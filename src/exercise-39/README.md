# 39 - 编写一个内核模块实现一个简单的文件操作函数

## 题目描述

编写一个内核模块，实现一个简单的文件操作函数，能够打开、读取、写入和关闭文件。

### 输入

无

### 输出

成功打开文件时：`File operation successful`

打开失败时：`Failed to open file`

## 本地测试

``` shell
make
insmod fileop.ko
rmmod fileop.ko
```
