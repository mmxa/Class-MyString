// 插入排序_序列基本有序时效率较高.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
void insertsort(int arr[], int len) {
	int j = 0;
	for (int i = 1; i < len; i++) {
		if (arr[i] < arr[i - 1]) {
			int temp = arr[i];
			for (j = i-1; j >= 0 && temp<arr[j]; j--) {
				arr[j + 1] = arr[j];
			}
			arr[j+1] = temp;
		}
	}

}
void shellsort(int arr[], int len) {
	int i, j, k;
	int increasement = len;
	do {
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++) {
			for (j = i+increasement; j < len; j += increasement) //从每个分组的第二个元素开始进行插入排序
			{
				if (arr[j] < arr[j - increasement]) {
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement) {
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);

}
int main()
{
	int a[8] = {51,21,41,5,74,6,41,23};
	shellsort(a, 8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", a[i]);
	}
}

