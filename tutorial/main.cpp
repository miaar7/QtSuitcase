#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
//#include "backend.h"
#include "invoke_class.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");


    invoke_class ic;

    //make ic available to engine
    QQmlApplicationEngine* engine = new QQmlApplicationEngine();
    engine->rootContext()->setContextProperty("ic", &ic);

    engine->load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine->rootObjects().isEmpty())
        return -1;

    //get first rootobject in the list and cast to quickwindow
    QObject * topLevel = engine->rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow*>(topLevel);




    QObject::connect(&ic, SIGNAL(setTextField(QVariant)), window, SLOT(setTextField(QVariant)));


    //engine->rootObjects().value(0)->dumpObjectTree();
    //engine->rootObjects().value(0)->dumpObjectInfo();

    qDebug() << "everything initialized";
    return app.exec();
}
