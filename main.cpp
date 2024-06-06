#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>
#include <QDebug>

#include "listcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/MVC_deneme/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    ListController listController;
    engine.rootContext()->setContextProperty("ListController", &listController);

    engine.load(url);

    // Test
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, [&listController] {
        static int counter{ 0 };
        listController.addData(QString("Data %1").arg(++counter));
        qDebug() << "Data added: " << counter;
    });
    timer.start(1000);

    return app.exec();
}
