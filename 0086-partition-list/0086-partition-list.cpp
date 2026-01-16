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
    ListNode* partition(ListNode* head, int x) {
        ListNode head1(-1);
        ListNode head2(-1);

        ListNode* mover1 = &head1;
        ListNode* mover2 = &head2;

        ListNode* mover = head;

        while(mover != nullptr) {
            if(mover->val < x) {
                mover1->next = mover;
                mover1 = mover1->next;
            } else {
                mover2->next = mover;
                mover2 = mover2->next;
            }
            mover = mover->next;
        }

        mover1->next = head2.next;
        mover2->next = nullptr;

        return head1.next;
    }
};