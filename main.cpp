#include <QtGui>
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char * argv[]) {
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("FloimQT");
    QCoreApplication::setApplicationVersion("1.0.0");
    QCoreApplication::setOrganizationName("Floim");
    QCoreApplication::setOrganizationDomain("floim.com");
    QUrl url;
    if (argc > 1)
        url = QUrl(argv[1]);
    else
#if defined QT_NO_DEBUG
        url = QUrl("https://floim.com/");
#else
        url = QUrl("http://localhost:3000/");
#endif
    MainWindow *browser = new MainWindow(url,app);
    #if defined Q_OS_SYMBIAN || defined Q_WS_HILDON || defined Q_WS_MAEMO_5 || defined Q_WS_SIMULATOR
        browser->showMaximized();
    #else
        browser->show();
    #endif
    return app.exec();
}
