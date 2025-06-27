class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Step 1: Sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        // Step 2: Return the k-th largest element (0-based index)
        return nums[k - 1];
    }
};
