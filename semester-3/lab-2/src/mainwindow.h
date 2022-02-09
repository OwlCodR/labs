#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QKeyEvent>
#include <QMainWindow>

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
    void on_pushButton_X_clicked();
    void on_pushButton_O_clicked();

    void on_pushButton_W_clicked();
    void on_pushButton_A_clicked();
    void on_pushButton_S_clicked();
    void on_pushButton_D_clicked();

    void on_pushButton_Restart_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent* e);
    void removeAllFrom(QGridLayout* layout);
    Game game;
};
#endif // MAINWINDOW_H
