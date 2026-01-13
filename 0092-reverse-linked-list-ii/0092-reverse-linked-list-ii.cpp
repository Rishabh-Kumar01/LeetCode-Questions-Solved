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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* beforeReverse = nullptr;
        ListNode* curr = head;

        int cnt = right - left + 1;

        while(left > 1) {
            beforeReverse = curr;
            curr = curr->next;
            left -= 1;
        }

        ListNode* tailOfReversed = curr;

        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(cnt > 0) {
            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
            cnt -= 1;
        }

        if(beforeReverse != nullptr) {
            beforeReverse->next = prev;
        } else {
            head = prev;
        }
        tailOfReversed->next = next;

        return head;
    }
};