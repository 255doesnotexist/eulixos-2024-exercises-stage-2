# 38 - 编写一个内核模块创建一个虚拟字符设备

## 题目描述：

编写一个内核模块，创建一个虚拟字符设备。当用户读取该设备时，返回固定的字符串

### 输入

无

### 输出

hello

## 本地测试：

``` shell
make
insmod chardev.ko message="hello"
rmmod chardev.ko
```
