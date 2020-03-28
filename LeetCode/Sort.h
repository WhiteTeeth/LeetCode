//
//  No2.h
//  LeetCode
//
//  Created by baiya on 2020/3/24.
//  Copyright © 2020 baiya. All rights reserved.
//

#ifndef No2_h
#define No2_h

#include <vector>

void mergeList(int a[], int aLen, int b[], int bLen, int result[]) {
    
}

// 归并排序
vector<int> mergeSort(vector<int> arr) {
    int len = arr.length();
    if (len < 2) return len;
    int middle = len / 2;
    vector<int> left(arr.begin, arr.begin + middle);
    vector<int> right(arr.begin + middle, arr.begin + len);
    return merge(mergeSort(left), mergeSort(right));
}

vector<int> merge(vector<int> left, vector<int> right) {
    // merge two arr
}


// 快速排序
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int key = arr[left];
        int i = left, j = right;
        while (i < j)
        {
            while (arr[j] > key && j > i)
                j--;
            if (i < j)
                arr[i++] = arr[j];
            while (arr[i] < key && i < j)
                i++;
            if (i < j)
                arr[j--] = arr[i];
        }
        arr[i] = key;
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}

#endif /* No2_h */
