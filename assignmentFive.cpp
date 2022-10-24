#include <vector>
#include <limits.h>
#include <iostream>

using namespace std;

// Utility function to find the maximum of two numbers
int max(int x, int y) {
    return (x > y) ? x : y;
}

// Function to find the maximum subarray sum using divide-and-conquer
int maximum_sum(vector<int> &nums, int low, int high) {
    // If the array contains 0 or 1 element
    if (high <= low) {
        return nums[low];
    }

    // Find the middle array element
    int mid = (low + high) / 2;

    // Find maximum subarray sum for the left subarray,
    // including the middle element
    int left_max = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += nums[i];
        if (sum > left_max) {
            left_max = sum;
        }
    }

    // Find maximum subarray sum for the right subarray,
    // excluding the middle element
    int right_max = INT_MIN;
    sum = 0;    // reset sum to 0
    for (int i = mid + 1; i <= high; i++) {
        sum += nums[i];
        if (sum > right_max) {
            right_max = sum;
        }
    }

    // Recursively find the maximum subarray sum for the left
    // and right subarray, and take maximum
    int max_left_right = max(maximum_sum(nums, low, mid),
                             maximum_sum(nums, mid + 1, high));

    // return the maximum of the three
    return max(max_left_right, left_max + right_max);
}

int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    return maximum_sum(nums, 0, n - 1);
}

int main() {
    int size;
    cin >> size;

    vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
    cout << maxSubArray(nums);

    return 0;
}