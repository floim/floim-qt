QT       += webkitwidgets network widgets
HEADERS   = mainwindow.h bgbridge.h
SOURCES   = main.cpp mainwindow.cpp bgbridge.cpp
RESOURCES = images.qrc
ICON      = floim-osx.icns


# install
target.path = Floim
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro
sources.path = Floim
INSTALLS += target sources

OTHER_FILES +=

#CONFIG-=app_bundle
