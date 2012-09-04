/* Written by dev.1one.w01f */

#include "gamemainwindow.h"
#include "ui_gamemainwindow.h"
#include <QLayout>

#include <QGroupBox>
#include <sudokucell.h>

GameMainWindow::GameMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameMainWindow)
{
    ui->setupUi(this);
    QGridLayout *_cellLayout = new QGridLayout();
    _cellLayout->setAlignment(Qt::AlignRight);
    //SudokuCell *_aCell = new SudokuCell();
    for (int i = 0; i < 9; i++){
       // _cellLayout.setColumnStretch(i,40);
        for (int j = 0; j < 9; j++){
           // _cellLayout.setRowStretch(j,40);
            char s[10];
            sprintf(s,"hihi%d",i);

            _cellLayout->addWidget(new SudokuCell(),i,j);
        }
    }
//    _cellLayout->addStretch(1);
//    QGroupBox PuzzleBox;
    ui->PuzzleFrame->setLayout(_cellLayout);

}
GameMainWindow::~GameMainWindow()
{
    delete ui;
}

void GameMainWindow::on_actionE_xit_triggered()
{
    // TODO: check for unsaved game and warn before quit
    qApp->exit(0);
}
