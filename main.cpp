#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "fileworker.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    FileWorker worker;
    engine.rootContext()->setContextProperty("fileWorker", &worker);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    worker.loadDefault();

    QObject* btnSave = engine.rootObjects().at(0)->findChild<QObject*>("saveButton");
    QObject::connect(btnSave, SIGNAL(saveMessage(QString)),
                     &worker, SLOT(save(QString)));
    return app.exec();
}

