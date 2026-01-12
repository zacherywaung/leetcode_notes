// leetcode24     mid


#include<iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        return dfs(head);
    }

    ListNode* dfs(ListNode* head)
    {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* nexthead = dfs(head->next->next);
        ListNode* ret = head->next;
        ret->next = head;
        head->next = nexthead;
        return ret;
    }
};

int main()
{
    ListNode node3 = ListNode(3);
    ListNode node2 = ListNode(2, &node3);
    ListNode node1 = ListNode(1, &node2);
    std::cout << Solution().swapPairs(&node1) << std::endl;

    return 0;
}