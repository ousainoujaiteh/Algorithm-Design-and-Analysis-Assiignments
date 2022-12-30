#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int rubbHouse(vector<int> nums)
{
    if (nums.size() == 0)
        return 0;
    if (nums.size() < 2)
        return nums[0];

    int result = max(nums[0], nums[1]);
    int b = nums[0];

    for (int i = 2; i < nums.size(); i++)
    {
        int temp = max(result, b + nums[i]);
        b = result;
        result = temp;
    }

    return result;
}

int main()
{
    int a;
    vector<int> nums;

    string bufferr;
    getline(cin, bufferr);

    for (int i = 0; i < bufferr.length(); i++)
    {
        char my = bufferr[i];

        if (my == ',' || my == '[' || my == ']')
            continue;

        char x = bufferr[i];
        a = x - '0';
        nums.push_back(a);
    }
    cout << rubbHouse(nums);
    return 0;
}
