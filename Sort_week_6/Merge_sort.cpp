#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for (int k = 0; k < n; k++) cout << arr[k] << " ";
    cout << endl;
}
void merge(int arr[], int left, int mid, int right, int n) {
    int m = right - left + 1;
    int temp[m];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int p = 0; p < m; p++) {
        arr[left + p] = temp[p];
    }
    print(arr, n);
}

void mergeSort(int arr[], int left, int right, int n) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, n);
    mergeSort(arr, mid + 1, right, n);
    merge(arr, left, mid, right, n);
}

int main() {
    int arr[] = {101, 23, 57, 13, 25, 121, 87, 36, 18, 204, 111, 89, 59};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    mergeSort(arr, 0, n - 1, n);
    return 0;
}