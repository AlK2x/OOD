#include "newharmonicdialog.h"
#include "ui_newharmonicdialog.h"

NewHarmonicDialog::NewHarmonicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewHarmonicDialog)
{
    ui->setupUi(this);
}

NewHarmonicDialog::~NewHarmonicDialog()
{
    delete ui;
}
