#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void OnCaptureImage();
    void OnDisplayImage(int, QImage);
    void OnSaveImage();
    void OnReadIDCard();
    void OnFaceRecognition();

private:
    Ui::MainWindow *ui;

    QCamera* camera;
    QCameraViewfinder * viewFinder;
    QCameraImageCapture * imageCapture;
};

#endif // MAINWINDOW_H
