QT       += core gui sql widgets

TARGET = Claims
TEMPLATE = app

INCLUDEPATH +=	../MyORM \
../DateListEdit

SOURCES +=\
        MainWindow.cpp \
    Invoice.cpp \
    Deposit.cpp \
    Claim.cpp \
    ClaimResult.cpp \
    Attachment.cpp \
    Provider.cpp \
    Attachable.cpp \
    InvoiceDAO.cpp \
    ProviderDAO.cpp \
    Main.cpp \
    AttachmentDAO.cpp \
    AttachableDAO.cpp \
    ClaimDAO.cpp \
    ../MyORM/DAO.cpp \
    ../MyORM/LibraryDAO.cpp \
    ../MyORM/Persistable.cpp \
    ../MyORM/Relationship.cpp \
    ../MyORM/LibraryBase.cpp \
    Library.cpp \
    ClaimResultDAO.cpp \
    DepositDAO.cpp \
    AllClaimsWidget.cpp \
    ClaimElement.cpp \
    ClaimItem.cpp \
    ClaimItemDlg.cpp \
    ../MyORM/PropertyPrinter.cpp \
    ../MyORM/PropertyLoader.cpp \
    DateRangeEdit.cpp \
    ../DateListEdit/DateListLineEdit.cpp \
    GraphicsScene.cpp

HEADERS  += MainWindow.h \
    Invoice.h \
    Deposit.h \
    Claim.h \
    ClaimResult.h \
    Attachment.h \
    Provider.h \
    Attachable.h \
    InvoiceDAO.h \
    ProviderDAO.h \
    AttachmentDAO.h \
    AttachableDAO.h \
    ClaimDAO.h \
    ../MyORM/DAO.h \
    ../MyORM/LibraryDAO.h \
    ../MyORM/Persistable.h \
    ../MyORM/Relationship.h \
    ../MyORM/LibraryBase.h \
    Library.h \
    ClaimResultDAO.h \
    DepositDAO.h \
    AllClaimsWidget.h \
    ClaimElement.h \
    ClaimItem.h \
    ClaimItemDlg.h \
    ../MyORM/Constants.h \
    ../MyORM/PropertyPrinter.h \
    ../MyORM/PropertyLoader.h \
    DateRangeEdit.h \
    ../DateListEdit/DateListLineEdit.h \
    GraphicsScene.h

FORMS    += MainWindow.ui

RESOURCES += \
    Resources.qrc
