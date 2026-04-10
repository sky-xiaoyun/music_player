#include "mainwindow.h"
#include "ui_mainwindow.h"

//qputenv("QT_MEDIA_BACKEND", "windows");

#include <QTimer>

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        // 模拟点击“播放/暂停”按钮
        on_stopPushButton_clicked();
    } else {
        // 其他按键交给默认处理
        QMainWindow::keyPressEvent(event);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_item(new QStandardItemModel(this))
    ,m_audioOutput(new QAudioOutput(this))
    ,m_player(new QMediaPlayer(this))
{
    ui->setupUi(this);

    openQss();

    ui->stackedWidget->setCurrentIndex(1);

    ui->musicListView->setModel(m_item);

    m_player->setAudioOutput(m_audioOutput);

    setFocusPolicy(Qt::StrongFocus);    //以防界面有其他抢空格暂停

    // 连接信号槽 (通常在构造函数中)
    connect(m_player, &QMediaPlayer::durationChanged, this, &MainWindow::onDurationChanged);
    connect(m_player, &QMediaPlayer::positionChanged, this, &MainWindow::onPositionChanged);
    connect(ui->timeHorizontalSlider, &QSlider::sliderMoved, this, &MainWindow::onSliderMoved);
    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia && !m_playlist.isEmpty()) {
            on_nextPushButton_clicked();
        }
    });
}

// 槽函数实现
void MainWindow::onDurationChanged(qint64 duration) {
    ui->finishLabel->setText(toQString(duration));
    ui->timeHorizontalSlider->setRange(0, duration);
}

void MainWindow::onPositionChanged(qint64 position) {
    // 避免在拖动进度条时更新，造成冲突
    if (!ui->timeHorizontalSlider->isSliderDown()) {
        ui->timeHorizontalSlider->setValue(position);
        ui->beginLabel->setText(toQString(position));
    }
}

void MainWindow::onSliderMoved(qint64 position) {
    m_player->setPosition(position);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playCurrent()
{
    if(m_currentIndex == -1)
    {
        qDebug()<<"m_currentIndex为-1";
        return;
    }
    m_player->setSource(m_playlist[m_currentIndex]);
    m_player->play();
    ui->stopPushButton->setIcon(QIcon(":/coin/pause.png"));
}

QString MainWindow::toQString(qint64 num)
{
    int seconds = num / 1000;
    int minutes = seconds / 60;
    seconds %= 60;
    QString temp = QString::number(minutes)+":"+QString::number(seconds);
    return temp;
}

void MainWindow::on_openFilePushButton_clicked()
{
    auto path = QFileDialog::getExistingDirectory(this, "选择文件", "\\music_player\\src\\coin");
    if(path.isEmpty())   return;

    QDirIterator it(path,{"*.mp3","*.wav","*.ogg"});
    int i = 1;
    while(it.hasNext())
    {
        auto info = it.nextFileInfo();
        m_playlist.append(QUrl::fromLocalFile(info.filePath()));
        auto item = new QStandardItem(QString::number(i++)+ "." + info.fileName());
        m_item->appendRow(item);
    }
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_musicListView_doubleClicked(const QModelIndex &index)
{
    m_currentIndex = index.row();
    playCurrent();
    ui->musicNameLabel->setText(index.data().toString());
    ui->stackedWidget->setCurrentIndex(1);
    ui->musicListView->setCurrentIndex(index);
}


void MainWindow::on_soundHorizontalSlider_actionTriggered()
{
    if((ui->soundHorizontalSlider->value() / 100.0) == 0.00 || (ui->soundHorizontalSlider->value() / 100.0) == 0.01)
    {
        //qDebug()<<ui->soundHorizontalSlider->value() / 100.0;
        m_audioOutput->setVolume(0);
        ui->soundPushButton->setIcon(QIcon(":/coin/unvol.png"));
        ui->soundPushButton->setToolTip("关闭静音");
    }
    else
    {
        m_audioOutput->setVolume(ui->soundHorizontalSlider->value() / 100.0);
        ui->soundPushButton->setIcon(QIcon(":/coin/vol.png"));
        ui->soundPushButton->setToolTip("静音");
    }

}


void MainWindow::on_soundPushButton_clicked()
{
    if((ui->soundHorizontalSlider->value() / 100.0) != 0.00)
    {
        ui->soundHorizontalSlider->setValue(0);
        m_audioOutput->setVolume(0);
        ui->soundPushButton->setIcon(QIcon(":/coin/unvol.png"));
        ui->soundPushButton->setToolTip("关闭静音");
    }
    else
    {
        ui->soundHorizontalSlider->setValue(50);
        m_audioOutput->setVolume(ui->soundHorizontalSlider->value() / 100.0);
        ui->soundPushButton->setIcon(QIcon(":/coin/vol.png"));
        ui->soundPushButton->setToolTip("静音");
    }
}


void MainWindow::on_listPushButton_clicked()
{
    if(ui->stackedWidget->currentIndex() == 1)
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->musicNameLabel->setText("音乐播放器");
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(1);
        QStandardItem *item = m_item->item(m_currentIndex);
        if (item) {
            ui->musicNameLabel->setText(item->text());
        }
    }
}


void MainWindow::on_stopPushButton_clicked()
{
    if(m_playlist.isEmpty()) return;
    switch(m_player->playbackState())
    {
    case QMediaPlayer::PlayingState:
        m_player->pause();
        ui->stopPushButton->setIcon(QIcon(":/coin/start.png"));
        ui->stopPushButton->setToolTip("播放");
        break;
    default:
        m_player->play();
        ui->stopPushButton->setIcon(QIcon(":/coin/pause.png"));
        ui->stopPushButton->setToolTip("暂停");
        break;
    }
}

void MainWindow::on_nextPushButton_clicked()
{
    if(m_playlist.isEmpty()) return;

    if(m_currentIndex != -1 && m_currentIndex < (m_playlist.size()-1))
    {
        m_currentIndex++;
    }
    else if(m_currentIndex == (m_playlist.size()-1))
    {
        m_currentIndex = 0;
    }
    playCurrent();
    ui->musicListView->setCurrentIndex(QModelIndex(ui->musicListView->model()->index(m_currentIndex,0)));

    //qDebug()<<m_playlist.size()-1<<m_currentIndex;

    if(ui->stackedWidget->currentIndex() == 0)
    {
        ui->musicNameLabel->setText("音乐播放器");
    }
    else
    {
        QStandardItem *item = m_item->item(m_currentIndex);
        if (item) {
            ui->musicNameLabel->setText(item->text());
        }
    }
}


void MainWindow::on_previousPushButton_clicked()
{
    if(m_playlist.isEmpty()) return;
    if(m_currentIndex != -1 && (m_currentIndex != 0 && m_currentIndex <= (m_playlist.size()-1)))
    {
        m_currentIndex--;
    }
    else if(m_currentIndex == 0)
    {
        m_currentIndex = m_playlist.size() - 1;
    }
    playCurrent();
    ui->musicListView->setCurrentIndex(QModelIndex(ui->musicListView->model()->index(m_currentIndex,0)));

    if(ui->stackedWidget->currentIndex() == 0)
    {
        ui->musicNameLabel->setText("音乐播放器");
    }
    else
    {
        QStandardItem *item = m_item->item(m_currentIndex);
        if (item) {
            ui->musicNameLabel->setText(item->text());
        }
    }
}


void MainWindow::openQss()
{
    QFile file(":/coin/style.qss");  // 如果放在资源文件中
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        this->setStyleSheet(styleSheet);
        file.close();
    }
}

