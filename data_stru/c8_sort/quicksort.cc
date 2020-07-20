#include <algorithm>
#include <iostream>

using namespace std;
size_t Partition(int A[], size_t low, size_t high) {
    int pivot = A[low];
    while (low != high) {
        while (low < high && A[high] >= pivot) {
            --high;
        }
        // swap(A[low], A[high]);
        A[low] = A[high];
        while (low < high && A[low] <= pivot) {
            ++low;
        }
        // swap(A[low], A[high]);
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

//快速排序
void QuickSort(int A[], size_t low, size_t high) {
    int pivot_pos;
    if (low < high) {
        pivot_pos = Partition(A, low, high);
        QuickSort(A, low, pivot_pos - 1);   //左表递归
        QuickSort(A, pivot_pos + 1, high);  //右表递归
    }
}

int main(int argc, char const* argv[]) {
    int arr[] = {7, 2, 4, 9, 8, 6, 5, 4};
    size_t sz = sizeof(arr) / sizeof(arr[0]);
    QuickSort(arr, 0, sz - 1);

    for (size_t i = 0; i < sz; ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
