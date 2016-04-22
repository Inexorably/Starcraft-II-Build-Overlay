#include "mainwindow.h"
#include "ui_mainwindow.h"

//Main window includes.
#include "Windows.h"
#include <QDebug>
#include <QTimer>

//Loading includes.
#include "choices.h"
//#include "buildorder.h"
#include "globals.h"

//Opening and loading / saving files / parsing.
#include <QFileDialog>
#include <sstream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow){
  ui->setupUi(this);
  setWindowFlags(Qt::FramelessWindowHint| Qt::WindowStaysOnTopHint);
  setAttribute(Qt::WA_TranslucentBackground);
  target_window = FindWindowA("Starcraft II", 0);
  if (!target_window) {
    qDebug() << "window not found";
    return;
  }
  QTimer* timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(update_pos()));
  timer->start(50); // update interval in milliseconds

  //Make labels nontransparent.
  ui->buildText->setStyleSheet("background-color: rgba(112, 234, 242, 1);");

  //Change name.
  setWindowTitle("Build Overlay");

}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::openChoices(){
    choiceWindow = new choices(this);
    choiceWindow->show();
}



void MainWindow::update_pos(){
     RECT rect;
     if (GetWindowRect(target_window, &rect)) {
//       setGeometry(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
       SetWindowPos((HWND)this->winId(), HWND_TOPMOST, rect.left, rect.top, 0, 0, SWP_NOSIZE);
     } else {
       //maybe window was closed
       qDebug() << "GetWindowRect failed";
       QApplication::quit();
     }
}

void MainWindow::on_pushButton_clicked(){
    setWindowFlags(windowFlags() & ~Qt::WindowStaysOnTopHint);
    std::fstream infile;
    std::string filename = QFileDialog::getOpenFileName(this, tr("TXT file"), qApp->applicationDirPath (),tr("TXT File (*.txt)")).toStdString();
    if (filename.empty())
        return;

    infile.open(filename, std::fstream:: in | std::fstream::out | std::fstream::app);
    if (true) {

    }
    infile.close();
    //openChoices();
}

void MainWindow::on_forward_clicked(){
    globList.nextItem();
}
