<div align="center">
  <img src="https://cdn.xyxsw.site/hdu-cs-wiki%20full.svg" alt="logo" width="450rem" height="450rem"/>
</div>
<h1 align="center">NekoBytes-TheMissing 贡献者指南</h1>
<p align="center">
  <a href="https://github.com/E1PsyCongroo/NekoBytes-TheMissing/blob/master/LICENSE">
    <img src="https://img.shields.io/github/license/E1PsyCongroo/NekoBytes-TheMissing?color=red" alt="license">
  </a>
  <a href="https://github.com/E1PsyCongroo/NekoBytes-TheMissing/releases">
    <img src="https://img.shields.io/github/v/release/E1PsyCongroo/NekoBytes-TheMissing?color=purple&include_prereleases" alt="release">
  </a>
  <a href="https://github.com/E1PsyCongroo/NekoBytes-TheMissing/issues">
    <img src="https://img.shields.io/github/issues/E1PsyCongroo/NekoBytes-TheMissing?color=lightgreen" alt="issues">
  </a>
  <a href="https://github.com/E1PsyCongroo/NekoBytes-TheMissing/pulls">
    <img src="https://img.shields.io/github/issues-pr/E1PsyCongroo/NekoBytes-TheMissing?color=lightgreen" alt="pulls">
  </a>
</p>

## Pull Request 流程与指南
Fork 本仓库，然后在你的仓库中进行修改，修改完成后在本仓库创建 NEW Pull Request ，选择 compare across forks 提交 pr 并评论上你修改的具体信息即可，我们会第一时间审阅并合并。

## 项目结构
```
NekoBytes-TheMissing
├── Labs/                 // 课程实验
│   └── Solutions/        // 实验答案
├── Lectures/             // 课程PPT
├── Notes/                // 课程讲义
├── Projects/             // 课程大作业
├── Tools/                // 工具
│   └── Setup/            // Linux初始化配置工具
├── Web/                  // 课程主页
├── Others/               // 其他杂项，比如辅助阅读资源、课程示例代码
```

## 项目任务说明
对应模块的任务说明请**参考对应目录**下的 README 文档。
### Labs
- 课程实验，应保证实验框架注释充分明确，为每个实验配备对应的README文档指引，提供基本的单元测试
- 本项目实验环境均为 **Ubuntu 22.04**，请贡献者确保课程实验能在该环境下正确进行
- 目录下实验应确保为 Linux 环境下的 **tar.gz** 压缩格式。命名格式如下: Lab0.tar.gz, Lab1.tar.gz, Lab2.tar.gz, ...
#### Solutions
- 项目实验配套解决方案，同样为 **tar.gz** 压缩格式。命名格式如下: Lab0-Sol.tar.gz, Lab1-Sol.tar.gz, ...
- 如有需要，可附文档文字说明
### Lectures
课程幻灯片，最终格式确保导出为 **PDF , 开发分支需要上传可供编辑修改的版本**。
### Notes
课程讲义，最终格式确保导出为 **MarkDown 与 PDF , 开发分支需要上传可供编辑修改的版本**。
### Projects
- 课程大作业，应配备完善的单元测试，README 文档。
- 本项目实验环境均为 **Ubuntu 22.04**，请贡献者确保课程实验能在该环境下正确进行
- 目录下作业应确保为 Linux 环境下的 **tar.gz** 压缩格式。命名格式如下: Proj0.tar.gz, Proj1.tar.gz, ...
- 不必提供对应的解决方案。
### Tools
#### Setup
Linux系统统一配置管理工具，为 Ubuntu 22.04 提供统一的环境可自定义初始化的配置工具。