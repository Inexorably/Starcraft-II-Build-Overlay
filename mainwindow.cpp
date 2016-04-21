#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Windows.h"
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
  setAttribute(Qt::WA_TranslucentBackground);
  target_window = FindWindowA("Notepad", 0);
  if (!target_window) {
    qDebug() << "window not found";
    return;
  }
  QTimer* timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update_pos()));
  timer->start(50); // update interval in milliseconds
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::update_pos() {
  RECT rect;
  if (GetWindowRect(target_window, &rect)) {
    setGeometry(rect.left, rect.top, rect.right - rect.left,
                rect.bottom - rect.top);
  } else {
    //maybe window was closed
    qDebug() << "GetWindowRect failed";
    QApplication::quit();
  }
  emit true;
}
