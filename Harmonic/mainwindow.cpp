#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // ui->amplitude->setValidator(new QDoubleValidator(-99.0, 99.0, 4, ui->amplitude));
   // ui->friquency->setValidator(new QDoubleValidator(-99.0, 99.0, 4, ui->friquency));
   // ui->phase->setValidator(new QDoubleValidator(-99.0, 99.0, 4, ui->phase));

    m_harmonicDialog = std::make_unique<NewHarmonicDialog>(this);
    m_solver = new CEquationSolver();

    m_funcStrList = new QStringList();
    m_funcModel = new QStringListModel(*m_funcStrList, NULL);
    ui->functionList->setModel(m_funcModel);


    connect(&(*m_harmonicDialog),
            SIGNAL(AddNewHarmonic(std::shared_ptr<CHarmonicEquation>)),
            this,
            SLOT(AddHarmonicFunction(std::shared_ptr<CHarmonicEquation>))
            );

    connect(ui->functionList,
            SIGNAL(clicked(QModelIndex)),
            this,
            SLOT(OnFunctionListClick(QModelIndex))
            );

    m_tableModel = new QStandardItemModel;

    QStringList horizontalHeader;
    horizontalHeader.append("x");
    horizontalHeader.append("y");
    m_tableModel->setHorizontalHeaderLabels(horizontalHeader);

    ui->tableView->setModel(m_tableModel);
    ui->tableView->setColumnWidth(0, (ui->tableView->width() / 3));
    ui->tableView->setColumnWidth(1, ui->tableView->width() / 3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    m_harmonicDialog->show();
}

void MainWindow::AddHarmonicFunction(std::shared_ptr<CHarmonicEquation> pFunc)
{
    m_funcList.push_back(pFunc);

    m_funcModel->insertRows(m_funcModel->rowCount(), 1);
    QModelIndex index = m_funcModel->index(m_funcModel->rowCount()-1);
    m_funcModel->setData(index, pFunc->ToString());
}

void MainWindow::on_deleteFunction_clicked()
{
    int index = ui->functionList->currentIndex().row();

    if (index >= 0)
    {
        m_funcModel->removeRows(index, 1);
        m_funcList.remove(index);
        int i = ui->widget->clearGraphs();
        qDebug() << "Deleted plots: " << i;
    }
}

void MainWindow::on_amplitude_editingFinished()
{
    QModelIndex index = ui->functionList->currentIndex();
    UpdateHarmonicFunction(index);
}

void MainWindow::on_friquency_editingFinished()
{
    QModelIndex index = ui->functionList->currentIndex();
    UpdateHarmonicFunction(index);
}

void MainWindow::on_phase_editingFinished()
{
    QModelIndex index = ui->functionList->currentIndex();
    UpdateHarmonicFunction(index);
}

void MainWindow::on_sin_toggled(bool checked)
{
    if (checked)
    {
        QModelIndex index = ui->functionList->currentIndex();
        UpdateHarmonicFunction(index);
    }
}

void MainWindow::on_cos_toggled(bool checked)
{
    if (checked)
    {
        QModelIndex index = ui->functionList->currentIndex();
        UpdateHarmonicFunction(index);
    }
}

void MainWindow::OnFunctionListClick(const QModelIndex & index)
{
    int row = index.row();
    auto func = m_funcList.at(row);
    ui->amplitude->setText(QString::number(func->GetAmplitude()));
    ui->friquency->setText(QString::number(func->GetFriquency()));
    ui->phase->setText(QString::number(func->GetPhase()));

    if (func->GetFunction() == HarmonicFunction::sin)
    {
        ui->sin->setChecked(true);
        ui->cos->setChecked(false);
    }
    else
    {
        ui->sin->setChecked(false);
        ui->cos->setChecked(true);
    }
    DrawFunction(index);
}

void MainWindow::UpdateHarmonicFunction(const QModelIndex & index)
{
    if (!index.isValid())
    {
        return;
    }

    int row = index.row();
    if (row < 0)
    {
        return;
    }

    auto func = m_funcList.at(row);
    func->SetAmplitude(ui->amplitude->text().toDouble());
    func->SetFriquence(ui->friquency->text().toDouble());
    func->SetPhase(ui->phase->text().toDouble());

    HarmonicFunction function = (ui->sin->isChecked()) ? HarmonicFunction::sin : HarmonicFunction::cos;
    func->SetFunction(function);
    m_funcModel->setData(index, func->ToString());
    DrawFunction(index);
}

void MainWindow::DrawFunction(const QModelIndex &index)
{
    if (!index.isValid())
    {
        return;
    }

    int row = index.row();
    if (row < 0)
    {
        return;
    }

    auto func = m_funcList.at(row);
    m_solver->Solve(func);
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(m_solver->GetXPoints(), m_solver->GetYPoints());
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(m_solver->GetMinX(), m_solver->GetMaxX());
    ui->widget->yAxis->setRange(m_solver->GetMinY(), m_solver->GetMaxY());
    ui->widget->replot();

    auto x = m_solver->GetXPoints();
    auto y = m_solver->GetYPoints();

    QStandardItem *item;
    for (int i = 0; i < x.size(); ++i)
    {
        item = new QStandardItem(QString::number(x[i]));
        m_tableModel->setItem(i, 0, item);

        item = new QStandardItem(QString::number(y[i]));
        m_tableModel->setItem(i, 1, item);
    }
}


