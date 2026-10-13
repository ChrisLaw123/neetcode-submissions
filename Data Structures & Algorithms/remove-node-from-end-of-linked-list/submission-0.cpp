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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* fast = head;
        int steps{};
        if (head == nullptr) return head;
        //we want a fast pointer which is n nodes ahead of curr. when fast = nullptr, remove the curr
        while (fast != nullptr) {
            if (steps != n) {
                fast = fast->next;
                steps++;
            } else  {
                prev = curr;
                curr = curr->next;
                fast = fast->next;
            }
        }
        if (prev == nullptr) {
            head = curr->next;
        } else {
            prev->next = curr->next;
        }
        
        
        return head;
    }
};
