#include "virtual_scope_demo.h"
#include "ui_virtual_scope_demo.h"
#include <QDebug>
#include <QTextCodec>

Virtual_scope_demo::Virtual_scope_demo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Virtual_scope_demo)
{
    ui->setupUi(this);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    connect(&serial,SIGNAL(readyRead()),this,SLOT(serialRead()));   //连接槽
    initSeialPort();
}

Virtual_scope_demo::~Virtual_scope_demo()
{
    serial.close();
    delete ui;
}

void Virtual_scope_demo::initSeialPort()
{
    //获取计算机上所有串口并添加到comboBox中
    QList<QSerialPortInfo>  infos = QSerialPortInfo::availablePorts();
    //ui->Com_comboBox->addItem( QStringLiteral("串口选择") );
    if(infos.isEmpty())
    {
        //ui->Com_comboBox->addItem( QStringLiteral("no com") );
        qDebug() << "no serialport" << endl;
        return;
    }
    foreach (QSerialPortInfo info, infos) {
        ui->Com_comboBox->addItem(info.portName());
        qDebug() << info.portName();
        //UsartAssistant::ComInfo = info;
    }
    //UsartAssistant::on_Com_comboBox_currentIndexChanged( UsartAssistant::ComInfo.portName() );
}

void Virtual_scope_demo::serialRead()
{
//    ui->SerialRead_textEdit->append( serial.readAll() );
    QByteArray qa = serial.readAll();
    //  if(qa.at(0)=='a')
    //ui->SerialRead_textEdit->append(qa);  //这种方法接受数据有问题，会出现换行符

    ui->SerialRead_textEdit->insertPlainText(QString(qa));
}

void Virtual_scope_demo::on_Com_comboBox_currentIndexChanged(const QString &arg1)
{
    //qDebug() << "Com_combobox enter" << endl;
    QSerialPortInfo info;
    QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
    int i = 0;
    foreach (info, infos) {
        if(info.portName() == arg1) break;
        i++;
    }
    if(i != infos.size ()){//can find
        //        ui->lblStatus->setText("串口打开成功");
        qDebug() << "open success";
        serial.close();
        serial.setPort(info);
        serial.open(QIODevice::ReadWrite);          //读写打开
        serial.setBaudRate(QSerialPort::Baud115200);  //波特率
        serial.setDataBits(QSerialPort::Data8);     //数据位
        serial.setParity(QSerialPort::NoParity);    //无奇偶校验
        serial.setStopBits(QSerialPort::OneStop);   //无停止位
        serial.setFlowControl(QSerialPort::NoFlowControl);  //无控制
        serial.setReadBufferSize( 1024 );
    }else{
        serial.close();
        qDebug() << "open fail" << endl;
    }
}

void Virtual_scope_demo::on_SerialPortScan_pushButton_clicked()
{
    ui->Com_comboBox->clear();
    Virtual_scope_demo::initSeialPort();
}
