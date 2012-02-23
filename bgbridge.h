#ifndef BGBRIDGE_H
#define BGBRIDGE_H

#include <QObject>

class MainWindow;

class BGBridge : public QObject
{
    Q_OBJECT
public:
    BGBridge(MainWindow *parent = 0);
    Q_PROPERTY(int unread READ unread WRITE setUnread);

    Q_INVOKABLE void alert(QString icon,QString title,QString msg);
    Q_INVOKABLE void open(QString url);

signals:

public slots:

private:
    MainWindow *mainWindow;
    int _unread;

    int unread();
    void setUnread(int unread);
};

#endif // BGBRIDGE_H
