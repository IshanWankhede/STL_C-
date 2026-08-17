#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();

    for (int value : nums) {
        int freq = 0;

        for (int el : nums) {
            if (el == value) {
                freq++;
            }
        }

        if (freq > n / 2) {
            return value;
        }
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = majorityElement(nums);

    cout << "Majority Element: " << result << endl;

    return 0;
}