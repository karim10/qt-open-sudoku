#ifndef SUDOKUCELL_H
#define SUDOKUCELL_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QDebug>
#include <QKeyEvent>
#include <cstdio>
#include <cstring>
#include <QColor>

class SudokuCell : public QLabel
{
    Q_OBJECT
public:
    explicit SudokuCell(QWidget *parent = 0);

signals:
    
public slots:

protected:
    void mousePressEvent(QMouseEvent *ev);
    void keyPressEvent(QKeyEvent *ev);
    
private:
    void setNotSelectedColor();
    void setSelectedColor();
    bool isSelected;
    QColor selectedColor, notSelectedColor;
    QColor selectedBgColor, notSelectedBgColor;
private slots:
};

#endif // SUDOKUCELL_H
