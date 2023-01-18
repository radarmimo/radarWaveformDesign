#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
//#include <uhd/utils/thread_priority.hpp>
//#include <uhd/utils/safe_main.hpp>
//#include <uhd/usrp/multi_usrp.hpp>
//#include <uhd/exception.hpp>
//#include <uhd/types/tune_request.hpp>
//#include <boost/program_options.hpp>
//#include <boost/format.hpp>
//#include <boost/thread.hpp>
//#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_FindDevices_clicked()
{



    std::string device_args("");

    uhd::device_addrs_t device_addrs = uhd::device::find(device_args);

    ui->textBrowser_USRPinfo->setText(device_addrs.data()->to_pp_string().c_str());



    std::string subdev("A:A");
    std::string ant("TX/RX");
    std::string ref("internal");

    double rate(50e6);
    double freq(ui->lineEdit_FreqGHzCH0->text().toDouble() * 1e9);
    double gain(ui->lineEdit_GaindBCH0->text().toDouble());
    double bw(ui->lineEdit_BandwidthMHzCH0->text().toDouble()*1e6);

    std::cout << boost::format("Frequency [Hz]: %s") % std::to_string(freq) << std::endl;
    std::cout << boost::format("Sample Rate [Hz]: %s") % std::to_string(rate) << std::endl;
    std::cout << boost::format("Bandwidth [Hz]: %s") % std::to_string(bw) << std::endl;
    std::cout << boost::format("Gain [dB]: %s") %std::to_string(gain) << std::endl;



    //create a usrp device
    //    uhd::set_thread_priority_safe();
    std::cout << std::endl;
    std::cout << boost::format("Creating the usrp device with: %s...") % device_args << std::endl;
    //    uhd::usrp::multi_usrp::sptr usrp = uhd::usrp::multi_usrp::make(device_args);
    usrp = uhd::usrp::multi_usrp::make(device_args);

    //    std::cout << boost::format("Using Device: %s") % usrp->get_pp_string() << std::endl;


    //    ui->textBrowser_USRPinfo->append(usrp->get_pp_string().c_str());

    ui->textBrowser_USRPinfo->append("~~~~~~~~~~~~~~~~~~~~~~~~");
    usrp->set_rx_rate(rate);
    ui->textBrowser_USRPinfo->append(  "Sampling Rate: " + QString::number(usrp->get_rx_rate(0)/1e6,'f', 3) + " [MHz]");

    ui->textBrowser_USRPinfo->append("~~~~~~~~~~~~~~~~~~~~~~~~");
    ui->textBrowser_USRPinfo->append("~~~~~~~~~~~~~~~~~~~~~~~~");
    ui->textBrowser_USRPinfo->append("Channel A ");
    ui->textBrowser_USRPinfo->append("........................");
    usrp->set_rx_freq(freq);
    ui->textBrowser_USRPinfo->append(  "    Center Frequency: " + QString::number(usrp->get_rx_freq(0)/1e9,'f', 3) + " [GHz]");

    usrp->set_rx_bandwidth(bw);
    ui->textBrowser_USRPinfo->append(  "    Bandwidth: " + QString::number(usrp->get_rx_bandwidth(0)/1e6,'f', 3) + " [MHz]");

    usrp->set_rx_gain(gain);
    ui->textBrowser_USRPinfo->append(  "    Gain: " + QString::number(usrp->get_rx_gain(0),'f', 3) + " [dB]");

    // set the antenna
    if (ui->comboBox_AntennaCH0->currentIndex() == 0) {
        std::string ant("TX/RX");
    }
    else{
        std::string ant("RX2");
    }


    std::cout << boost::format("Antenna: %s") % ant << std::endl;
    usrp->set_rx_antenna(ant);

    ui->textBrowser_USRPinfo->append(  "    Antenna: " + QString::fromStdString(usrp->get_rx_antenna())) ;



    ui->textBrowser_USRPinfo->append("~~~~~~~~~~~~~~~~~~~~~~~~");

    ui->pushButton_Connect->setEnabled(true);


    ui->customPlot1->addGraph();
    ui->customPlot1->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
//    ui->customPlot1->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    ui->customPlot1->addGraph();
    ui->customPlot1->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    ui->customPlot1->xAxis->setRange(0,1024);
    ui->customPlot1->yAxis->setRange(-0.1,0.1);
    ui->customPlot1->xAxis2->setVisible(true);
    ui->customPlot1->xAxis2->setTickLabels(false);
    ui->customPlot1->yAxis2->setVisible(true);
    ui->customPlot1->yAxis2->setTickLabels(false);
    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(ui->customPlot1->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot1->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot1->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot1->yAxis2, SLOT(setRange(QCPRange)));
    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    ui->customPlot1->graph(0)->rescaleAxes();
    ui->customPlot1->graph(1)->rescaleAxes(true);
    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    ui->customPlot1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    //    ui->customPlot1->replot();
    //    _______________________________________

}


