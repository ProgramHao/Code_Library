#pragma once

#include<stdio.h>
#include<stdlib.h>

//打印数组
void PrintArray(int* a, int n);

//直接插入排序
//这里排升序
void InsertSort(int* a, int n);

//希尔排序，这里排升序
void ShellSort(int* a, int n);

//交换两个数
void Swap(int* a, int* b);

//选择排序 之 直接选择排序
void SelectSort(int* a, int n);

//选择排序 之 冒泡排序
void BubbleSort(int* a, int n);