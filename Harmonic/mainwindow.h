#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QDebug>
#include "newharmonicdialog.h"
#include "harmonicfunctionlistmodel.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void testFunc(std::shared_ptr<CHarmonicEquation>);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    std::unique_ptr<NewHarmonicDialog> m_harmonicDialog;
    NewHarmonicDialog * m_thd;

    //QVector<std::shared_ptr<CHarmonicEquation>> m_funcList;
    CHarmonicFunctionListModel * m_funcModel;
};

#endif // MAINWINDOW_H
