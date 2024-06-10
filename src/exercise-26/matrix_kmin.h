typedef struct
{
  int val; // 值
  int row; // 行索引
  int col; // 列索引
} HeapNode;

typedef struct
{
  HeapNode *array; // 存储堆节点的数组
  int size;        // 堆的当前大小
  int capacity;    // 堆的容量
} MinHeap;

MinHeap *createMinHeap (int capacity);

void swap (HeapNode *a, HeapNode *b);

void minHeapify (MinHeap *heap, int idx);

HeapNode extractMin (MinHeap *heap);

void insertMinHeap (MinHeap *heap, HeapNode node);

int kthSmallest (int **matrix, int matrixSize, int *matrixColSize, int k);
