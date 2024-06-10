# 22 - 矩阵相乘

矩阵相乘是线性代数中一个基本操作，广泛应用于图像处理、机器学习、物理模拟等领域。在这个任务中，我们需要实现矩阵相乘的操作，并将结果矩阵输出。

你需要实现一个函数 `multiply`，该函数用于计算两个矩阵的乘积。

矩阵的定义由以下结构表示：

```c
int **multiply(int **A, int ASize, int *AColSize, int **B, int BSize, int *BColSize, int *returnSize, int **returnColumnSizes);
```

## 例子

假设我们有两个矩阵：

矩阵 A：
```
1 2 3
4 5 6
7 8 9
```

矩阵 B：
```
9 8 7
6 5 4
3 2 1
```

调用 `multiply(A, 3, AColSize, B, 3, BColSize, &returnSize, &returnColumnSizes)` 后，返回的新矩阵应该是：

```
30 24 18
84 69 54
138 114 90
```

## 输入

两个矩阵 A 和 B，每个矩阵由逗号分隔的数值表示。例如：
```
矩阵 A：`1,2,3,4,5,6,7,8,9`
矩阵 B：`9,8,7,6,5,4,3,2,1`
```

## 输出

打印相乘后的矩阵

`Result:
30 24 18
84 69 54
138 114 90`
```
