#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <choices.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    HWND target_window;

public slots:
    void openChoices();

private slots:
  void update_pos();

  void on_pushButton_clicked();

  void on_forward_clicked();

private:
    Ui::MainWindow *ui;
    choices *choiceWindow;
};

#endif // MAINWINDOW_H
