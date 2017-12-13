#include <QGuiApplication>
#include <QtWidgets/QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QtQuickControls2/QQuickStyle>

#include "backend.h"


int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);

    Backend backend;

    // Tmp100Timer timer;

    QQmlApplicationEngine* e = new QQmlApplicationEngine();
    e->rootContext()->setContextProperty("backend", &backend);

    QQuickStyle::setStyle("Material");


    e->load(QUrl(QLatin1String("qrc:/main.qml")));
    if (e->rootObjects().isEmpty())
        return -1;

    //get first rootobject in the list and cast to quickwindow
    QObject * topLevel = e->rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow*>(topLevel);
    QObject::connect(&backend, SIGNAL(currentTemperature(QVariant)), window, SLOT(temperatureChange(QVariant)));




    return app.exec();
}
