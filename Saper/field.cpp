#include "field.h"
#include "dot.h"
#include <QGridLayout>
#include <QMessageBox>

bool Field::desiredCoordinate(int i, int j) {
  return i >= 0 && j >= 0 && i < mn && j < mn;
}

bool Field::victory() {
  int n = mn * mn - mBombNumber;
  for (int i = 0; i < mn; ++i)
    for (int j = 0; j < mn; ++j)
      n -= mfield[i][j]->if_pressed_dot();
  return 0 == n;
}

void Field::pressDot(int i, int j) {
  if (false == desiredCoordinate(i, j)) return;
  Dot *p = mfield[i][j];
  if (p->if_pressed_dot())
    return;
  p->setOpen();
  if (p->value()) return;
  pressDot(i - 1, j); pressDot(i + 1, j);
  pressDot(i, j - 1); pressDot(i, j + 1);
}

void Field::If_Press_Right() {
  if (false == misGameActive) return;
  Dot *t = reinterpret_cast<Dot*>(sender());
  if (t->if_pressed_dot()) return;
  t->swapFlag();
}

void Field::openAll() {
  for (int i = 0; i < mn; ++i)
    for (int j = 0; j < mn; ++j)
      mfield[i][j]->setOpen();
}

void Field::If_Press_Left() {
  if (false == misGameActive)  return;
  Dot *t = reinterpret_cast<Dot*>(sender());
  if (t->if_pressed_dot())  return;
  if (t->bomb()) {
    misGameActive = false;
    emit finished(); //подаем сигнал о завершении игры
    QMessageBox::information(0, " ", "Вы проиграли!");
    openAll();
    return;
  }
  pressDot(t->i(), t->j());
  if (victory()) {
    misGameActive = false;
    emit finished();
    QMessageBox::information(0, " ", "Вы победили!");
    openAll();
  }
}



Field::Field(QWidget *parent)
  : QWidget(parent) {
  misGameActive = true;
  QGridLayout *layout = new QGridLayout(this);
  for (int i = 0; i < mn; ++i) {
    for (int j = 0; j < mn; ++j) {
      mfield[i][j] = new Dot(i, j, this);
      layout->addWidget(mfield[i][j], i, j, 1, 1);
      connect(mfield[i][j], SIGNAL(press_left()), this, SLOT(If_Press_Left()));
      connect(mfield[i][j], SIGNAL(press_right()), this, SLOT(If_Press_Right()));
    }
  }

  for (int i = 0; i < mBombNumber;) {
    Dot *p = mfield[qrand() % mn][qrand() % mn];
    if (p->bomb())
      continue;
    else {
      p->setBomb();
      ++i;
    }
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
  }

  for (int i = 0; i < mn; ++i) {
    for (int j = 0; j < mn; ++j) {
      if (mfield[i][j]->bomb()) {
        if (desiredCoordinate(i - 1, j - 1)) mfield[i - 1][j - 1]->incBomb();
        if (desiredCoordinate(i - 1, j)) mfield[i - 1][j]->incBomb();
        if (desiredCoordinate(i - 1, j + 1)) mfield[i - 1][j + 1]->incBomb();
        if (desiredCoordinate(i, j - 1)) mfield[i][j - 1]->incBomb();
        if (desiredCoordinate(i, j + 1)) mfield[i][j + 1]->incBomb();
        if (desiredCoordinate(i + 1, j - 1)) mfield[i + 1][j - 1]->incBomb();
        if (desiredCoordinate(i + 1, j)) mfield[i + 1][j]->incBomb();
        if (desiredCoordinate(i + 1, j + 1)) mfield[i + 1][j + 1]->incBomb();
      }
    }
  }
}
