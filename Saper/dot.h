#ifndef DOT_H
# define DOT_H
# include <QPushButton>

//клетка поля
class Dot : public QPushButton {
  Q_OBJECT
public:
  Dot(int i, int j, QWidget *parent);
  int i();  // индекс строки клетки
  int j();  //индекс столбца клетки
  bool bomb();   //есть ли в клетке бомба
  void setBomb();  //ставим бомбу
  void incBomb(); //счетчик бомб ++
  int value();     //счетчик бомб вернуть
  void setOpen();   //открываем клетку
  bool if_pressed_dot();    //открыта ли клетка
  void swapFlag();    //флажок
signals:
  void press_left();
  void press_right();
protected:
   void paintEvent(QPaintEvent *event);
   void mouseReleaseEvent(QMouseEvent *e);

  int mi, mj; //координаты клетки
  int mvalue;  // значение хранимое в клетке
  bool mbomb;    //vявляется ли бомбой
  bool mif_pressed_dot;     //открыта ли
  bool misFlag;  // помечена ли флагом
};

#endif // DOT_H
