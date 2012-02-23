#include <QtGui>
#include <QtWebKit>
#include <QSslConfiguration>
#include <QSslSocket>
#include "mainwindow.h"

MainWindow::MainWindow(const QUrl& url, QApplication& _app) {
    progress = 0;
    app = &_app;

    createTrayIcon();
    trayIcon->show();

    setUnreadCount(-1);

    QSettings settings;


    QNetworkProxyFactory::setUseSystemConfiguration(true);
    QWebSettings::enablePersistentStorage();
    QWebSettings* s = QWebSettings::globalSettings();
    // https://developer.qt.nokia.com/doc/qt-4.8/qwebsettings.html#WebAttribute-enum
    s->setAttribute(QWebSettings::LocalStorageEnabled,true);
    s->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
    s->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
    s->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled,true);
    s->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
    //s->setAttribute(QWebSettings::TiledBackingStoreEnabled, true);
    s->setAttribute(QWebSettings::SiteSpecificQuirksEnabled, false);

    qDebug("%s",qVersion());
    webView = new QWebView(this);
    bridge = new BGBridge(this);

    webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

    //webView->setContextMenuPolicy(Qt::NoContextMenu);
    webView->load(url);

    connect(webView, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));
    connect(webView, SIGNAL(urlChanged(QUrl)), this, SLOT(adjustLocation(QUrl)));
    connect(webView, SIGNAL(titleChanged(QString)), SLOT(adjustTitle()));
    connect(webView, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
    connect(webView, SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));
    connect(webView->page(), SIGNAL(databaseQuotaExceeded(QWebFrame*,QString)),this,SLOT(increaseDatabaseQuota(QWebFrame*,QString)));
    connect(webView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(javaScriptWindowObjectCleared()));
    connect(webView->page()->mainFrame(), SIGNAL(urlChanged(QUrl)), this, SLOT(adjustLocation(QUrl)));
    connect(webView, SIGNAL(linkClicked(QUrl)), this, SLOT(linkClicked(QUrl)));

    setCentralWidget(webView);
    setUnifiedTitleAndToolBarOnMac(true);
    javaScriptWindowObjectCleared();

    QPoint pos = settings.value("pos", QPoint(100, 100)).toPoint();
    QSize size = settings.value("size", QSize(800, 600)).toSize();
    resize(size);
    move(pos);
}

void MainWindow::createTrayIcon() {
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/pim.svg"));
    trayIcon->setToolTip("Pim");
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason) {
    raise();
}

void MainWindow::adjustLocation(QUrl url) {
    QWebFrame *frame = webView->page()->mainFrame();
    QString href = frame->evaluateJavaScript("window.location.href").toString();
    qDebug() << href;
}

void MainWindow::linkClicked(QUrl url) {
    QDesktopServices::openUrl(url);
}

void MainWindow::adjustLocation() {
    QUrl url = webView->url();
    adjustLocation(url);
}

void MainWindow::adjustTitle() {
    adjustLocation();
    if (progress <= 0 || progress >= 100) {
        setWindowTitle(webView->title());
    } else {
        setWindowTitle(QString("%1 (%2%)").arg(webView->title()).arg(progress));
    }
}

void MainWindow::setProgress(int p) {
    progress = p;
    adjustTitle();
}

void MainWindow::finishLoading(bool) {
    progress = 100;
    adjustTitle();
}

void MainWindow::increaseDatabaseQuota(QWebFrame* frame,QString) {
    QWebSecurityOrigin origin = frame->securityOrigin();
    origin.setDatabaseQuota(100 * 1024 * 1024);
}

void MainWindow::setUnreadCount(int count) {
    QString unread="";
    if (count < 0) {
        unread = QString("?");
    } else if (count > 0) {
        unread = QString("%1").arg(count);
    }
    QImage base(QString(":/pim.svg"));
    if (count != 0) {
        QPainter painter(&base);
        painter.setPen(Qt::white);
        painter.setBrush(QBrush(Qt::red));

        int r = 2*base.rect().width()/3;
        QRect unreadBox(base.rect().width()-r,0,r,r);
        painter.drawEllipse(unreadBox);
        painter.setFont(QFont("Arial", r*0.7));
        painter.drawText(unreadBox, Qt::AlignCenter, unread);
    }
    QIcon icon = QIcon(QPixmap::fromImage(base));
    setWindowIcon(icon);
    app->setWindowIcon(icon);
    trayIcon->setIcon(icon);
}
void MainWindow::showMessage(QString icon,QString title,QString msg) {
    trayIcon->showMessage(title,msg);
    Q_UNUSED(icon);
}

void MainWindow::openUrl(QString url) {
    qDebug() << url;
    if (url.startsWith("/")) {
        url = webView->page()->mainFrame()->evaluateJavaScript("window.location.protocol+'//'+window.location.host").toString()+url;
    }
    if (url.startsWith("http://") || url.startsWith("https://")) {
        QDesktopServices::openUrl(QUrl(url));
    }
}

void MainWindow::javaScriptWindowObjectCleared() {
    QWebFrame *frame = webView->page()->mainFrame();
    frame->addToJavaScriptWindowObject("QTApp", bridge);
    frame->evaluateJavaScript("window.open = QTApp.open;");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    QWidget::closeEvent(event);
}
