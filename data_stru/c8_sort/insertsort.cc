#include <iostream>

void InsertSort(int arr[], size_t n) {
    size_t j;
    for (size_t i = 2; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            arr[0] = arr[i];
            for (j = i - 1; arr[0] < arr[j]; --j)
                arr[j + 1] = arr[j];
            arr[j + 1] = arr[0];
        }
    }
}

void InsertSort1(int arr[], size_t n) {
    size_t j, low, high, mid;
    for (size_t i = 2; i < n; ++i) {
        arr[0] = arr[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] > arr[0])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; --j)
            arr[j + 1] = arr[j];
        arr[high + 1] = arr[0];
    }
}

int main(int argc, char const* argv[]) {
    int arr[] = {0, 9, 2, 4, 1, 7, 4, 8};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    InsertSort1(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}
