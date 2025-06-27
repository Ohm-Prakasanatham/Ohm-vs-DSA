class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap storing pairs {value, ListNode*}
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;

        // Insert the head of each linked list into the Min-Heap
        for (ListNode* i : lists) {
            if (i) {
                minHeap.push({i->val, i});
            }
        }

        // Create a dummy node and use temp pointer for tracking
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;  // temp will move along the new list

        // Process the heap
        while (!minHeap.empty()) {
            // Extract the smallest element from the heap
            auto [val, j] = minHeap.top();
            minHeap.pop();

            // Attach it to the merged list
            temp->next = j;
            temp = temp->next; // Move temp forward

            // Insert the next node of the extracted element into the heap
            if (j->next) {
                minHeap.push({j->next->val, j->next});
            }
        }

        // Return the merged list starting from dummy->next
        return dummy->next;
    }
};
