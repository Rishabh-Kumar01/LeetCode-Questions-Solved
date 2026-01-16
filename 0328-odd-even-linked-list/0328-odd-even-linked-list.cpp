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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd(-1);
        ListNode even(-1);

        ListNode* mover1 = &odd;
        ListNode* mover2 = &even;

        ListNode* mover = head;
        int cnt = 0;

        while(mover != nullptr) {
            cnt += 1;
            if(cnt % 2 == 0) {
                mover2->next = mover;
                mover2 = mover2->next;
            } else {
                mover1->next = mover;
                mover1 = mover1->next;
            }
            mover = mover->next;
        }

        mover1->next = even.next;
        mover2->next = nullptr;

        return odd.next;
    }
};