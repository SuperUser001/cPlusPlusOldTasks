#ifndef FIELD_H
#define FIELD_H
#include <QWidget>
#include <QGridLayout>
#include "dot.h"

class Dot;

// игровое поле
class Field : public QWidget {
  Q_OBJECT //для возможности использовать механизм сигналов-слотов
public:
  Field(QWidget *parent);
protected:
  void openAll();                     //нажать все клетки поля
  bool desiredCoordinate(int i, int j);    //проверяет является ли i,j координатами
  void pressDot(int i, int j);         //нажимает клетку и все клетки вокруг
  bool victory();                         // проверяет выигрыш
  const static int mn = 15,             // размер поля
                   mBombNumber = 15;  //количество бомб на поле
  Dot* mfield[mn][mn];                // игровое поле
  bool misGameActive;                   // состояние игрового поля
protected slots:
  void If_Press_Left();     // слот обработки нажатия  левой кнопкой мыши
  void If_Press_Right();    // слот обработки правой кнопкой мыши
signals:
  void finished();  //  завершения игры
};

#endif // FIELD_H
