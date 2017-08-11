#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //! [style]
    QQuickStyle::setStyle(QStringLiteral("qrc:/qml/Style"));
    //! [style]

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/semc-sample.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
