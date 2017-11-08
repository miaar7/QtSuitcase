#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQuickControls2/QQuickStyle>
#include "backend.h"


int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    Backend backend;

    QQmlApplicationEngine* e = new QQmlApplicationEngine();
    e->rootContext()->setContextProperty("backend", &backend);

    QQuickStyle::setStyle("Material");


    e->load(QUrl(QLatin1String("qrc:/main.qml")));
    if (e->rootObjects().isEmpty())
        return -1;

    return app.exec();
}
