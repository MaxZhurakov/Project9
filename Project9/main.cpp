//HM_ex_1_24.03.2023_
#include <iostream>
using namespace std;
void compressArray(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++;
        }
    }
    while (count < n) {
        arr[count] = -1;
        count++;
    }
}
int main() {
    int arr[] = { 1, 0, 2, 0, 3, 4, 0, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    compressArray(arr, n);

    cout << "Compressed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
//HM_ex_2_24.03.2023_
#include <iostream>
using namespace std;
int main() {
    int arr1[5] = { 3, 1, -2, 0, 4 };
    int arr2[5] = { -1, 2, 0, -3, 5 };
    int arr3[10];
    int pos = 0, zero = 0, neg = 0;
    for (int i = 0; i < 5; i++) {
        if (arr1[i] > 0) {
            arr3[pos] = arr1[i];
            pos++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (arr2[i] > 0) {
            arr3[pos] = arr2[i];
            pos++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (arr1[i] == 0) {
            arr3[pos + zero] = arr1[i];
            zero++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (arr2[i] == 0) {
            arr3[pos + zero] = arr2[i];
            zero++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (arr1[i] < 0) {
            arr3[pos + zero + neg] = arr1[i];
            neg++;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (arr2[i] < 0) {
            arr3[pos + zero + neg] = arr2[i];
            neg++;
        }
    }
    cout << "Merged array: ";
    for (int i = 0; i < 10; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    return 0;
}