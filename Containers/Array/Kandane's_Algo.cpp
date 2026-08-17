#include <iostream>
#include <vector>
#include <climits>  
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int val : nums) {
        currSum += val;
        maxSum = max(maxSum, currSum);

        if (currSum < 0) {
            currSum = 0; 
        }
    }
    return maxSum;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxSubArray(nums);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
