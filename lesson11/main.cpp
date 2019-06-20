#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "gameboard.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //GameBoard gameBoard;

    qmlRegisterType<GameBoard>("GameBoard_uri", 1, 0, "GameBoard_qml");


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                        if (!obj && url == objUrl)
                            QCoreApplication::exit(-1);
                    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
