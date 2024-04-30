#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    restoreTasksFromFile();
}

MainWindow::~MainWindow()
{
    storeTasksToFile();
    delete ui;
}

void MainWindow::storeTasksToFile() {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "Error", file.errorString());
    }

    QTextStream out(&file);
    for( int i=0; i< ui->listWidgetTasks->count(); i++ ) {
        out<<ui->listWidgetTasks->item(i)->text()<<"\n";
    }

    file.close();
}

void MainWindow::restoreTasksFromFile() {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "Error", file.errorString());
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString text = in.readLine();
        QListWidgetItem* item = new QListWidgetItem(text, ui->listWidgetTasks);
        item->setFlags(item->flags() | Qt::ItemIsEditable);
        ui->listWidgetTasks->addItem(item);
    }

    file.close();
}

void MainWindow::on_btnAdd_clicked()
{
    QString taskItem = ui->editTaskItem->text();
    QListWidgetItem* listItem = new QListWidgetItem(taskItem, ui->listWidgetTasks);
    listItem->setFlags(listItem->flags() | Qt::ItemIsEditable);
    ui->listWidgetTasks->addItem(listItem);
    ui->editTaskItem->clear();
    ui->editTaskItem->setFocus();
}


void MainWindow::on_btnRemove_clicked()
{
    QListWidgetItem* listItem = ui->listWidgetTasks->currentItem();
    delete listItem;
}


void MainWindow::on_btnRemoveAll_clicked()
{
    ui->listWidgetTasks->clear();
}
