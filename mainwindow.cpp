#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
     QString path = QFileDialog::getExistingDirectory(this, tr("Choose catalog"), ".", QFileDialog::ReadOnly);

     QDir directory(path);

     QStringList filters;
         filters << "*.avi";
         QStringList files = directory.entryList(filters);

         QStringList changedFiles, failedFiles;

         foreach(QString filename, files)
         {
             QFileInfo info(filename);
             QString rawFileName = filename.section(".", 0, 0);

             rawFileName.remove("_video");
             rawFileName.remove('_');
             rawFileName.remove(':');
             rawFileName.remove('-');
             rawFileName.remove(' ');

             QString newName = "/home/sit/vdata/" + rawFileName + ".avi";

             QString fPath = "/home/sit/vdata/" + filename.section(".", 0, 0) + ".avi";

             bool success = directory.rename(fPath, newName);

             if(success)
             {
                 changedFiles << info.absoluteFilePath();
             }
             else
             {
                 failedFiles << info.absoluteFilePath();
             }
         }



}
