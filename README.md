# Material-Color
这个主题旨在模仿 Windows10 自带输入法的UI

# 使用方式
```
mkdir -p ~/.local/share/fcitx5/themes/Material-Color
git clone https://github.com/hosxy/Fcitx5-Material-Color.git ~/.local/share/fcitx5/themes/Material-Color
```

然后修改配置文件： `~/.config/fcitx5/conf/classicui.conf`

```
# 垂直候选列表
Vertical Candidate List=False

# 按屏幕 DPI 使用
PerScreenDPI=True

# Font (设置成你喜欢的字体)
Font="思源黑体 CN Medium 13"

# 主题
Theme=Material-Color
```

要使用单行模式(inline_preedit),请修改 `~/.config/fcitx5/conf/pinyin.conf`, 加入/修改以下内容：

```
# 开启单行预编辑模式
PreeditInApplicaation=True
```

**注意: 修改配置文件时，请务必退出 fcitx5 输入法，因为输入法退出时会覆盖配置文件**

# 截图

丑陋的双行模式：

![No-Preedit](./screenshot/No-Preedit.png)

漂亮的单行模式：

pink:
![粉红色](./screenshot/pink.png)

blue:
![蓝色](./screenshot/blue.png)

brown:
![棕色](./screenshot/brown.png)

deepPurple:
![深紫色](./screenshot/deepPurple.png)

Indigo:
![Indigo](./screenshot/Indigo.png)

red:
![红色](./screenshot/red.png)

teal:
![Teal](./screenshot/teal.png)



# 更换配色方案
主题默认配色方案是：pink <br>
由于目前 fcitx5 还没有图形界面的主题编辑器，跟换配色方案需要使用命令行，<br>
比如将配色方案切换为 blue：

```
cd ~/.local/share/fcitx5/themes/Material-Color
ln -sf ./panel-blue.png  panel.png
ln -sf ./highlight-blue.png  highlight.png
```

