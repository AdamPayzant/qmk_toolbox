#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <typeinfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LoadButton->setEnabled(false);
    populateMCU();
    // Populate boards is currently incomplete
    // populateBoards();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OpenButton_clicked()
{
    std::cout << "Open Clicked" << std::endl;
    QString f = QFileDialog::getOpenFileName(this, 
        tr("Select firmware to load"), "/home", tr("HEX Files (*.hex)"));
    ui->FilePath->setText(f);
}

void MainWindow::on_FlashButton_clicked()
{
    std::cout << "Flash Clicked" << std::endl;
}

void MainWindow::populateMCU() {
    std::ifstream file("../common/mcu-list.txt");
    std::string line;

    while(getline(file, line)) {
        if(line.length() > 0) {
            ui->MCU_List->addItem(QString::fromStdString(line));
        }
    }
}

void MainWindow::populateBoards() {
    CURL *curl;
    CURLcode res;
    std::string readbuffer;
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://api.qmk.fm/v1/keyboards");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readbuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        //std::cout << readbuffer << std::endl;
        // TODO: Parse JSON
        
    }

    curl_global_cleanup();
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}