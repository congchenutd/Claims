#-------------------------------------------------
#
# Project created by QtCreator 2016-09-16T16:06:11
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Claims
TEMPLATE = app


SOURCES +=\
        MainWindow.cpp \
    Invoice.cpp \
    Deposit.cpp \
    Claim.cpp \
    ClaimResult.cpp \
    Attachment.cpp \
    Provider.cpp \
    Attachable.cpp \
    Persistable.cpp \
    DAO.cpp \
    InvoiceDAO.cpp \
    ProviderDAO.cpp \
    Library.cpp \
    LibraryDAO.cpp \
    Main.cpp \
    AttachmentDAO.cpp \
    AttachableDAO.cpp \
    Relationship.cpp

HEADERS  += MainWindow.h \
    Invoice.h \
    Deposit.h \
    Claim.h \
    ClaimResult.h \
    Attachment.h \
    Provider.h \
    Attachable.h \
    Persistable.h \
    DAO.h \
    InvoiceDAO.h \
    ProviderDAO.h \
    Library.h \
    LibraryDAO.h \
    AttachmentDAO.h \
    AttachableDAO.h \
    Relationship.h

FORMS    += MainWindow.ui
