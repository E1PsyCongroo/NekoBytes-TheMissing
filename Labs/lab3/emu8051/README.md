## 51虚拟工具安装介绍
### 安装说明
1. 解压emu8051-master.zip文件
2. 调取终端,输入
    ```bash
    sudo apt-get install libncurses5 libncurses5-dev
    make
    ```

### 使用说明
1. 运行文件
    ```bash
    ./emu
    ```

2. 按键说明:
    - v:切换显示窗口
    - l:烧录本目录下的十六进制文件
    - +/-:调节运行的频率
    - Q:退出
    - r:运行

3. 想要观察现象,单击v进行跳转直到看到P2这个数据框,需要观察的数据是P2的最低位,其中 "*" 表示高电平(5V),"_"表示低电平(0V)

> [仓库链接](https://github.com/jarikomppa/emu8051)