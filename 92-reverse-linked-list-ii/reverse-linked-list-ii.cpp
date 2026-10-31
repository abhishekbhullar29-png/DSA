
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        // Dummy node handles the case when left = 1
        ListNode dummy(0);
        dummy.next = head;

        // Move prev to the node just before left
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Start reversing from left position
        ListNode* curr = prev->next;

        // Reverse nodes between left and right
        for (int i = 0; i < right - left; i++) {
            ListNode* nextNode = curr->next;

            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy.next;
    }
};
