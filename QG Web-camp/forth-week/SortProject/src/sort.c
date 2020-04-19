#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)
{
    int i, j, k;
    for(i = 1; i < n; i ++)//���ѭ��ָ����Ҫ�����������
    {
        for(j = i; j > 0; j --)//�ڲ�ѭ����������
        {
            if(a[j] < a[j - 1])
            {
                k = a[j];
                a[j] = a[j - 1];
                a[j - 1] = k;
            }
            else
                break;//������������ڵ���ǰһ����ʱ��������ɣ��˳�ѭ��
        }
    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int left = begin, right = mid + 1, i = begin;
    //�ϲ�������������
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
    //��ʣһ��û�н�temp
    while(left <= mid)
    {
        temp[i ++] = a[left ++];
    }
    while(right <= end)
    {
        temp[i ++] = a[right ++];
    }
    //�������õ����鸴�Ƶ�ԭ����
    for(i = begin; i <= end; ++ i)
    {
        a[i] = temp[i];
    }
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin >= end) return;
    //������ֳ�С����
    int mid = (begin + end) / 2;
    MergeSort(a, begin, mid, temp);
    MergeSort(a, mid + 1, end, temp);
    //�ֵ���С���ǵݹ飬�ϲ�����
    MergeArray(a, begin, mid, end, temp);
}



/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
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
    //��һ��ջ�����Ҫѭ����index
    struct stack
    {
        int *elem;
        int top;
        int size;
    }IndexStack;
    IndexStack.elem = (int *)malloc(size * sizeof(int));
    IndexStack.top = 0;
    IndexStack.size = size;

    //��ջ
    IndexStack.elem[IndexStack.top ++] = size - 1;
    IndexStack.elem[IndexStack.top ++] = 0;

    //��ջ�ﻹ������˵�����д����е�����
    while (IndexStack.top)
    {
        int left = IndexStack.elem[-- IndexStack.top];
        int right = IndexStack.elem[-- IndexStack.top];

        //����
        int div = PartSort(a, left, right);
        if(div - 1 > left)//˵��������������������
		{
		    //��ջ
		    //ע��˳��
            IndexStack.elem[IndexStack.top ++] = div - 1;
            IndexStack.elem[IndexStack.top ++] = left;
		}
		if(div + 1 < right)
		{
		    //��ջ
		    IndexStack.elem[IndexStack.top ++] = right;
		    IndexStack.elem[IndexStack.top ++] = div + 1;
		}
    }
}


/**
 *  @name        : int QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end)
{
    if (begin < end)
    {
        int left = begin;
        int right = end;
        int temp = a[begin];//����Ԫ��

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
        //����Ԫ�ع�λ
        a[left] = temp;

        Partition(a, begin, left - 1);
        Partition(a, right + 1, end);
    }
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
    //������
    int *arr;
    arr = (int *)malloc((max + 1) * sizeof(int));
    //Ͱ��˼�뽫a����arr
    int i;
    //���Ͱ
    for(i = 0; i < max; i++)
    {
        arr[i] = 0;
    }
    //����Ͱ
    for(i = 0; i < size; i++)
    {
        arr[a[i]] ++;
    }
    //ͳ��
    int t = 0;
    for(i = 0; i <= max; i++)
    {
        if(arr[i])
        {
            arr[i] += t;
            t = arr[i];
        }
    }
    //�������������
    int *temp;
    temp = (int *)malloc(size * sizeof(int));
    for(i = size - 1; i >= 0; i --)
    {
        arr[a[i]] --;
        temp[arr[a[i]]] = a[i];
    }
    //���ƻ�ȥ
    for(i = 0; i < size; i ++)
    {
        a[i] = temp[i];
    }
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
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
		//�ռ�
		for(i = 0; i < size; i ++){
			bucket[a[i] / bits % 10] ++;
		}
		//ͳ��
		for(i = 1; i < 10; i ++){
			bucket[i] += bucket[i - 1];
		}

		//����
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
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{
    int p, p0, p2;
    p0 = p = 0;
    p2 = size - 1;

    while(p >= p2)
    {
        //�ҵ���Ϊ1�ĵ�,��ʼѭ��
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
        //p�ƶ�һλ
        p ++;
    }
}


/**
 *  @name        : int GetNumber(int *a, int n, int k, _Bool isMax)
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size, ��K��/С�� �����������С
 */
int PartitionOnce(int *a, int begin, int end)
{
    if (begin < end)
    {
        int left = begin;
        int right = end;
        int temp = a[begin];//����Ԫ��

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
        //����Ԫ�ع�λ
        a[left] = temp;
        return left;
    }
}
int GetNumber(int *a, int n, int k, _Bool isMax)
{
    if(isMax)
    {
        //��k����� == ��n-k+1С����
        k = n-k+1;
    }
	int l = 0;
	int r = n-1;
	while(l <= r){
	    int index = PartitionOnce(a, l, r);
	    //�ҵ�
		if(index + 1 == k){
            return a[index];
        }
        else if(index+1 < k){ //���ұ�������
		    l = index+1;
	    }
	    else{ //�����������
	        r = index-1;
	    }
	}
}

