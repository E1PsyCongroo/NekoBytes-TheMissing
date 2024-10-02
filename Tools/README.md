# Setup Tool

这是一个用于初始化 Ubuntu 系统的 Bash 脚本，能够自动完成开发环境的安装与配置。脚本支持静默模式、卸载模式，并通过日志记录操作。

## 特性

- 自动更新系统及更换镜像源
- 支持安装常用编程工具和开发环境
- 安装并配置 `oh-my-zsh`、`oh-my-tmux`
- 支持 `unsnap` 并安装 `flatpak`
- 支持静默模式和卸载功能

## 使用方法

### 1. 克隆仓库获取工具

```bash
git clone https://github.com/E1PsyCongroo/NekoBytes-TheMissing.git
cd NekoBytes-TheMissing/Tools
tar xvf setup.tar.gz
```

### 2. 运行脚本

默认情况下，脚本将以详细模式运行，输出到终端并记录在一个日志文件中（文件名为当前日期）。

```bash
./script.sh
```

你可以通过 --help 选项来查看可用的命令和参数。

```bash
./script.sh --help
```

### 3. 可选参数

--help, -h: 显示帮助信息。
--quiet, -q: 以静默模式运行脚本（只输出错误信息到终端，标准输出记录到日志文件）。
--uninstall: 卸载脚本安装的软件和配置。

### 4. 示例

详细模式执行初始化

```bash
./script.sh
```

静默模式执行初始化

```bash
./script.sh --quiet
```

卸载安装的软件和配置

```bash
./script.sh --uninstall
```

### 5. 日志记录

每次运行脚本，都会将输出日志保存在以当前日期命名的 .log 文件中。日志文件会记录脚本的每个操作步骤，便于排查问题。

```bash
# 日志文件示例
2023-09-15.log
```

## 脚本功能

1. 更新系统及安装 curl:
脚本会自动运行 apt update，并安装 curl 工具。
2. 更换 Ubuntu 镜像源:
通过执行 chsrc 脚本更换镜像源，提升软件包的下载速度。
3. 删除 Snap 并安装 Flatpak:
脚本将删除 Snap 并改用 Flatpak 安装 Firefox 和其他软件包。
4. 安装编程工具:
自动安装常用的开发工具和 CLI 工具，包括 build-essential, git, vim, tmux, zsh, tldr 等。
5. 安装并配置 Oh-My-Zsh:
将 oh-my-zsh 安装到用户的 home 目录，并切换默认 Shell 为 zsh。
6. 安装 Nerd Font 字体:
自动下载并安装 JetBrains Mono 字体以支持更多终端样式。
7. 配置 Oh-My-Tmux:
脚本会将 tmux 配置文件复制到用户目录，完成终端管理工具的设置。
8. 卸载功能:
支持卸载脚本安装的软件和配置，包括 oh-my-zsh、oh-my-tmux。

## 注意事项

- 该脚本需要 sudo 权限执行，以安装和卸载系统软件。
- 默认安装的开发环境包括了 zsh, tmux 等工具，如果你不需要某些工具，可以自行修改脚本。
- 在执行脚本前，请确保系统已更新并有足够的磁盘空间。

## 许可

该项目遵循 MIT License。
