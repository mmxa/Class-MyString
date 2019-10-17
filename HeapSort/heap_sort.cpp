// 堆排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <time.h>
#include <sys/timeb.h>
#define MAX 15
using namespace std;

int* CreateArray() {
	srand((unsigned int)time(NULL));
	int* a = (int*)malloc(sizeof(int) * MAX);
	for (int i = 0; i < MAX; i++)
		a[i] = rand() % MAX;
	return a;
}
void PrintArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
}
void myswap(int arr[], int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
void HeapAdjust(int arr[], int index, int len) {
	int max = index;
	int lchild = 2 * index + 1;
	int rchild = 2 * index + 2;
	if (lchild < len && arr[lchild]>arr[max]) {
		max = lchild;
	}
	if (rchild < len && arr[rchild]>arr[max]) {
		max = rchild;
	}
	if (max != index) {
		myswap(arr, max, index);
		HeapAdjust(arr, max, len);
	}
}
void HeapSort(int arr[], int len) {
	for (int i = len / 2 - 1; i >= 0; i--) {
		HeapAdjust(arr, i, len);//初始化堆
	}
	for(int i = len - 1; i >= 0; i--) {
		myswap(arr, 0, i);
		HeapAdjust(arr, 0, i);//使得除去最大元素节点外剩下的部分的根处为最大元素
	}
	/*
	每一次HeapAdjust使得根(i.e. arr[0])的元素为最大值，
	通过交换确保本次循环中最后一个节点保存了最大值元素，
	然后对最大元素外的部分再次进行循环，实现了堆排序
	*/
}
int main()
{
	int* arr = CreateArray();
	int len = MAX;
	PrintArray(arr, len);
	HeapSort(arr, len);
	cout << endl;
	PrintArray(arr, len);
}
