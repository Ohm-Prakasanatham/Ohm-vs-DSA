class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> result;

        // Step 1: Extract all values from the linked lists into result[]
        for (auto j : lists) {
            while (j != nullptr) {
                result.push_back(j->val);
                j = j->next;
            }
        }

        // Step 2: Sort the result array
        sort(result.begin(), result.end());

        // Step 3: Create new sorted linked list from result[]
        ListNode dummy(0);
        ListNode* temp = &dummy;

        for (int i : result) {
            temp->next = new ListNode(i);
            temp = temp->next;
        }

        return dummy.next;
    }
};