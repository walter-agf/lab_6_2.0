#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    h_limit = 1050;
    v_limit = 850;
    dt = 100;

    timer = new QTimer(this);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-525,-425,h_limit,v_limit);
    scene->setBackgroundBrush(QPixmap(":/image/stars.jpg"));


    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));


    bars.append(new cuerpograf(0,-7000,2,0,70,120));
    bars.append(new cuerpograf(0,0,0,0,70000,300));
    bars.append(new cuerpograf(4000,5000,-1.6,1.2,25,100));

//    bars.append(new cuerpograf(0,0,0,0,50000,200));
//    bars.append(new cuerpograf(-5000,0,0,-2,70,70));
//    bars.append(new cuerpograf(5000,0,0,2,25,100));
//    bars.append(new cuerpograf(0,-5000,2,0,70,70));
//    bars.append(new cuerpograf(0,5000,-2,0,70,70));

    for (int i=0;i<bars.size() ;i++ ) {
        bars.at(i)->actualizar(dt);
        scene->addItem(bars.at(i));
    }


}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
}

void MainWindow::actualizar()
{
    for (int i=0;i<bars.size() ;i++ ) {
        for (int j = 0; j < bars.size() ; j++) {
            if(i!=j){
                bars.at(i)->getEsf()->acelerar(bars.at(j)->getEsf()->getPX(),bars.at(j)->getEsf()->getPY(),bars.at(j)->getEsf()->getMasa());
            }
        }
        bars.at(i)->actualizar(dt);
        datos += to_string(bars.at(i)->getEsf()->getPX());
        datos.push_back('\t');
        datos += to_string(bars.at(i)->getEsf()->getPY());
        datos.push_back('\t');
    }
    datos.push_back('\n');

}


void MainWindow::on_pushButton_clicked()
{
    timer->start(dt);
    qDebug() << entrada;
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
    bars.back()->guardar_datos(datos);
}

void MainWindow::on_pushButton_3_clicked()
{
    string prueba;
    bars.append(new cuerpograf(ui->x->value(),ui->y->value(),ui->vx->value(),ui->vy->value(),ui->masa->value(),ui->radio->value()));
    bars.back()->actualizar(dt);
    scene->addItem(bars.back());
}

void MainWindow::on_pushButton_4_clicked()
{
    for (int i=0;i<bars.size() ;i++ ) {
        scene->clear();
    }
    bars.clear();
}
