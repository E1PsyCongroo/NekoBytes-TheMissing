#!/usr/bin/env bash

# 定义颜色
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
RESET=$(tput sgr0)

# 定义日志级别的颜色和格式
INFO="[INFO]"
WARNING="[WARNING]"
ERROR="[ERROR]"

# 生成以日期命名的日志文件名
LOG_FILE="$(date +'%Y-%m-%d').log"

# 定义带颜色输出的日志函数
log_info() {
    echo -e "${GREEN}${INFO} $1${RESET}" | tee -a "$LOG_FILE"
}

log_warning() {
    echo -e "${YELLOW}${WARNING} $1${RESET}" | tee -a "$LOG_FILE"
}

log_error() {
    echo -e "${RED}${ERROR} $1${RESET}" | tee -a "$LOG_FILE"
}

# 默认启用 verbose 模式
VERBOSE=true

# 帮助菜单
usage() {
    echo "使用方法: $0 [选项]"
    echo ""
    echo "选项:"
    echo "  --help, -h         显示此帮助信息"
    echo "  --quiet, -q        静默模式，不显示命令输出"
    echo "  --uninstall        卸载已安装的软件和配置"
    echo ""
    echo "示例:"
    echo "  $0                 执行初始化"
    echo "  $0 --quiet         静默模式执行初始化"
    echo "  $0 --uninstall     卸载已安装的软件和配置"
}

# 定义静默或详细运行的命令
run_command() {
    if [ "$VERBOSE" = true ]; then
        # 详细模式：显示所有输出
        "$@"
    else
        # 静默模式：只隐藏标准输出，保留错误输出
        "$@" >/dev/null
    fi
}

uninstall_neovim() {
    if dpkg -l | grep -q neovim; then
        log_warning "Neovim 已安装，正在卸载..."
        run_command sudo apt-get remove -y -qq neovim
    fi
}

init() {
    # 初始化
    log_info "正在初始化脚本"
    run_command sudo apt-get update -qq
    uninstall_neovim

    # 为 chsrc 安装 curl 测速工具
    log_info "正在安装 curl 测速工具"
    run_command sudo apt-get install -y -qq curl

    # 为 ubuntu 更换镜像源
    log_info "正在为 ubuntu 更换镜像源"
    run_command sudo "$(pwd)/chsrc" set ubuntu

    # 更新系统
    log_info "正在更新系统"
    run_command sudo apt-get upgrade -y -qq

    # 安装编程开发环境
    log_info "正在安装编程开发环境和基础 CLI 工具"
    run_command sudo apt-get install -y -qq build-essential tar man gcc-doc gdb cgdb \
        libreadline-dev libsdl2-dev wget pip npm cargo ripgrep net-tools \
        valgrind clang clangd bear openssh-server git tldr vim tmux zsh

    # 开启 ssh 服务
    run_command sudo systemctl enable --now ssh

    # 安装 oh-my-zsh
    log_info "正在安装 oh-my-zsh"
    run_command cp -r "$(pwd)/pkg/ohmyzsh" "$HOME/.ohmyzsh"
    run_command cp "$(pwd)/config/.zshrc" "$HOME/.zshrc"

    # 切换用户默认 Shell
    log_info "正在切换默认 Shell 为 zsh"
    run_command chsh -s /usr/bin/zsh
    log_warning "oh-my-zsh 安装完毕, 请注意配置主题样式"

    # 安装 nerd font
    log_info "正在安装 Nerd 字体"
    run_command mkdir -p "$HOME/.local/share/fonts"
    run_command unzip "$(pwd)/pkg/JetBrainsMono.zip" -d "$HOME/.local/share/fonts"

    # 安装 NeoVim
    log_info "正在安装 NeoVim"
    run_command sudo rm -rf /opt/nvim
    run_command sudo tar -C /opt -xzf pkg/nvim-linux64.tar.gz

    # 安装 LunarVim
    log_info "正在安装 LunarVim"
    run_command mkdir -p "$HOME/.local/share"
    run_command mkdir -p "$HOME/.local/bin"
    run_command cp -r "$(pwd)/pkg/lunarvim" "$HOME/.local/share/lunarvim"
    run_command cp "$(pwd)/pkg/lvim" "$HOME/.local/bin/lvim"
    run_command cp -r "$(pwd)/config/lvim" "$HOME/.config/lvim"

    # 安装 oh-my-tmux
    log_info "正在使用 oh-my-tmux 配置 tmux"
    run_command mkdir -p "$HOME/.config/tmux"
    run_command cp "$(pwd)/config/.tmux/.tmux.conf" "$HOME/.config/tmux/tmux.conf"
    run_command cp "$(pwd)/config/.tmux/.tmux.conf.local" "$HOME/.config/tmux/tmux.conf.local"

    # 为 flatpak 更换镜像源
    log_info "正在为 flatpak 更换镜像源"
    run_command sudo apt-get install -y -qq flatpak
    run_command sudo apt-get install -y -qq gnome-software-plugin-flatpak
    run_command flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo
    run_command sudo "$(pwd)/chsrc" set flathub

    # 重新安装 firefox
    log_info "正在安装 firefox"
    run_command flatpak install -y flathub org.mozilla.firefox

    # 删除 snap
    log_info "正在删除 snap, 使用 flatpak 替代"
    cd "$(pwd)/unsnap" && run_command "$(pwd)/unsnap" auto
    run_command sudo apt-get purge -y -qq snapd

    # 完成
    log_info "正在清理无关软件包"
    run_command sudo apt-get autoremove --purge -y -qq
    log_info "系统初始化已完成"
    log_info "如果需要卸载 oh-my-zsh NeoVim LunarVim, 请键入 bash common.sh uninstall"
}

uninstall() {
    log_info "正在卸载 oh-my-zsh"
    run_command uninstall_oh_my_zsh

    log_info "正在卸载 NeoVim"
    run_command sudo rm -rf /opt/nvim

    log_info "正在卸载 LunarVim"
    run_command bash "$HOME/.local/share/lunarvim/lvim/utils/installer/uninstall.sh"
}

# 检查参数
while [[ $# -gt 0 ]]; do
    case $1 in
    --help | -h)
        usage
        exit 0
        ;;
    --quiet | -q)
        VERBOSE=false
        shift
        ;;
    --uninstall)
        uninstall
        exit 0
        ;;
    *)
        log_error "未知选项: $1"
        usage
        ;;
    esac
done

init
