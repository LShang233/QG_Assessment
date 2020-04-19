#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
    int i, j, k;
    for(i = 1; i < n; i ++)//外层循环指向需要进行排序的数
    {
        for(j = i; j > 0; j --)//内层循环进行排序
        {
            if(a[j] < a[j - 1])
            {
                k = a[j];
                a[j] = a[j - 1];
                a[j - 1] = k;
            }
            else
                break;//当插入的数大于等于前一个数时，插入完成，退出循环
        }
    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int left = begin, right = mid + 1, i = begin;
    //合并两个有序数组
    while(left <= mid && right <= end)
    {
        if(a[left] < a[right])
        {
            temp[i ++] = a[left ++];
        }
        else
        {
            temp[i ++] = a[right ++];
        }
    }
    //还剩一个没有进temp
    while(left <= mid)
    {
        temp[i ++] = a[left ++];
    }
    while(right <= end)
    {
        temp[i ++] = a[right ++];
    }
    //最后将排序好的数组复制到原数组
    for(i = begin; i <= end; ++ i)
    {
        a[i] = temp[i];
    }
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin >= end) return;
    //将数组分成小数组
    int mid = (begin + end) / 2;
    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid + 1, end, temp);
    //分到最小后开是递归，合并数组
    MergeArray(a, begin, mid, end, temp);
}



/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
    int i = begin, j = end, n;
    int t;
    n = a[(begin + end) / 2];
    while(i <= j)
    {
        while(a[i] < n)
        {
            i++;
        }
        while(a[j] > n)
        {
            j--;
        }
        if(i <= j)
        {
            t = a[i];
            a[i]= a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if(begin <j)
    {
        QuickSort_Recursion(a, begin, j);
    }
    if(i < end)
    {
        QuickSort_Recursion(a, i, end);
    }
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
int PartSort(int* a,int left,int right)
{
    int pivot = a[left];
    while (left < right)
    {
        while (left < right && a[right] >= pivot)
            right--;
        a[left] = a[right];
        while (left < right && a[left] <= pivot)
            left++;
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}
void QuickSort(int *a,int size)
{
    //建一个栈来存放要循环的index
    struct stack
    {
        int *elem;
        int top;
        int size;
    }IndexStack;
    IndexStack.elem = (int *)malloc(size * sizeof(int));
    IndexStack.top = 0;
    IndexStack.size = size;

    //进栈
    IndexStack.elem[IndexStack.top ++] = size - 1;
    IndexStack.elem[IndexStack.top ++] = 0;

    //当栈里还有数，说明还有待排列的区间
    while (IndexStack.top)
    {
        int left = IndexStack.elem[-- IndexStack.top];
        int right = IndexStack.elem[-- IndexStack.top];

        //排序
        int div = PartSort(a, left, right);
        if(div - 1 > left)//说明左区域还有至少两个数
		{
		    //进栈
		    //注意顺序
            IndexStack.elem[IndexStack.top ++] = div - 1;
            IndexStack.elem[IndexStack.top ++] = left;
		}
		if(div + 1 < right)
		{
		    //进栈
		    IndexStack.elem[IndexStack.top ++] = right;
		    IndexStack.elem[IndexStack.top ++] = div + 1;
		}
    }
}


/**
 *  @name        : int QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{
    if (begin < end)
    {
        int left = begin;
        int right = end;
        int temp = a[begin];//枢轴元素

        while (left < right)
        {
            while (left < right && a[right] >= temp)
            {
                right --;
            }
            if(left < right)
            {
                a[left ++] = a[right];
            }

            while (left < right && a[left] <= temp)
            {
                left ++;
            }
            if(left < right)
            {
                a[right --] = a[left];
            }
        }
        //枢轴元素归位
        a[left] = temp;

        Partition(a, begin, left - 1);
        Partition(a, right + 1, end);
    }
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
    //建数组
    int *arr;
    arr = (int *)malloc((max + 1) * sizeof(int));
    //桶排思想将a放入arr
    int i;
    //清空桶
    for(i = 0; i < max; i++)
    {
        arr[i] = 0;
    }
    //进入桶
    for(i = 0; i < size; i++)
    {
        arr[a[i]] ++;
    }
    //统计
    int t = 0;
    for(i = 0; i <= max; i++)
    {
        if(arr[i])
        {
            arr[i] += t;
            t = arr[i];
        }
    }
    //倒序进入新数组
    int *temp;
    temp = (int *)malloc(size * sizeof(int));
    for(i = size - 1; i >= 0; i --)
    {
        arr[a[i]] --;
        temp[arr[a[i]]] = a[i];
    }
    //复制回去
    for(i = 0; i < size; i ++)
    {
        a[i] = temp[i];
    }
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
int GetMaxPos(int *a, int size)
{
    int max = 0;
    int i;
    for(i = 0; i < size; i ++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }
    i = 0;
    while(max)
    {
        max /= 10;
        i ++;
    }
    return i;
}
void RadixCountSort(int *a,int size)
{
	int bucket[10];
	int *temp;
	int bits = 1, pos;
	int i, j;
	temp = (int *)malloc(size * sizeof(int));

	pos = GetMaxPos(a, size);
	for(j = 0; j < pos; j ++){
		for(i = 0; i < size; i++){
			temp[i] = a[i];
		}
		for(i = 0; i < 10; i ++){
			bucket[i] = 0;
		}
		//收集
		for(i = 0; i < size; i ++){
			bucket[a[i] / bits % 10] ++;
		}
		//统计
		for(i = 1; i < 10; i ++){
			bucket[i] += bucket[i - 1];
		}

		//分配
		i = size - 1;
		while(i >= 0)
        {
			a[ -- bucket[temp[i] / bits % 10]] = temp[i];
			i--;
		}
		bits *= 10;
	}
}




/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
    int p, p0, p2;
    p0 = p = 0;
    p2 = size - 1;

    while(p >= p2)
    {
        //找到不为1的点,开始循环
        while(a[p] != 1)
        {
            if(a[p] == 2)
            {
                int temp = a[p];
                a[p] = a[p2];
                a[p2] = temp;
                p2 --;
            }
            if(a[p] == 0)
            {
                int temp = a[p];
                a[p] = a[p0];
                a[p0] = temp;
                p0 ++;
            }
        }
        //p移动一位
        p ++;
    }
}


/**
 *  @name        : int GetNumber(int *a, int n, int k, _Bool isMax)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size, 第K大/小， 找最大还是找最小
 */
int PartitionOnce(int *a, int begin, int end)
{
    if (begin < end)
    {
        int left = begin;
        int right = end;
        int temp = a[begin];//枢轴元素

        while (left < right)
        {
            while (left < right && a[right] >= temp)
            {
                right --;
            }
            if(left < right)
            {
                a[left ++] = a[right];
            }

            while (left < right && a[left] <= temp)
            {
                left ++;
            }
            if(left < right)
            {
                a[right --] = a[left];
            }
        }
        //枢轴元素归位
        a[left] = temp;
        return left;
    }
}
int GetNumber(int *a, int n, int k, _Bool isMax)
{
    if(isMax)
    {
        //第k大的数 == 第n-k+1小的数
        k = n-k+1;
    }
	int l = 0;
	int r = n-1;
	while(l <= r){
	    int index = PartitionOnce(a, l, r);
	    //找到
		if(index + 1 == k){
            return a[index];
        }
        else if(index+1 < k){ //在右边序列找
		    l = index+1;
	    }
	    else{ //在左边序列找
	        r = index-1;
	    }
	}
}

