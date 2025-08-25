#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

//选择排序
void SelectSort(int* arr, int sizeNum);
//堆排序
void HeapSort(int* arr, int n);

//直接插入排序
void InsertSort(int* arr, int sizeNum);
//希尔排序
void ShellSort(int* arr, int sizeNum);

void BubbleSort(int* arr, int sizeNum);
//快速排序
void QuickSort(int* arr, int left, int right);
//非递归版本快排
void QuickSortNorR(int* arr, int left, int right);

//归并排序
void MergeSort(int* arr, int sizeNum);

//计数排序
void CountSort(int* arr, int sizeNum);