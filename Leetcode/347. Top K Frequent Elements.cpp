class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Max heap: {frequency, number}
        priority_queue<pair<int, int>> pq;

        for (auto& [num, count] : freq) {
            pq.push({count, num});
        }

        vector<int> ans;

        // Take k most frequent elements
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
