![GitHub License](https://img.shields.io/github/license/datawhalechina/cstart)![GitHub Release](https://img.shields.io/github/v/release/datawhalechina/cstart)![GitHub Issues](https://img.shields.io/github/issues/datawhalechina/cstart?color=lightgreen)![GitHub Pr](https://img.shields.io/github/issues-pr/datawhalechina/cstart?color=lightgreen)![GitHub Starts](https://img.shields.io/github/stars/datawhalechina/cstart)

---

# CStart 贡献者指南

CStart 计算机入门导引！这是我们的编程入门系列中的第一门课程。CStart 将让您熟悉 C 编程语言，介绍计算机科学与技术中的常见主题，包括抽象、算法、体系结构、人工智能、嵌入式开发、计算机系统和编程语言，并练习应用工具来解决复杂问题。

## Pull Request 流程与指南

Fork 本仓库, 然后在你的仓库中对内容分支进行修改, 修改完成后在本仓库创建 NEW Pull Request , 选择 compare across forks 提交 pr 并评论上你修改的具体信息即可, 我们会第一时间审阅并合并。

> [!CAUTION]
> 请不要向 dev 和 master 分支提交 pr, 你应该始终向同个分支提交 pr

## 项目结构

```shell
CStart
├── Labs/                 // 课程实验
│   └── Solutions/        // 实验答案
├── Lectures/             // 课程PPT
├── Notes/                // 课程讲义
├── Projects/             // 课程大作业
├── Tools/                // 工具
│   └── setup/            // Linux初始化配置工具
├── Others/               // 其他杂项，比如辅助阅读资源、课程示例代码
```

## 项目任务说明

对应模块的任务说明请**参考对应目录**下的 README 文档。

### Labs

- 课程实验, 应保证实验框架注释充分明确, 为每个实验配备对应的README文档指引, 提供基本的单元测试
- 本项目实验环境均为 **Ubuntu 22.04**, 请贡献者确保课程实验能在该环境下正确进行
- 目录下实验应确保为 Linux 环境下的 **tar.gz** 压缩格式。命名格式如下: Lab0.tar.gz, Lab1.tar.gz, Lab2.tar.gz, ...

#### Solutions

- 项目实验配套解决方案, 同样为 **tar.gz** 压缩格式。命名格式如下: Lab0-Sol.tar.gz, Lab1-Sol.tar.gz, ...
- 如有需要, 可附文档文字说明

### Lectures

课程幻灯片, 最终格式确保导出为 **PDF或静态网页index.html , 开发分支需要上传可供编辑修改的版本**。

### Notes

课程讲义, 最终格式确保导出为 **MarkDown 与 PDF , 开发分支需要上传可供编辑修改的版本**。

### Projects

- 课程大作业, 应配备完善的单元测试, README 文档。
- 本项目实验环境均为 **Ubuntu 22.04**, 请贡献者确保课程实验能在该环境下正确进行
- 目录下作业应确保为 Linux 环境下的 **tar.gz** 压缩格式。命名格式如下: Proj0.tar.gz, Proj1.tar.gz, ...
- 不必提供对应的解决方案。

### Tools

#### Setup

Linux系统统一配置管理工具, 为 Ubuntu 22.04 提供统一的环境可自定义初始化的配置工具。

### Others

#### VSCode C/C++ 配置文件

请使用VSCode导入配置文件：C-C++.code-profile

## 参与贡献

- 如果你想参与到项目中来欢迎查看项目的 [Issue]() 查看没有被分配的任务。
- 如果你发现了一些问题，欢迎在 [Issue]() 中进行反馈🐛。
- 如果你对本项目感兴趣想要参与进来可以通过 [Discussion]() 进行交流💬。

如果你对 Datawhale 很感兴趣并想要发起一个新的项目，欢迎查看 [Datawhale 贡献指南](https://github.com/datawhalechina/DOPMC#%E4%B8%BA-datawhale-%E5%81%9A%E5%87%BA%E8%B4%A1%E7%8C%AE)。

## 关注我们

<div align=center>
<p>扫描下方二维码关注公众号：Datawhale</p>
<img src="https://raw.githubusercontent.com/datawhalechina/pumpkin-book/master/res/qrcode.jpeg" width = "180" height = "180">
</div>

## LICENCE

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="知识共享许可协议" style="border-width:0" src="https://img.shields.io/badge/license-CC%20BY--NC--SA%204.0-lightgrey" /></a><br />本作品采用<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">知识共享署名-非商业性使用-相同方式共享 4.0 国际许可协议</a>进行许可。
