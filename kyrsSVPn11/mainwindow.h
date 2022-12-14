#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <qstring.h>
#include <QModelIndex>
#include <QPushButton>
//#include <QEvent>
//#include <QAbstractNativeEventFilter>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_sort_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QModelIndex index;
    int row;
    int nrow;

    std::vector<QString> datetooth;
    std::vector<QString> idtooth_with_date;
    std::vector<QString> idtooth_without_date;

};

#endif // MAINWINDOW_H
