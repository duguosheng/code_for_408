#include <iostream>
using namespace std;

void ShellSort(int arr[], size_t n) {
    size_t j;
    for (size_t dk = n / 2; dk > 0; dk /= 2)
        for (size_t i = dk + 1; i < n; ++i) {
            if (arr[i] < arr[i - dk]) {
                arr[0] = arr[i];
                for (j = i - dk; arr[0] < arr[j]; j -= dk)
                    arr[j + dk] = arr[j];
                arr[j + dk] = arr[0];
            }
        }
}
int main(int argc, char const* argv[]) {
    int arr[] = {0, 9, 2, 4, 1, 7, 4, 8};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        cout << arr[i] << " ";
    cout << endl;
    ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
