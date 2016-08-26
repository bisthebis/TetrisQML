#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "tetrisdata.h"
#include "global.h"

#define TR QObject::tr

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    /*QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));//*/

    TetrisData data;
    data.log();

    return app.exec();
}
