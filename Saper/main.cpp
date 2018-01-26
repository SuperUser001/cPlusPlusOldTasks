#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include "gofield.h"


int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  QMainWindow Window; // окно программы
  GoField field;            // игровое поле
  QMenuBar *top_level_menu;        // меню верхнего уровня (Новая игры)
  Window.setCentralWidget(&field); //void QMainWindow::setCentralWidget ( QWidget * widget )
//  Устанавливает заданный виджет (widget), в качестве центрального виджета главного окна.
  top_level_menu = Window.menuBar();

  QAction *openAct = new QAction(QObject::tr("&Новая игра"), &Window);
  QObject::connect(openAct, SIGNAL(triggered()), &field, SLOT(game_restart()));
  //добавление в соответствующее меню и подсоединение к слоту, который будет выполнять действие

  top_level_menu->addAction(openAct);
  Window.show();

  return a.exec();
}
