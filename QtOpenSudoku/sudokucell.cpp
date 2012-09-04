#include "sudokucell.h"
#include <QPalette>

SudokuCell::SudokuCell(QWidget *parent) :
    QLabel(parent)
{

    selectedBgColor = Qt::lightGray;
    notSelectedBgColor = Qt::white;

    notSelectedColor = Qt::blue;
    selectedColor = Qt::red;

    setAutoFillBackground(true);

    setText("TEST");
    isSelected = false;


    setFixedWidth(50);
    setFixedHeight(50);
    qDebug() << this->backgroundRole();

    setNotSelectedColor();

    setFrameStyle(QFrame::Box);
    setLineWidth(3);
}

void SudokuCell::mousePressEvent(QMouseEvent *ev){
    isSelected = true;
    setSelectedColor();

    grabMouse();
    grabKeyboard();
}

void SudokuCell::keyPressEvent(QKeyEvent *ev){
    qDebug() << "key pressed = " << ev->key() << endl;
    if (! isSelected)
        return;
    if(ev->key() >= Qt::Key_0 && ev->key() <= Qt::Key_9){
        char s[5];
        sprintf(s,"%d",(ev->key() - Qt::Key_0));
        setText(s);
    }
    else if (ev->key() == Qt::Key_Backspace || ev->key() == Qt::Key_Delete){
        setText(" ");
    }
    else if (ev->key() == Qt::Key_Enter){
        isSelected = 0;
        releaseKeyboard();
        releaseMouse();
        setNotSelectedColor();
    }
}

void SudokuCell::setNotSelectedColor()
{
    QPalette _pal;
    _pal.setColor(QPalette::WindowText,notSelectedColor);
    _pal.setColor(QPalette::Window,notSelectedBgColor);
    this->setPalette(_pal);
}

void SudokuCell::setSelectedColor()
{
    QPalette _pal;
    _pal.setColor(QPalette::WindowText,selectedColor);
    _pal.setColor(QPalette::Window,selectedBgColor);
    this->setPalette(_pal);
}
