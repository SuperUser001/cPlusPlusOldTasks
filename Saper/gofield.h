#ifndef FIELDWRAPPER_H
# define FIELDWRAPPER_H
# include <QWidget>
# include <QLabel>
#include <QGridLayout>
#include "field.h"


class QGridLayout;
class Field;

class GoField :public QWidget {
  Q_OBJECT
protected:
  Field *mfield;     // игровое поле агрегирование
  QGridLayout *mlayout; // раскладка виджета
public:
   GoField() : mfield(nullptr), mlayout(nullptr){ //конструктор
    mlayout = new QGridLayout;
     setLayout(mlayout); //функция QWidget::setLayout() привязывает компоновку к виджету.
      game_restart();
    }
public slots:
    void game_restart() {
      if (mfield) delete mfield;
      mfield = new Field(this);
      mlayout->addWidget(mfield, 1, 0, 1, 1);
   //   mlayout->setSpacing(0);
    }

};

#endif // FIELDWRAPPER_H
