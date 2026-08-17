class Solution {
public:

    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > pq;

        // Put the first node of each non-empty list into the heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            // Get the smallest node
            ListNode* node = pq.top();
            pq.pop();

            // Add node to result
            tail->next = node;
            tail = tail->next;

            // Add next node from the same list
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy->next;
    }
};