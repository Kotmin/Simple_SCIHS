QT -= gui

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

INCLUDEPATH += C:\Users\Kuba\Documents\Simple_SCIHS-main\boost_1_81_0

SOURCES += \
        Student.cpp \
        main.cpp \
        studentcatalog.cpp \
        unique_index.cpp \
        validator.cpp

HEADERS += \
    Student.h \
    studentcatalog.h \
    unique_index.h \
    validator.h
