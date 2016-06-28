#ifndef NEWHARMONICDIALOG_H
#define NEWHARMONICDIALOG_H

#include <QDialog>

namespace Ui {
class NewHarmonicDialog;
}

class NewHarmonicDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewHarmonicDialog(QWidget *parent = 0);
    ~NewHarmonicDialog();

private:
    Ui::NewHarmonicDialog *ui;
};

#endif // NEWHARMONICDIALOG_H
