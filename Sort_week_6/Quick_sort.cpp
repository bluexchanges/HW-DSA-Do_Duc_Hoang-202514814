#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void print(int arr[], int n) {
    for (int k = 0; k < n; k++) cout << arr[k] << " ";
    cout << endl;
}
void quickSort(int arr[], int low, int high, int n) {
    if (low >= high) return;
    int p = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < p) {
            Swap(arr[i], arr[j]);
            i++;
        }
    }
    Swap(arr[i], arr[high]);
    print(arr, n);
    quickSort(arr, low, i - 1, n);
    quickSort(arr, i + 1, high, n);
}
int main() {
    int arr[] = {101, 23, 57, 13, 25, 121, 87, 36, 18, 204, 111, 89, 59};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    quickSort(arr, 0, n - 1, n);
    return 0;
}