#include "choices.h"
#include "ui_choices.h"

//Opening and loading / saving files / parsing.
#include <QFileDialog>
#include <sstream>
#include <fstream>

choices::choices(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choices){
    ui->setupUi(this);
}

choices::~choices(){
    delete ui;
}

void choices::on_pushButton_clicked(){
    std::fstream infile;
    std::string filename = QFileDialog::getOpenFileName(this, tr("CSV file"), qApp->applicationDirPath (),tr("CSV File (*.csv)")).toStdString();
    if (filename.empty())
        return;

    infile.open(filename, std::fstream:: in | std::fstream::out | std::fstream::app);
    if (true) {

    }
    infile.close();
}
