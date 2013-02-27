#include <QtGui>
#include <QMainWindow>
#include <QtWebKit>
#include <QSystemTrayIcon>
#include "bgbridge.h"

class QWebView;
class QLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QUrl& url, QApplication& _app);

public slots:
    void increaseDatabaseQuota(QWebFrame* frame,QString);
    void javaScriptWindowObjectCleared();
    void setUnreadCount(int count);
    void showMessage(QString icon,QString title,QString msg);
    void openUrl(QString url);
    QIcon iconWithUnread(QString unread, double scale);

protected slots:
    void adjustLocation(QUrl url);
    void linkClicked(QUrl url);
    void adjustLocation();
    void adjustTitle();
    void setProgress(int p);
    void finishLoading(bool);
    void iconActivated(QSystemTrayIcon::ActivationReason);
    void createTrayIcon();
    void closeEvent(QCloseEvent *event);

private:
    QApplication *app;
    QSystemTrayIcon *trayIcon;
    QWebView *webView;
    BGBridge *bridge;

    int progress;
};
