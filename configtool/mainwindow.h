#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTreeWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_okBtn_clicked();
    void on_cancelBtn_clicked();
    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
