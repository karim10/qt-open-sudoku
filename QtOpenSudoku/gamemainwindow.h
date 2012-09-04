#ifndef GAMEMAINWINDOW_H
#define GAMEMAINWINDOW_H

#include <cstdio>
#include <cstring>

#include <QMainWindow>
#include <QtGui>

namespace Ui {
class GameMainWindow;
}

class GameMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GameMainWindow(QWidget *parent = 0);
    ~GameMainWindow();
    
private slots:
    void on_actionE_xit_triggered();

private:
    Ui::GameMainWindow *ui;
};

#endif // GAMEMAINWINDOW_H
