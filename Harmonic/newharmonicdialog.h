#ifndef NEWHARMONICDIALOG_H
#define NEWHARMONICDIALOG_H

#include <QDialog>
#include "charmonicequation.h"

namespace Ui {
class NewHarmonicDialog;
}

class NewHarmonicDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewHarmonicDialog(QWidget *parent = 0);
    ~NewHarmonicDialog();

public slots:
    void accept();

signals:
    void AddNewHarmonic(std::shared_ptr<CHarmonicEquation> pHarmonic);


private:
    Ui::NewHarmonicDialog *ui;
};

#endif // NEWHARMONICDIALOG_H
