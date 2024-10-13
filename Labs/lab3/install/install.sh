#!/bin/bash

# 确保脚本在错误时退出，并启用调试模式
set -e
set -x

# 依赖项列表
DEPENDENCIES=("sdcc" "python3-pip" "bison" "libboost-all-dev" "flex")

# 检查依赖项是否已安装
check_dependencies() {
    missing=()
    for cmd in "${DEPENDENCIES[@]}"; do
        if ! dpkg -l | grep -q "$cmd"; then
            missing+=("$cmd")
        fi
    done

    if [ ${#missing[@]} -ne 0 ]; then
        echo "Missing dependencies: ${missing[*]}"
        return 1
    fi
    return 0
}

# 安装依赖项
install_dependencies() {
    echo "Installing missing dependencies..."
    sudo apt update
    sudo apt install -y bison libboost-all-dev flex sdcc python3-pip

    # 安装 stcgal
    python3 -m pip install --user stcgal
}

# 设置 pip 安装路径
ensure_path() {
    if ! echo "$PATH" | grep -q "$HOME/.local/bin"; then
        export PATH="$HOME/.local/bin:$PATH"
        echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
        source ~/.bashrc
    fi
}

# 主函数
main() {
    echo "Checking and installing dependencies if needed..."
    # 检查并安装依赖项
    if ! check_dependencies; then
        install_dependencies
    else
        echo "All dependencies are already installed."
    fi

    echo "Ensuring ~/.local/bin is in PATH..."
    # 确保 ~/.local/bin 在 PATH 中
    ensure_path

    echo "Verifying sdcc installation..."
    # 验证 sdcc 安装
    sdcc --version

    # echo "Creating example program..."
    # 编写示例程序
#     cat <<EOF > main.c
# #include <8052.h>

# void delay100ms()        //@11.0592MHz
# {
#     unsigned char i, j;

#     i = 180;
#     j = 73;
#     do
#     {
#         while (--j);
#     } while (--i);
# }

# void main()
# {
#     while(1)
#     {
#         P2_0 = !P2_0;
#         delay100ms();
#     }
# }
# EOF

    echo "Compiling example program..."
    # 编译示例程序
    sdcc -mmcs51 main.c

    echo "Verifying stcgal installation..."
    # 验证 stcgal 安装
    if ! command -v stcgal &> /dev/null; then
        echo "stcgal could not be found"
        exit 1
    fi

    echo "Stopping and disabling brltty service..."
    # 停止并禁用 brltty 服务
    sudo systemctl stop brltty
    sudo systemctl disable brltty

    echo "Checking serial devices..."
    # 检查串口设备
    sudo dmesg | grep -i ch34

    echo "Listing USB serial devices..."
    ls /dev/ttyUSB*

    if [ ! -e /dev/ttyUSB0 ]; then
        echo "/dev/ttyUSB0 not found. Exiting."
        exit 1
    fi

    echo "Setting permissions for /dev/ttyUSB0..."
    # 设置权限并烧录固件
    sudo chmod 666 /dev/ttyUSB0

    echo "Flashing firmware..."
    # 烧录固件
    stcgal -p /dev/ttyUSB0 -b 115200 main.ihx

    echo "Cleaning up compiled files..."
    # 删除编译产生的文件
    rm -f main.asm main.cdb main.lst main.map main.mem main.rst main.sym main.rel main.lk

    echo "Done."
}

# 执行主函数
main
