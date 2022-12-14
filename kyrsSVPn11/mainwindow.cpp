#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nrow =28;
    model = new QStandardItemModel(nrow,2,this);
    ui->tableView->setModel( model);
    model->setHeaderData(0, Qt::Horizontal, "Позиция зуба");
     model->setHeaderData(1, Qt::Horizontal, "Дата прорезывания");

     for (int i = 0; i < nrow; i++)
     {
         index = model->index(i,0);
         model->setData(index, i+1);
     }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_clicked()
{

    model->insertRow(model->rowCount());
  //  nrow++;
}


void MainWindow::on_pushButton_delete_clicked()
{
     model->removeRow(row); // УДАЛЕНИЕ ТАБЛИЦЫ
     //nrow--;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();

}


void MainWindow::on_pushButton_sort_clicked()
{
    int n = 0, nz=0; // кол-во заполненных и не заполненных строк
    for (int i = 0; i < model->rowCount(); i++)
    {
        index = model->index(i,1); // в переменную индекс 2 стобца
        if (index.data().toInt() == 0){ // проверяет написано ли что-то в строку второго столбца
            nz++;
            index = model->index(i,0);
            idtooth_without_date.push_back(index.data().toString()); // в вектор данные строки первого столбца
        }
        else{
            n++;
            datetooth.push_back(index.data().toString()); // в вектор то что записано в строке второго столбца
            index = model->index(i,0);
            idtooth_with_date.push_back(index.data().toString()); // в вектор данные строки первого столбца
        }
    }
    for (int i = 0; i < n; i++) // циклы с перезаписыванием данных в таблицу
    {
        index = model->index(i,0);
        model->setData(index, idtooth_with_date[i]);
    }
    for (int i = 0; i < n; i++)
    {
        index = model->index(i,1);
        model->setData(index, datetooth[i]);
    }
    for (int i = n; i < n+nz; i++)
    {
        index = model->index(i,0);
        model->setData(index, idtooth_without_date[i-n]);
    }
    for (int i = n; i < n+nz; i++)
    {
        index = model->index(i,1);
        model->setData(index, "");
    }
    idtooth_with_date.clear(); // очискта векторов
    datetooth.clear();
    idtooth_without_date.clear();
}

