#include <QApplication>
#include "kanjitoolswindow.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    KanjiToolsWindow k;
    k.show();
    
    return a.exec();
}
