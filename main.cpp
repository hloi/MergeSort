#include <iostream>

using namespace std;

void merge(int arr[], const int left, const int mid,const int right) {
    int arr1Size = mid - left + 1;
    int arr2Size = right - mid;
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
    int indexMergeArr = left;  // typo here

    while ((indexArr1 < arr1Size) && (indexArr2 < arr2Size)) {
        if (leftArr[indexArr1] <= rightArr[indexArr2]) {
            arr[indexMergeArr] = leftArr[indexArr1];
            indexArr1++;

        }
        else {
            arr[indexMergeArr] = rightArr[indexArr2];
            indexArr2++;

        }
        indexMergeArr++;
    }

    // copy remaining data  left > right
    while (indexArr1 < arr1Size) {
        arr[indexMergeArr] = leftArr[indexArr1];
        indexArr1++;
        indexMergeArr++;
    }

    // right > left
    while (indexArr2 < arr2Size) {
        arr[indexMergeArr] = rightArr[indexArr2];
        indexArr2++;
        indexMergeArr++;
    }

    delete[] leftArr;
    delete[] rightArr;
}


void mergeSort(int arr[], const int left, const int right)
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
        cout << arr[i] << " ";
    }
    cout << endl;
}






int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = 6;
    printArray(arr,size);
    mergeSort(arr, 0, size-1);
    printArray(arr,size);

    return 0;
}


//// C++ program for Merge Sort
//#include <iostream>
//using namespace std;
//
//// Merges two subarrays of array[].
//// First subarray is arr[begin..mid]
//// Second subarray is arr[mid+1..end]
//void merge(int array[], int const left, int const mid,
//           int const right)
//{
//    auto const subArrayOne = mid - left + 1;
//    auto const subArrayTwo = right - mid;
//
//    // Create temp arrays
//    auto *leftArray = new int[subArrayOne],
//            *rightArray = new int[subArrayTwo];
//
//    // Copy data to temp arrays leftArray[] and rightArray[]
//    for (auto i = 0; i < subArrayOne; i++)
//        leftArray[i] = array[left + i];
//    for (auto j = 0; j < subArrayTwo; j++)
//        rightArray[j] = array[mid + 1 + j];
//
//    auto indexOfSubArrayOne
//            = 0, // Initial index of first sub-array
//    indexOfSubArrayTwo
//    = 0; // Initial index of second sub-array
//    int indexOfMergedArray
//            = left; // Initial index of merged array
//
//    // Merge the temp arrays back into array[left..right]
//    while (indexOfSubArrayOne < subArrayOne
//           && indexOfSubArrayTwo < subArrayTwo) {
//        if (leftArray[indexOfSubArrayOne]
//            <= rightArray[indexOfSubArrayTwo]) {
//            array[indexOfMergedArray]
//                    = leftArray[indexOfSubArrayOne];
//            indexOfSubArrayOne++;
//        }
//        else {
//            array[indexOfMergedArray]
//                    = rightArray[indexOfSubArrayTwo];
//            indexOfSubArrayTwo++;
//        }
//        indexOfMergedArray++;
//    }
//    // Copy the remaining elements of
//    // left[], if there are any
//    while (indexOfSubArrayOne < subArrayOne) {
//        array[indexOfMergedArray]
//                = leftArray[indexOfSubArrayOne];
//        indexOfSubArrayOne++;
//        indexOfMergedArray++;
//    }
//    // Copy the remaining elements of
//    // right[], if there are any
//    while (indexOfSubArrayTwo < subArrayTwo) {
//        array[indexOfMergedArray]
//                = rightArray[indexOfSubArrayTwo];
//        indexOfSubArrayTwo++;
//        indexOfMergedArray++;
//    }
//    delete[] leftArray;
//    delete[] rightArray;
//}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
//void mergeSort(int array[], int const begin, int const end)
//{
//    if (begin >= end)
//        return; // Returns recursively
//
//    auto mid = begin + (end - begin) / 2;
//    mergeSort(array, begin, mid);
//    mergeSort(array, mid + 1, end);
//    merge(array, begin, mid, end);
//}
//
//// UTILITY FUNCTIONS
//// Function to print an array
//void printArray(int A[], int size)
//{
//    for (auto i = 0; i < size; i++)
//        cout << A[i] << " ";
//}
//
//// Driver code
//int main()
//{
//    int arr[] = { 12, 11, 13, 5, 6, 7 };
//    auto arr_size = sizeof(arr) / sizeof(arr[0]);
//
//    cout << "Given array is \n";
//    printArray(arr, arr_size);
//
//    mergeSort(arr, 0, arr_size - 1);
//
//    cout << "\nSorted array is \n";
//    printArray(arr, arr_size);
//    return 0;
//}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes


//int partition(int arr[], int start, int end) {
//    int pivot = arr[start];
//
//    int count = 0;
//    for (int i=0; i<= end; i++) {
//        if (arr[i] <= pivot) {
//            count++;
//        }
//    }
//    int pivotIndex = start + count;
//    swap(arr[pivotIndex], arr[start]);
//
//}
//
//
//
//void quickSort(int arr[], int start, int end) {
//    if (start >= end) {
//        return;
//    }
//    int p = partition(arr, start, end);
//
//    quickSort(arr, start, p-1);
//    quickSort(arr, p+1, end);
//}
//
//void printArray(int A[], int size)
//{
//    for (auto i = 0; i < size; i++)
//        cout << A[i] << " ";
//}
//
//int main() {
//    int arr[] = { 12, 11, 13, 5, 6, 7 };
//    int size = 6;
//    printArray(arr, size);
//    quickSort(arr, 0, size-1);
//    printArray(arr, size);
//}