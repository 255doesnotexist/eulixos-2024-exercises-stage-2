# 36 - 编写一个内核模块计算数组中所有元素的最大值

## 题目描述

编写一个内核模块，接收一个整数数组作为输入，计算数组中所有元素的最大值，并输出结果。

### 输入

- 一个整数数组

## 输出

- 数组中的最大值

## 示例：

- 输入：[8, 3, 12, 6, 20]
- 输出：20

## 本地测试：

``` shell
make
insmod max_value.ko input_str="1,2,3,4,5"
rmmod max_value.ko
```
