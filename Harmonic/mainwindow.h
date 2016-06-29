#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include <QDebug>
#include "newharmonicdialog.h"
#include "equationsolver.h"
#include <QStringListModel>
#include <QStringList>
#include <QStandardItemModel>
#include <QStandardItem>


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
    void AddHarmonicFunction(std::shared_ptr<CHarmonicEquation>);


private slots:
    void on_pushButton_2_clicked();
    void on_deleteFunction_clicked();
    void on_amplitude_editingFinished();
    void on_friquency_editingFinished();
    void on_phase_editingFinished();
    void on_sin_toggled(bool checked);
    void on_cos_toggled(bool checked);

    void OnFunctionListClick(const QModelIndex &);

private:
    void UpdateHarmonicFunction(const QModelIndex & index);

    void DrawFunction(const QModelIndex & index);

    Ui::MainWindow *ui;
    std::unique_ptr<NewHarmonicDialog> m_harmonicDialog;

    QVector<std::shared_ptr<CHarmonicEquation>> m_funcList;
    QStringListModel * m_funcModel;
    QStandardItemModel * m_tableModel;
    QStringList * m_funcStrList;
    CEquationSolver * m_solver;
};

#endif // MAINWINDOW_H
