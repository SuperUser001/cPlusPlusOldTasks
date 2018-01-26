#include "dot.h"
#include <QPainter>
#include <QMouseEvent>

//конструктор
Dot::Dot(int i, int j, QWidget *parent) : QPushButton(parent), mi(i), mj(j), mvalue(0), mbomb(false)
  , mif_pressed_dot(false), misFlag(false) {
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  setFixedSize(30, 30);
}

//геттеры
int Dot::i() { return mi; }
int Dot::j() { return mj; }
int Dot::value() { return mvalue; }
void Dot::incBomb() { ++mvalue; }
bool Dot::bomb() { return mbomb; }
void Dot::setBomb() { mbomb = true; repaint(); }
bool Dot::if_pressed_dot() { return mif_pressed_dot; }
void Dot::setOpen() { mif_pressed_dot = true; repaint(); }
void Dot::swapFlag() { misFlag = !misFlag; repaint(); }

//прорисовка бомб и флажков
 void Dot::paintEvent(QPaintEvent *event) {
  if (if_pressed_dot() && bomb() == false && 0 == mvalue)
    return;
  QPushButton::paintEvent(event);
  QPainter p(this);
  if (if_pressed_dot()) {
    if (bomb()) {
      p.setBrush(QBrush(Qt::darkMagenta, Qt::Dense1Pattern));
      p.drawEllipse(1, 1, width() - 3, height() - 3);
      return;
    }
    setText(QString::number(mvalue));
    return;
  }
  if (misFlag) {
    p.setBrush(QBrush(Qt::darkYellow, Qt::Dense2Pattern));
    p.drawEllipse(1, 1, width() - 3, height() - 3);
  }
}

  void Dot::mouseReleaseEvent(QMouseEvent *e) { //определяем поведение при нажатии
  if (e->button() == Qt::LeftButton) emit press_left();
  if (e->button() == Qt::RightButton) emit press_right();
}
