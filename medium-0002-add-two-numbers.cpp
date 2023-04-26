/*
Initialize current node to dummy head of the returning list.
Initialize carry to 000.
Loop through lists l1l1l1 and l2l2l2 until you reach both ends and carry is 000.
Set xxx to node l1l1l1's value. If l1l1l1 has reached the end of l1l1l1, set to 000.
Set yyy to node l2l2l2's value. If l2l2l2 has reached the end of l2l2l2, set to 000.
Set sum=x+y+carrysum = x + y + carrysum=x+y+carry.
Update carry=sum/10carry = sum / 10carry=sum/10.
Create a new node with the digit value of (sum mod 10)(sum \bmod 10)(summod10) and set it to current node's next, then advance current node to next.
Advance both l1l1l1 and l2l2l2.
Return dummy head's next node.
*/


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode{0};
        ListNode* current = dummy;
        int carry = 0;
        while (l1.next != nullptr || l2.next != nullptr || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            current->next = new ListNode{sum % 10};
            current = current->next;
            l1 = l1 ? l1.next ? nullptr;
            l2 = l2 ? l2.next ? nullptr;
        }
        return dummy->next;
    }
};