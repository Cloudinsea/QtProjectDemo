#ifndef VIRTUAL_SCOPE_DEMO_H
#define VIRTUAL_SCOPE_DEMO_H

#include <QMainWindow>

namespace Ui {
class Virtual_scope_demo;
}

class Virtual_scope_demo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Virtual_scope_demo(QWidget *parent = 0);
    ~Virtual_scope_demo();

private:
    Ui::Virtual_scope_demo *ui;
};

#endif // VIRTUAL_SCOPE_DEMO_H
