#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QProcess>
#include <QDebug>

const QString configPath = QDir::home().path()+"/.local/share/fcitx5/themes/Material-Color";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir qd(configPath);
    //加载目录下所有文件，可以添加过滤
    QFileInfoList subFileList = qd.entryInfoList(QDir::Files | QDir::CaseSensitive);//过滤条件为只限文件并区分大小写

    QVector<QString> vec;
    QStringList treeList;
    //遍历并输出指定类型的文件名
        for (int i = 0;i < subFileList.size(); i++)
        {
            QString suffix = subFileList[i].suffix();//获取后缀名
            if (suffix.compare("png") == 0)//如果后缀为"txt"
            {
                QString str = qPrintable(subFileList[i].baseName());
                QStringList list = str.split("-");
                if (list.size() == 2){
                    vec.push_back(list.at(1));
                    treeList.append(list.at(1));
                    QTreeWidgetItem *item =new QTreeWidgetItem(ui->treeWidget,treeList);
                    ui->treeWidget->addTopLevelItem(item);
                    treeList.clear();
                } else {
                    continue;
                }
            }
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_okBtn_clicked()
{
    if(ui->treeWidget->currentItem() == nullptr){
        return;
    }
    QMessageBox:: StandardButton result=  QMessageBox::information(NULL, "提示", "是否更换输入法皮肤？",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(result == QMessageBox:: StandardButton::No){
        return;
    }
    QProcess *p = new QProcess();
    p->setWorkingDirectory(configPath);
    QStringList arg;
    QString path = "theme-" + ui->treeWidget->currentItem()->text(0)+ ".conf";
    QString confPath = "theme.conf";
    arg<< "-sf" << path << confPath;
    p->start("ln",arg);
    p->waitForFinished();
    QMessageBox::information(NULL, "提示", "重启输入法后生效",
                             QMessageBox::Yes );
}

void MainWindow::on_cancelBtn_clicked()
{
    this->close();
}

void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    QString fileName =  current->text(0) + ".png";
    QString filePath = configPath+ "/screenshot/"+fileName;
    QPixmap myPix(filePath);
    ui->imageLab->setPixmap(myPix);
}
