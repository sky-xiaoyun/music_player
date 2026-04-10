# 音乐播放器 (Music Player)

基于 Qt 6 开发的简易本地音乐播放器，支持 mp3/wav/ogg 格式。

## 功能
- 选择文件夹，自动扫描并添加音乐
- 播放/暂停、上一首/下一首
- 进度条拖动、音量调节
- 歌曲列表显示，双击播放
- 播放结束自动切换下一首
- 列表界面与唱片封面界面切换

## 技术栈
- C++17
- Qt 6.9.3 (Widgets, Multimedia, Core, Gui)
- QMediaPlayer + QAudioOutput
- 模型/视图架构 (QStandardItemModel)

## 如何运行
1. 使用 Qt Creator 打开项目
2. 配置 Qt 6.9.3 MinGW 64-bit 套件
3. 编译运行