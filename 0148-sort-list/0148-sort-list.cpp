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
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // ← Important: start fast at head->next

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // slow is at middle
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2; // Attach remaining

        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || head->next == nullptr) return head;

        ListNode* mid = getMid(head);

        ListNode* right = mid->next;
        mid->next = nullptr;

        ListNode *left = sortList(head);
        right = sortList(right);

        return merge(left, right);
    }
};