#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

/*
 * Entry point to initialize the application.
 * NOTE: It is mostly based on the wearable QT Tutorial with additional
 * check on the engine loading.
 *
 * @author Alejandro B. Salazar
 */
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // Using QT sample code to override styles of some default controllers
    //! [style]
    QQuickStyle::setStyle(QStringLiteral("qrc:/qml/Style"));
    //! [style]

    // Initializing the Engine
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/semc-sample.qml")));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
