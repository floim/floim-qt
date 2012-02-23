#include "bgbridge.h"
#include "mainwindow.h"

BGBridge::BGBridge(MainWindow *parent_) {
    mainWindow = parent_;
    _unread = -1;
}
int BGBridge::unread() {
    return _unread;
}
void BGBridge::setUnread(int unread) {
    _unread = unread > 0 ? unread : 0;
    mainWindow->setUnreadCount(_unread);
}
void BGBridge::alert(QString icon,QString title,QString msg) {
    mainWindow->showMessage(icon,title,msg);
}
void BGBridge::open(QString url) {
    mainWindow->openUrl(url);
}
