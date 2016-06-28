#include "newharmonicdialog.h"
#include "ui_newharmonicdialog.h"
#include <QDebug>

NewHarmonicDialog::NewHarmonicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewHarmonicDialog)
{
    ui->setupUi(this);

    ui->amplitude->setValidator(new QDoubleValidator(-99.0, 99.0, 4, ui->amplitude));
    ui->friquency->setValidator(new QDoubleValidator(-99.0, 99.0, 4, ui->friquency));
    ui->phase->setValidator(new QDoubleValidator(-999.0, 999.0, 4, ui->phase));
}

void NewHarmonicDialog::accept()
{
    double amp = ui->amplitude->text().toDouble();
    double friquency = ui->friquency->text().toDouble();
    double phase = ui->phase->text().toDouble();
    HarmonicFunction func = (ui->sinFunc->isChecked()) ? HarmonicFunction::sin : HarmonicFunction::cos;

    std::shared_ptr<CHarmonicEquation> pEquation = std::make_shared<CHarmonicEquation>(func);
    pEquation->SetAmplitude(amp);
    pEquation->SetFriquence(friquency);
    pEquation->SetPhase(phase);

    emit AddNewHarmonic(pEquation);
}

NewHarmonicDialog::~NewHarmonicDialog()
{
    delete ui;
}
