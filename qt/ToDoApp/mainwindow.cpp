#include "mainwindow.h"
#include "ui_mainwindow.h"

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
