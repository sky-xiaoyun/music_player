#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDirIterator>
#include <QDebug>
#include <QStandardItemModel>
#include <QList>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFile>
#include <QApplication>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void keyPressEvent(QKeyEvent *event) override;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void playCurrent();

    QString toQString(qint64 num);

    void openQss();

public slots:
    // 槽函数实现
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void onSliderMoved(qint64 position);
private slots:
    void on_openFilePushButton_clicked();

    void on_musicListView_doubleClicked(const QModelIndex &index);

    void on_soundHorizontalSlider_actionTriggered();

    void on_soundPushButton_clicked();

    void on_listPushButton_clicked();

    void on_stopPushButton_clicked();

    void on_nextPushButton_clicked();

    void on_previousPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* m_item;
    QList<QUrl> m_playlist;         //音乐列表
    int m_currentIndex = -1;        //音乐列表的索引
    QMediaPlayer *m_player;         //控制音乐类
    QAudioOutput *m_audioOutput;    //播放音乐类
};
#endif // MAINWINDOW_H
