#include <iostream>

using namespace std;

/*
 * Selection Sort Algorithm
 */
void selectionSort(int a[], int n) {
    int min, temp;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        // swap array elements
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main() {
    int size;
    cout << "Please Enter The Size Of The Array. It Must be between 2 and 1000:";
    cin >> size;

    int a[size];
    if (size >= 2 && size <= 999) {

        cout << "Enter First Element: ";
        for (int i = 0; i < size; ++i) {
            cin >> a[i];
            cout << "Enter [" << i << "] Array Element:  ";
        }

        cout << "Given Array is:" << endl;
        for (int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        selectionSort(a, size);
        printf("\nSorted Array Is: \n");
        for (int i = 0; i < size; i++) {
            if (!(i == size-1)){
                cout << a[i] << " ";
            }else {
                cout << a[i] << "\n";
            }
        }
    } else {
        cout << "Invalid Array Size [" << size <<"] Please Try Again: " << endl;
    }
    return 0;

}