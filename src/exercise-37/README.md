# 37 - 编写一个内核模块启动一个定时器

## 题目描述：

编写一个内核模块，加载时启动一个定时器，在5s后输出一条消息到内核日志中

### 输入

-无

### 输出

-定时n秒后输出 Timer expired

## 本地测试

``` shell
make
insmod timer.ko
rmmod timer.ko
```
