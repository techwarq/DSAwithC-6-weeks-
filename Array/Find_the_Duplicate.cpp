#include <vector>
#include <iostream>
using namespace std;

int findDuplicate(const vector<int>& nums) {
    // Phase 1: Finding the intersection point of the two runners.
    int tortoise = nums[0];
    int hare = nums[0];
    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Phase 2: Finding the entrance to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}

int main() {
    vector<int> nums1 = {1, 3, 4, 2, 2};
    cout << "Duplicate in nums1: " << findDuplicate(nums1) << endl;  // Output: 2

    vector<int> nums2 = {3, 1, 3, 4, 2};
    cout << "Duplicate in nums2: " << findDuplicate(nums2) << endl;  // Output: 3

    vector<int> nums3 = {3, 3, 3, 3, 3};
    cout << "Duplicate in nums3: " << findDuplicate(nums3) << endl;  // Output: 3

    return 0;
}
