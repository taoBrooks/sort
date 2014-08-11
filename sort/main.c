//
//  main.c
//  sort
//
//  Created by wangyu on 14-8-5.
//  Copyright (c) 2014年 tz. All rights reserved.
//

#include <stdio.h>

#include <stdio.h>

void swap(int arr[],int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int Findmin(int arr[], int length){
    int min = arr[0];
    int i;
    for(i=0; i< length; i++)
        if(min > arr[i])
            min = arr[i];
    return min;
}
void Bubblesort(int array[], int length){ // 冒泡，两两交换，将最大的挪到最高位
    int i, j;
    for(i = 0; i < length; i++){
        for(j = 0; j < length - i; j++)
            if(array[j] > array[j+1]){
                swap(array, j, j+1);
            }
    }
}
void SelectionSort(int arr[], int length){ //选择排序，选择一个最小的，交换
    int i,j;
    for (i = 0; i< length; i++) {
        int min = i;
        for (j = i; j<length; j++) {
            if (arr[min] > arr[j]) {    //半天没想通...
                min = j;
            }
        }
        if (min != i) {
            swap(arr, i, min);
        }
    }
}


void selectionsort(int arr[], int length){
    int base, curr;
    for(base = 0; base < length; base++)
        for(curr = base; curr < length; curr++){
            if(arr[base] > arr[curr])
                swap(arr, base, curr);
        }
}




void select_sort(int *a, int n)
{
    int i, j, min, t;
    for( i =0; i < n -1; i++) {
        min = i; //查找最小值
        for( j = i +1; j < n; j ++)
            if( a[min] > a[j])
                min = j; //交换
        if(min != i)
        {
            t = a[min];
            a[min] = a[i];
            a[i] = t;
        }
    }
}

int partition(int arr[], int left, int right){ // 快排
    int pivot = arr[(left + right)/2];
    while(left <= right){
        while(arr[left] < pivot)
            left++;
        while(arr[right] > pivot)
            right--;
        if(left <= right){
            swap(arr, left, right);
            left++;
            right--;
        }
    }
    return left;
}
void QuickSort(int arr[], int left, int right){ // 快排
    int index = partition(arr, left, right);
    if(left < index-1)
        QuickSort(arr, left, index-1);
    if(right > index)
        QuickSort(arr, index, right);
}
int main(){
    int array[10] = {1,4,2,3,13,10,12,0,8,5};
    int i;
    for(i=0; i<10; i++)
        printf("%d ",array[i]);
    printf("\n");
    //Bubblesort(array, 10);
    SelectionSort(array, 10);
    //QuickSort(array,0,9);
    for(i=0; i<10; i++)
        printf("%d ",array[i]);
    return 0;
}
