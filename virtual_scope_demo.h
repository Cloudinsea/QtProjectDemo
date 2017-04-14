#ifndef VIRTUAL_SCOPE_DEMO_H
#define VIRTUAL_SCOPE_DEMO_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class Virtual_scope_demo;
}

class Virtual_scope_demo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Virtual_scope_demo(QWidget *parent = 0);
    ~Virtual_scope_demo();

    QSerialPort serial;//串口实例
    void initSeialPort();//初始化串口函数

    // TaoTao's Function...

private slots:
    void serialRead();
    void on_Com_comboBox_currentIndexChanged(const QString &arg1);

    void on_SerialPortScan_pushButton_clicked();

private:
    Ui::Virtual_scope_demo *ui; 
};

#endif // VIRTUAL_SCOPE_DEMO_H
