#include <QtGui/QApplication>
#include "kanjitoolswindow.h"
#include <QtCore/QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    KanjiToolsWindow k;
    //k.show();
   // k.hide();
    //k.setHidden(true);
    
    return a.exec();
}
