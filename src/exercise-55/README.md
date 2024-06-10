# 55 - 模拟虚拟内存限制

##  题目描述

通过容器技术，可以实现对一个进程的内存实现限制，从而避免一个病毒进程占据太多的内存，导致系统崩溃和影响其他进程。本题需要你按照注释补充所空的函数中的几个语句，实现对一个进程所使用的内存的限制。

child_program.c为所控制程序，其所实现的功能是为自己分配指定数量的内存（120M）.主程序main.c的功能是限制child_program的内存使用量（100M），从而导致子进程输出无法分配要求的内存。

void set_memory_limit(rlim_t memory_limit)；函数为所需要补充完整的函数。rlim_t 是一个在 Unix 和 Unix-like 操作系统中使用的数据类型，用于表示资源限制。这个数据类型通常与 getrlimit 和 setrlimit 系统调用一起使用，以便获取和设置进程的资源限制。

### 输出

malloc failed: Cannot allocate memory

### 构建
在主目录中执行以下命令

``` shell
make exercise-55
make test-exercise-55
```

如果非主目录中执行的话需要改变main程序中的child_program路径。
