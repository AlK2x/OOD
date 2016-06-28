#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_harmonicDialog = std::make_unique<NewHarmonicDialog>(this);

    m_funcModel = new CHarmonicFunctionListModel(this);
    ui->functionList->setModel(m_funcModel);

    connect(&(*m_harmonicDialog),
            SIGNAL(AddNewHarmonic(std::shared_ptr<CHarmonicEquation>)),
            this,
            SLOT(testFunc(std::shared_ptr<CHarmonicEquation>))
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    double a = -1; //Начало интервала, где рисуем график по оси Ox
    double b =  1; //Конец интервала, где рисуем график по оси Ox
    double h = 0.01; //Шаг, с которым будем пробегать по оси Ox

    int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x(N), y(N); //Массивы координат точек

    //Вычисляем наши данные
    int i=0;
    for (double X=a; X<=b; X+=h)//Пробегаем по всем точкам
    {
        x[i] = X;
        y[i] = X*X;//Формула нашей функции
        i++;
    }

    ui->widget->clearGraphs();
    ui->widget->addGraph();

    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");

    ui->widget->xAxis->setRange(a, b);


    //Для показа границ по оси Oy сложнее, так как надо по правильному
    //вычислить минимальное и максимальное значение в векторах
    double minY = y[0], maxY = y[0];
    for (int i=1; i<N; i++)
    {
        if (y[i]<minY) minY = y[i];
        if (y[i]>maxY) maxY = y[i];
    }
    //ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

    //И перерисуем график на нашем widget
    ui->widget->replot();
}

void MainWindow::on_pushButton_2_clicked()
{
    m_harmonicDialog->show();
}

void MainWindow::testFunc(std::shared_ptr<CHarmonicEquation> pFunc)
{
    int row = m_funcModel->rowCount(QModelIndex());
    m_funcModel->insertRows(row, 1, QModelIndex());
    QModelIndex index = m_funcModel->index(row);

    m_funcModel->setData(index, QVariant(pFunc.get()), Qt::EditRole);

    ui->functionList->setCurrentIndex(index);


    qDebug() << "Get func: " << pFunc->ToString();
}
