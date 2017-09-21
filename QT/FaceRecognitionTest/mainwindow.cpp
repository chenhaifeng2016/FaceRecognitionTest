#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

#include "QFile"
#include "QDataStream"

#include "IDCardReader.h"
#include "WltRS.h"

#include "FaceRecognition.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    camera = new QCamera(this);
    viewFinder = new QCameraViewfinder(this);
    imageCapture = new QCameraImageCapture(camera);

    ui->cameraView->addWidget(viewFinder);
    ui->imageCapture->setScaledContents(true);

    camera->setViewfinder(viewFinder);
    camera->start();

    connect(ui->btnCapture, SIGNAL(clicked()), this, SLOT(OnCaptureImage()));
    connect(imageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(OnDisplayImage(int, QImage)));

    connect(ui->btnSave, SIGNAL(clicked()), this, SLOT(OnSaveImage()));

    connect(ui->btnReadID, SIGNAL(clicked()), this, SLOT(OnReadIDCard()));

    connect(ui->btnFaceRecognition, SIGNAL(clicked()), this, SLOT(OnFaceRecognition()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnCaptureImage(){
    imageCapture->capture();
}

void MainWindow::OnDisplayImage(int, QImage image){
    ui->imageCapture->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::OnSaveImage(){
    const QPixmap* pixmap = ui->imageCapture->pixmap();
    if(pixmap) {
        pixmap->save("E:\\FaceRecognition\\FaceRecognitionTest\\test_images\\camera.jpg");


        QMessageBox::information(this, QString("ÌáÊ¾¿ò").toLocal8Bit(), tr("save successfully"));
    }

}

void MainWindow::OnReadIDCard(){
    IDCARD id;

    if (!ReadIDCard("com3", &id)) {
          QMessageBox::information(this, "read idcard error", "information");
            return;
    }

    // save file
    QFile file("E:\\FaceRecognition\\FaceRecognitionTest\\test_images\\id.wlt");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QDataStream out(&file);

    //out.writeBytes(id.image, 1024);
    out.writeRawData(id.image, 1024);

    file.close();

    // wlt => bmp
    char wltfile[] = "E:/FaceRecognition/FaceRecognitionTest/test_images/id.wlt";
    int rc = GetBmp(wltfile, 0);
    if (rc != 1) {
            return;
        }

    // show img
    QImage* img = new QImage;
    img->load("E:\\FaceRecognition\\FaceRecognitionTest\\test_images\\id.bmp");

    ui->imageIDPhoto->setPixmap(QPixmap::fromImage(*img));

    delete img;

}

void MainWindow::OnFaceRecognition(){
    int confidence  = 0;
    int ret = FaceRecognition("E:\\FaceRecognition\\FaceRecognitionTest\\test_images\\id.bmp", "E:\\FaceRecognition\\FaceRecognitionTest\\test_images\\camera.jpg", &confidence);

    QString sConfidence = QString::number(confidence, 10);
    ui->lblConfidence->setText(sConfidence);
}
