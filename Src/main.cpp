#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>

#include <QThread>
#include "LcmDataParse.hpp"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    LcmDataParse lcmDataParse;
    QQuickView viewer;
    viewer.setResizeMode(QQuickView::SizeViewToRootObject);
    viewer.rootContext()->setContextProperty("LcmDataParse", &lcmDataParse);

    viewer.setSource(QUrl("qrc:/main.qml"));
    viewer.show();

    return app.exec();
}
