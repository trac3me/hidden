# Hidden

Hidden has been developed like a solution for reverse engineering and researching tasks. This is a windows driver with a usermode interface which is used for hiding specific environment on your windows machine, like installed RCE programs (ex. procmon, wireshark), vm infrastracture (ex. vmware tools) and etc. 
此项目是用来隐藏文件、注册表、进程，启动隐藏的进程。在驱动中实现，有应用层接口。

## Features

- hide registry keys and values
- hide files and directories
- hide processes (*experemental, might be not stable*)
- protect specific processes
- exclude specific processes from hiding and protection features
- usermode interface (lib and cli) for working with a driver

and so on

## System requirements

Windows Vista and above, x86 and x64

## Recommended build environment

- Visual Studio 2019
- Windows Driver Kit 10

## Building

Following guide explains how to make a release win32 build
1. Open Hidden.sln using Visual Studio
2. Build **Hidden Package** project with configurations Release, Win32
3. Open build results folder **\<ProjectDir\>\Release**

## Installing

1. Disable a digital signature enforcement on a test machine (bcdedit /set TESTSIGNING ON) and reboot it
2. Copy files from **\<ProjectDir\>\Release\Hidden Package** to a test machine
3. Right mouse click on **Hidden.inf** and choose **Install**
4. Start a driver (sc start hidden)
5. Make sure service is running (sc query hidden)

Important: Keep in mind that the driver bitness have to be the same to an OS bitness

## Hiding

A command line tool **hiddencli** is used for managing a driver. You are able to use it for hiding and unhiding objects, changing a driver state and so on.

To hide a file try the command
```
hiddencli /hide file c:\Windows\System32\calc.exe
```

Want to hide a directory? No problems
```
hiddencli /hide dir "c:\Program Files\VMWare"
```

Registry key?
```
hiddencli /hide regkey "HKCU\Software\VMware, Inc."
```

Maybe a process?
```
hiddencli /hide pid 2340
```

By a process image name?
```
hiddencli /hide image apply:forall c:\Windows\Explorer.EXE
```

To get a full help just type
```
hiddencli /help
```
