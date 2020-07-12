#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <fstream>
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json-c/json.h>

#include <QMainWindow>
#include <QFileDialog>

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
    void on_OpenButton_clicked();

    void on_FlashButton_clicked();

private:
    Ui::MainWindow *ui;
    void populateMCU();
    void populateBoards();
};

static size_t WriteCallback(void *, size_t, size_t, void *);

#endif // MAINWINDOW_H
