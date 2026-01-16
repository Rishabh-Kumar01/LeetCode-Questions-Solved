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
    ListNode* reverseLL(ListNode* head) {

        if(head == nullptr) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* mover1 = reverseLL(l1);
        ListNode* mover2 = reverseLL(l2);

        int carryOn = 0;

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(mover1 != nullptr || mover2 != nullptr || carryOn) {
            int totalSum = carryOn;

            if(mover1 != nullptr) {
                totalSum += mover1->val;
                mover1 = mover1->next;
            }

            if(mover2 != nullptr) {
                totalSum += mover2->val;
                mover2 = mover2->next;
            }

            carryOn = totalSum / 10;
            
            ListNode* newNode = new ListNode(totalSum % 10);
            tail->next = newNode;
            tail = tail->next;
        }

        return reverseLL(dummy.next);
    }
};