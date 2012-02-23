QT       += webkit network
HEADERS   = mainwindow.h bgbridge.h
SOURCES   = main.cpp mainwindow.cpp bgbridge.cpp
RESOURCES = images.qrc
ICON      = pim-osx.icns
QT += svg


# install
target.path = Pim
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro
sources.path = Pim
INSTALLS += target sources

OTHER_FILES +=

#CONFIG-=app_bundle
