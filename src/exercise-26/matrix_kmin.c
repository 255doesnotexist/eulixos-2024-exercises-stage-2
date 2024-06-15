#include "matrix_kmin.h"
#include <stdio.h>
#include <stdlib.h>

MinHeap *
createMinHeap (int capacity)
{
  MinHeap *heap = (MinHeap *)malloc (sizeof (MinHeap));
  heap->capacity = capacity;
  heap->size = 0;
  heap->array = (HeapNode *)malloc (capacity * sizeof (HeapNode));
  return heap;
}

void
swap (HeapNode *a, HeapNode *b)
{
  HeapNode temp = *a;
  *a = *b;
  *b = temp;
}

void
minHeapify (MinHeap *heap, int idx)
{
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < heap->size && heap->array[left].val < heap->array[smallest].val)
    {
      smallest = left;
    }
  if (right < heap->size && heap->array[right].val < heap->array[smallest].val)
    {
      smallest = right;
    }
  if (smallest != idx)
    {
      swap (&heap->array[idx], &heap->array[smallest]);
      minHeapify (heap, smallest);
    }
}

HeapNode
extractMin (MinHeap *heap)
{
  if (heap->size == 0)
    {
      printf ("Heap underflow\n");
      exit (1);
    }
  HeapNode min = heap->array[0];
  heap->array[0] = heap->array[heap->size - 1];
  heap->size--;
  minHeapify (heap, 0);
  return min;
}

void
insertMinHeap (MinHeap *heap, HeapNode node)
{
  if (heap->size == heap->capacity)
    {
      printf ("Heap overflow\n");
      exit (1);
    }
  int i = heap->size;
  heap->size++;
  heap->array[i] = node;
  while (i > 0 && heap->array[(i - 1) / 2].val > heap->array[i].val)
    {
      swap (&heap->array[i], &heap->array[(i - 1) / 2]);
      i = (i - 1) / 2;
    }
}

int
kthSmallest (int **matrix, int matrixSize, int *matrixColSize, int k)
{
  MinHeap *heap = createMinHeap (matrixSize);

  // 下面对算法进行具体实现
    for (int i = 0; i < matrixSize; i++)
    {
      HeapNode node;
      node.val = matrix[i][0];
      node.row = i;
      node.col = 0;
      insertMinHeap (heap, node);
    }

  HeapNode hr; const int INT_MAX = (1 << 30) - 1;
  for (int i = 0; i < k - 1; i++)
    {
      hr = extractMin (heap);
      int nextVal = (hr.col < matrixColSize[hr.row] - 1)
                      ? matrix[hr.row][hr.col + 1]
                      : INT_MAX;
      if (nextVal != INT_MAX)
        {
          HeapNode newNode;
          newNode.val = nextVal;
          newNode.row = hr.row;
          newNode.col = hr.col + 1;
          insertMinHeap (heap, newNode);
        }
    }

  int result = heap->array[0].val;
  free (heap->array);
  free (heap);
  return result;
}