void MainWindow::on_pushButton_Plot_clicked()
{
    //    // add two new graphs and set their look:
    //    ui->customPlot1->addGraph();
    //    ui->customPlot1->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    //    ui->customPlot1->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
    //    ui->customPlot1->addGraph();
    //    ui->customPlot1->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    //    // generate some points of data (y0 for first, y1 for second graph):
    //    QVector<double> x(251), y0(251), y1(251);
    //    for (int i=0; i<251; ++i)
    //    {
    //      x[i] = i;
    //      y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
    //      y1[i] = qExp(-i/150.0);              // exponential envelope
    //    }
    //    // configure right and top axis to show ticks but no labels:
    //    // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
    //    ui->customPlot1->xAxis2->setVisible(true);
    //    ui->customPlot1->xAxis2->setTickLabels(false);
    //    ui->customPlot1->yAxis2->setVisible(true);
    //    ui->customPlot1->yAxis2->setTickLabels(false);
    //    // make left and bottom axes always transfer their ranges to right and top axes:
    //    connect(ui->customPlot1->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot1->xAxis2, SLOT(setRange(QCPRange)));
    //    connect(ui->customPlot1->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot1->yAxis2, SLOT(setRange(QCPRange)));
    //    // pass data points to graphs:
    //    ui->customPlot1->graph(0)->setData(x, y0);
    //    ui->customPlot1->graph(1)->setData(x, y1);
    //    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    //    ui->customPlot1->graph(0)->rescaleAxes();
    //    // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
    //    ui->customPlot1->graph(1)->rescaleAxes(true);
    //    // Note: we could have also just called customPlot->rescaleAxes(); instead
    //    // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
    //    ui->customPlot1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    //    ui->customPlot1->replot();
}


void MainWindow::on_pushButton_AddData_clicked()
{
    ui->customPlot1->graph(0)->addData(((double) rand() / (RAND_MAX))*250, ((double) rand() / (RAND_MAX)) );
    ui->customPlot1->replot();
}


void MainWindow::on_pushButton_Connect_clicked()
{
    // start Rx
//    ui->pushButton_Connect->setEnabled(false);
    ui->textBrowser_USRPinfo->append("Connected to the device!");
    ui->textBrowser_USRPinfo->append("Receiving data");

    usrp->set_time_now(uhd::time_spec_t(0.0));

    std::string wire;

    std::vector<size_t> channel_nums(0);

    // create a receive streamer
    uhd::stream_args_t stream_args("fc32"); // complex double
    stream_args.channels             = channel_nums;
    stream_args.args["spp"] = "200"; //  samples per packet (buffer size, which saves samples if we could not receive on-time)
    uhd::rx_streamer::sptr rx_stream = usrp->get_rx_stream(stream_args);

    // setup streaming
    double seconds_in_future(1.5);
    int nSamples(1024);
    size_t total_num_samps(200*nSamples);

    std::cout << std::endl;
    std::cout << boost::format("Begin streaming %u samples, %f seconds in the future...")
                 % total_num_samps % seconds_in_future
              << std::endl;
    uhd::stream_cmd_t stream_cmd(uhd::stream_cmd_t::STREAM_MODE_START_CONTINUOUS);
    stream_cmd.num_samps  = total_num_samps;
    stream_cmd.stream_now = false;
    stream_cmd.time_spec  = uhd::time_spec_t(seconds_in_future);
    rx_stream->issue_stream_cmd(stream_cmd);


    std::cout << rx_stream->get_max_num_samps() << std::endl;

    // meta-data will be filled in by recv()
    uhd::rx_metadata_t md;

    // allocate buffer to receive with samples
    std::vector<std::complex<float>> buff(rx_stream->get_max_num_samps());
    std::vector<void*> buffs;
    for (size_t ch = 0; ch < rx_stream->get_num_channels(); ch++)
        buffs.push_back(&buff.front()); // same buffer for each channel

    // the first call to recv() will block this many seconds before receiving
    double timeout = seconds_in_future + 0.1; // timeout (delay before receive + padding)

    size_t num_acc_samps = 0; // number of accumulated samples

    //        po::variables_map vm;
    //        bool verbose = vm.count("dilv") == 0;


//    while (true) {
        QVector<double> dataI, dataQ;
        dataI.reserve(total_num_samps);
        dataQ.reserve(total_num_samps);
        while (num_acc_samps < total_num_samps) {
            // receive a single packet
            size_t num_rx_samps = rx_stream->recv(&buff.front(), buff.size(), md, timeout, true);

            // use a small timeout for subsequent packets
            timeout = 0.1;

            dataI.push_back(buff.front().real());
            dataQ.push_back(buff.front().imag());


            // handle the error code
            //                if (md.error_code == uhd::rx_metadata_t::ERROR_CODE_TIMEOUT)
            //                    break;
            //                if (md.error_code != uhd::rx_metadata_t::ERROR_CODE_NONE) {
            //                    throw std::runtime_error(
            //                        str(boost::format("Receiver error %s") % md.strerror()));
            //                }

            //            ui->customPlot1->graph(0)->setData(buff.data());

            num_acc_samps += num_rx_samps;

        }
        emit MainWindow::process_data(dataI, dataQ);
//    }




    if (num_acc_samps < total_num_samps)
        std::cerr << "Receive timeout before all samples received..." << std::endl;

    // finished
    std::cout << std::endl << "Done!" << std::endl << std::endl;
}

void MainWindow::start_rx(uhd::usrp::multi_usrp::sptr &usrp)
{

}

void MainWindow::process_data(QVector<double> &dataI, QVector<double> &dataQ)
{
    //    QVector IandQ;
    //    QVector<double> vector = QVector<double>::fromVector(buffs);

    //    std::vector<T> QVector::toStdVector () const;
    //    QVector<T> QVector::fromStdVector ( const std::vector<T> & vector ) [static];
//    std::cout << buff.data()->real() << std::endl;
//    std::cout << buff.data()->imag() << std::endl;
//    std::cout << buff.size() << std::endl;
//    std::cout << dataI[0] << dataI[1]*1000 << dataI[2] << dataI[3]  << std::endl;
//    std::cout << dataQ[0] << dataQ[1]*1000 << dataQ[2] << dataQ[3]  << std::endl;
    QVector<double> xAxis(dataI.size());
    for (int i = 0; i < dataI.size(); ++i) {
        xAxis[i] = i;
    }
    ui->customPlot1->graph(0)->setData(xAxis,dataI);
    ui->customPlot1->graph(1)->setData(xAxis, dataQ);
    ui->customPlot1->replot();
}

