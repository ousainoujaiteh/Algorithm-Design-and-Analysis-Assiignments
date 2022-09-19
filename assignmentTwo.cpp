#include <iostream>
using namespace std;
void findMajority(int arr[],int size){
    bool flag = false;
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = i; j < size; ++j) {
            if (arr[i] == arr[j]){
                count++;
            }
        }
        if (count > size/3){
            cout << arr[i] << " ";
            flag = true;
        }
    }
    if (!flag){
        // cout << "No Majority Element Found " << endl;
    }
}

int main() {
    int arr[] = { 2, 2, 3, 1, 3, 2, 1, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    findMajority(arr,size);
    return 0;
}