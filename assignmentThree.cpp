#include <iostream>

using namespace std;

bool findTriples(int A[], int size, int sum) {
    for (int i = 0; i < size - 2; ++i) {
        for (int j = i + 1; j < size - 1; ++j) {
            for (int k = j + 1; k < size; ++k) {
                if (A[i] + A[j] + A[k] == sum) {
                    cout << "Triplets are: " << A[i] <<
                         ", " << A[j] << ", " << A[k];
                    return false;
                }
            }
        }
    }
    // cout << "No Triples Found!!! " << endl;
    return false;
}


int main() {
    int size;
    // cout << "Please Enter The Size of The Array: ";
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; ++i) {
        // cout << "Enter [" << i << "] Array Element:  ";
        cin >> arr[i];
    }

    int sum;
    // cout << "Please Enter The Sum of The Triples: ";
    cin >> sum;

    findTriples(arr, size, sum);

    return 0;
}