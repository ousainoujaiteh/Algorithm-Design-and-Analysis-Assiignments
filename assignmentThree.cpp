#include <iostream>
#include <algorithm>

using namespace std;

int threeNumberSum(int array[],int size){
    int count = 0;
    int targetSum = 0;
    std::sort(array,array + size);
    int left, right, findingSum;
    for (int i = 0; i < size - 2; i++) {
        if (targetSum < array[i]) break;
        findingSum = targetSum - array[i];
        left = i +1;
        right = size -1;
        while (left < right) {
            if ((array[left] + array[right]) < findingSum){
                left ++;
            } else if ((array[left] + array[right]) > findingSum){
                right--;
            } else {
                count++;
                left++;
                right--;
            }
        }
    }

    return count;
}


int main() {
    int size;
    cin >> size;

    int array[size] ;
    for (int i = 0; i < size; ++i) {
        cin>> array[i];
    }
    cout << threeNumberSum(array, size);

    return 0;
}
