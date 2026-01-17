/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // STEP 1: Check if we have k nodes remaining
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            if (curr == nullptr) {
                return head;  // BASE CASE: Less than k nodes, return as-is
            }
            curr = curr->next;
        }
        
        // STEP 2: Reverse exactly k nodes
        ListNode* prev = nullptr;
        curr = head;
        
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // At this point:
        // prev = new head (kth node, reversed)
        // curr = (k+1)th node (start of next group)
        // head = original first node, now tail of reversed group
        
        // STEP 3: Recursively solve the rest
        head->next = reverseKGroup(curr, k);
        
        // STEP 4: Return new head
        return prev;
    }
};