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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = nullptr;
        ListNode* l4 = nullptr;
        ListNode* l5 = nullptr;
        int carry = 0, value;
        while (l1 != nullptr || l2 != nullptr || carry) {
            value = carry;
            if (l1 != nullptr) {
                value += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                value += l2->val;
                l2 = l2->next;
            }
            carry = value / 10;
            value = value % 10;
            l4 = new ListNode(value);
            if (l5 == nullptr)
                l3 = l5 = l4;
            else {
                l5->next = l4;
                l5 = l5->next;
            }
        }
        return l3;
    }
};