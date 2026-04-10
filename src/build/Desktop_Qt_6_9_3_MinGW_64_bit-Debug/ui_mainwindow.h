/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *musicNameLabel;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QListView *musicListView;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QLabel *backgroundImgLabel;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *beginLabel;
    QSlider *timeHorizontalSlider;
    QLabel *finishLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *previousPushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *stopPushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *nextPushButton;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *openFilePushButton;
    QPushButton *soundPushButton;
    QSlider *soundHorizontalSlider;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *listPushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(324, 472);
        MainWindow->setMaximumSize(QSize(324, 472));
        MainWindow->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/src/music.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setAnimated(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMaximumSize(QSize(16777215, 16777215));
        centralwidget->setAcceptDrops(true);
        centralwidget->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        musicNameLabel = new QLabel(centralwidget);
        musicNameLabel->setObjectName("musicNameLabel");
        QFont font;
        font.setPointSize(14);
        musicNameLabel->setFont(font);
        musicNameLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(musicNameLabel);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        page = new QWidget();
        page->setObjectName("page");
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName("gridLayout");
        musicListView = new QListView(page);
        musicListView->setObjectName("musicListView");
        musicListView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        musicListView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        gridLayout->addWidget(musicListView, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setObjectName("gridLayout_2");
        backgroundImgLabel = new QLabel(page_2);
        backgroundImgLabel->setObjectName("backgroundImgLabel");
        backgroundImgLabel->setMaximumSize(QSize(300, 300));
        backgroundImgLabel->setPixmap(QPixmap(QString::fromUtf8(":/src/changpian.png")));
        backgroundImgLabel->setScaledContents(true);
        backgroundImgLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(backgroundImgLabel, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        beginLabel = new QLabel(widget_2);
        beginLabel->setObjectName("beginLabel");
        beginLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(beginLabel);

        timeHorizontalSlider = new QSlider(widget_2);
        timeHorizontalSlider->setObjectName("timeHorizontalSlider");
        timeHorizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(timeHorizontalSlider);

        finishLabel = new QLabel(widget_2);
        finishLabel->setObjectName("finishLabel");
        finishLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(finishLabel);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 50));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        previousPushButton = new QPushButton(widget);
        previousPushButton->setObjectName("previousPushButton");
        previousPushButton->setMinimumSize(QSize(40, 40));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::MediaSeekBackward));
        previousPushButton->setIcon(icon1);

        horizontalLayout->addWidget(previousPushButton);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stopPushButton = new QPushButton(widget);
        stopPushButton->setObjectName("stopPushButton");
        stopPushButton->setMinimumSize(QSize(40, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/src/start.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        stopPushButton->setIcon(icon2);

        horizontalLayout->addWidget(stopPushButton);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        nextPushButton = new QPushButton(widget);
        nextPushButton->setObjectName("nextPushButton");
        nextPushButton->setMinimumSize(QSize(40, 40));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::MediaSeekForward));
        nextPushButton->setIcon(icon3);

        horizontalLayout->addWidget(nextPushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(0, 40));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        openFilePushButton = new QPushButton(widget_3);
        openFilePushButton->setObjectName("openFilePushButton");
        openFilePushButton->setMinimumSize(QSize(30, 30));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        openFilePushButton->setIcon(icon4);

        horizontalLayout_3->addWidget(openFilePushButton);

        soundPushButton = new QPushButton(widget_3);
        soundPushButton->setObjectName("soundPushButton");
        soundPushButton->setMinimumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/src/vol.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        soundPushButton->setIcon(icon5);
        soundPushButton->setIconSize(QSize(14, 14));

        horizontalLayout_3->addWidget(soundPushButton);

        soundHorizontalSlider = new QSlider(widget_3);
        soundHorizontalSlider->setObjectName("soundHorizontalSlider");
        soundHorizontalSlider->setMinimumSize(QSize(0, 35));
        soundHorizontalSlider->setSizeIncrement(QSize(0, 0));
        soundHorizontalSlider->setValue(30);
        soundHorizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        soundHorizontalSlider->setTickInterval(0);

        horizontalLayout_3->addWidget(soundHorizontalSlider);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        listPushButton = new QPushButton(widget_3);
        listPushButton->setObjectName("listPushButton");
        listPushButton->setMinimumSize(QSize(30, 30));
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::FormatJustifyLeft));
        listPushButton->setIcon(icon6);

        horizontalLayout_3->addWidget(listPushButton);


        verticalLayout->addWidget(widget_3);

        MainWindow->setCentralWidget(centralwidget);
#if QT_CONFIG(shortcut)
        beginLabel->setBuddy(timeHorizontalSlider);
        finishLabel->setBuddy(timeHorizontalSlider);
#endif // QT_CONFIG(shortcut)

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", nullptr));
        musicNameLabel->setText(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220\346\222\255\346\224\276\345\231\250", nullptr));
        backgroundImgLabel->setText(QString());
        beginLabel->setText(QCoreApplication::translate("MainWindow", "0:00", nullptr));
        finishLabel->setText(QCoreApplication::translate("MainWindow", "0:00", nullptr));
#if QT_CONFIG(tooltip)
        previousPushButton->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        previousPushButton->setText(QString());
#if QT_CONFIG(tooltip)
        stopPushButton->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
#endif // QT_CONFIG(tooltip)
        stopPushButton->setText(QString());
#if QT_CONFIG(tooltip)
        nextPushButton->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\246\226", nullptr));
#endif // QT_CONFIG(tooltip)
        nextPushButton->setText(QString());
#if QT_CONFIG(tooltip)
        openFilePushButton->setToolTip(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\351\237\263\344\271\220", nullptr));
#endif // QT_CONFIG(tooltip)
        openFilePushButton->setText(QString());
#if QT_CONFIG(tooltip)
        soundPushButton->setToolTip(QCoreApplication::translate("MainWindow", "\351\235\231\351\237\263", nullptr));
#endif // QT_CONFIG(tooltip)
        soundPushButton->setText(QString());
#if QT_CONFIG(tooltip)
        listPushButton->setToolTip(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220\345\210\227\350\241\250", nullptr));
#endif // QT_CONFIG(tooltip)
        listPushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
