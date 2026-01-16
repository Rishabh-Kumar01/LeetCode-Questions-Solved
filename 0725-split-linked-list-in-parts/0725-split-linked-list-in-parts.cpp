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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* mover = head;
        int n = 0;

        while (mover != nullptr) {
            n += 1;
            mover = mover->next;
        }

        int div = n / k;
        int modulo = n % k;

        ListNode* mover2 = head;
        vector<ListNode*> ans(k, nullptr);
        int idx = 0;

        while (mover2 != nullptr) {
            int cnt = div;
            if (modulo > 0) {
                cnt += 1;
                modulo--;
            }
                

            ListNode sub(-1);
            ListNode* temp = &sub;

            while (cnt > 1) {
                temp->next = mover2;
                temp = temp->next;
                mover2 = mover2->next;
                cnt--;
            }

            temp->next = mover2;
            temp = temp->next;
            mover2 = mover2->next;

            temp->next = nullptr;

            ans[idx] = sub.next;
            idx++;
        }

        return ans;
    }
};