#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int arr1Size = mid-left+1;
    int arr2Size = right - left;
    int* leftArr = new int[arr1Size];
    int* rightArr = new int[arr2Size];
    for (int i=0; i< arr1Size; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i=0; i< arr2Size; i++) {
        rightArr[i] = arr[mid+1+i];
    }
    int indexArr1=0;
    int indexArr2=0;
    int indexMergeArr = 0;

    while ((indexArr1 < arr1Size) && (indexArr2 < arr2Size) {
        if (leftArr[indexArr1] <= rightArr[indexArr2]) {
            arr[indexMergeAr] = leftArr[indexArr1];
            indexArr1++;
        }
        else {
            arr[indexMergeAr] = rightArr[indexArr2];
            indexArr2++;
        }
    }

    while (indexOfArr2 < arr2Size) {
        arr[indexMergeArr] = rightArr[indexOfArr2];
        indexOfArr2++;
        indexOfMergeAr++;
    }

    delete[] lefit;
    delete[] right;
}


void mergeSort(int arr[], int left, int right)
{

    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}


void printArray(int arr[], int size) {
    for (int i=0; i<size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}






int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = 6;

    mergeSort(arr, 0, size-1);


    return 0;
}
