class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Insert first k elements into the heap
        for (int i = 0; i < k; i++) {
            minHeap.push(nums[i]);
        }

        // Process remaining elements
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > minHeap.top()) { 
                minHeap.pop();  // Remove the smallest element
                minHeap.push(nums[i]);  // Insert the new element
            }
        }

        // The root of the heap is the kth largest element
        return minHeap.top();
    }
};
