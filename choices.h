#ifndef CHOICES_H
#define CHOICES_H

#include <QDialog>

namespace Ui {
class choices;
}

class choices : public QDialog
{
    Q_OBJECT

public:
    explicit choices(QWidget *parent = 0);
    ~choices();

private slots:
    void on_pushButton_clicked();

private:
    Ui::choices *ui;
};

#endif // CHOICES_H
