#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qstandardpaths.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnRemove_clicked();

    void on_btnRemoveAll_clicked();

    void storeTasksToFile();
    void restoreTasksFromFile();

private:
    Ui::MainWindow *ui;

    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\todoFile.txt";
};
#endif // MAINWINDOW_H
