#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initializeDashboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeDashboard()
{
    setWindowTitle("VoltGuard Dashboard");

    statusBar()->showMessage("System Initialized");

    updateSystemStatus("Waiting for Simulation...");
}

void MainWindow::updateSystemStatus(const QString &status)
{
    statusBar()->showMessage(status);
}