TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    square_matrix.h \
    graph_arrow.h \
    bigraph.h

SOURCES += main.cpp \
    square_matrix.cpp \
    bigraph.cpp
