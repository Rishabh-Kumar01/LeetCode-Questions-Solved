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
    ListNode* mergeHelper(vector<ListNode*>& lists, int left, int right) {
        if(left == right) return lists[left];
        // if(left > right) return nullptr;

        int mid = left + (right - left)/2;

        ListNode* l1 = mergeHelper(lists, left, mid);
        ListNode* l2= mergeHelper(lists, mid+1, right);

        return mergeTwoList(l1, l2);
    }
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoList(l1, l2->next);
            return l2;
        }


    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        return mergeHelper(lists, 0, lists.size() - 1);
    }
};