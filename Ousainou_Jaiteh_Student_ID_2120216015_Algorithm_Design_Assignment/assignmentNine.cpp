using namespace std;
int maxAmount(int* arr)
{   
    int n = sizeof(arr) / sizeof(arr[0]);

	if (n == 0)
		return 0;

	int v1 = arr[0];
	if (n == 1)
		return v1;

	int v2 = max(arr[0], arr[1]);
	if (n == 2)
		return v2;
	int max_val;
	for (int i = 2; i < n; i++) {
		max_val = max(arr[i] + v1, v2);
		v1 = v2;
		v2 = max_val;
	}

	return max_val;
}

int rob(vector<int>& A){
    int prev2 = 0, prev = 0m cur =0
    for (int i : A) {
        cur = max(prev, i + prev2);
        prev2 = prev;
        prev = cur;
    }
    return cur;
}

int main()
{
	int arr[] = { 6, 7, 1, 3, 8, 2, 4 };
	// int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxAmount(arr);
	return 0;
}