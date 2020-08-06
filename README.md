# Material-Color
这个主题使用了 Material Design 定义的标准颜色，界面旨在模仿 Windows10 自带输入法的UI。

# 使用方式
## 安装
### 发行版包管理器
+ **Arch Linux：** `pacman -S fcitx5-material-color` <br>
+ **[Debian](https://tracker.debian.org/pkg/fcitx5-material-color)：** `apt install fcitx5-material-color` <br>

然后修改配置文件： `~/.config/fcitx5/conf/classicui.conf`
```
# 垂直候选列表
Vertical Candidate List=False

# 按屏幕 DPI 使用
PerScreenDPI=True

# Font (设置成你喜欢的字体)
Font="思源黑体 CN Medium 13"

# 主题
Theme=Material-Color-Pink
```
根据颜色不同，使用以下主题名称:
+ Material-Color-Pink
+ Material-Color-Blue
+ Material-Color-Brown
+ Material-Color-DeepPurple
+ Material-Color-Indigo
+ Material-Color-Red
+ Material-Color-Teal

### 手动安装
```
mkdir -p ~/.local/share/fcitx5/themes/Material-Color
git clone https://github.com/hosxy/Fcitx5-Material-Color.git ~/.local/share/fcitx5/themes/Material-Color
```
+ #### 手动设置配色方案：
    手动设置/切换配色方案需要使用命令行，<br>
比如将配色方案设置/切换为 blue：

```
cd ~/.local/share/fcitx5/themes/Material-Color
ln -sf ./theme-blue.conf  theme.conf
```
>  **Tips1：第一次使用时必须设置一种配色方案(不然会打回原形)，因为一些原因不方便设置一个默认的配色方案**<br>
  **Tips2：设置/切换配色方案后须重启输入法以生效**

+ #### 启用主题
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

+ #### 更新：
  想要更新这个皮肤很简单，打开一个终端，执行以下命令：

```
cd ~/.local/share/fcitx5/themes/Material-Color
git pull
```

## 单行模式(inline_preedit)
要使用单行模式(inline_preedit),<br>
对于fcitx5自带pinyin 请修改 `~/.config/fcitx5/conf/pinyin.conf`, <br>
对于fcitx5-rime，请新建/修改 `~/.config/fcitx5/conf/rime.conf` ，<br>
加入/修改以下内容：

```
# 可用时在应用程序中显示预编辑文本
PreeditInApplication=True
```

**注意: 修改配置文件 `~/.config/fcitx5/profile` 时，请务必退出 fcitx5 输入法，否则会因为输入法退出时会覆盖配置文件导致之前的修改被覆盖，修改其他配置文件可以不用退出fcitx5输入法，重启生效**



# 截图

## 丑陋的双行模式：

![No-Preedit](./screenshot/No-Preedit.png)

## 漂亮的单行模式(preedit)：

### pink:

![粉红色](./screenshot/pink.png)

### blue:

![蓝色](./screenshot/blue.png)

### brown:

![棕色](./screenshot/brown.png)

### deepPurple:

![深紫色](./screenshot/deepPurple.png)

### indigo:

![Indigo](./screenshot/indigo.png)

### red:

![红色](./screenshot/red.png)

### teal:

![Teal](./screenshot/teal.png)


# 备注
1. 使用 xim 的程序(非GTK非QT程序)中无法使用单行模式，比如 xterm alacritty ...
2. 较新版本 fcitx5 默认禁用了 gvim 的单行模式，若需启用，只需将环境变量`FCITX_NO_PREEDIT_APPS`设置为空即可。
