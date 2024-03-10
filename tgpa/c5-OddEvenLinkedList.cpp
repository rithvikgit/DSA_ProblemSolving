// Odd Even Linked List
// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the head of the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.

// Input Format:
// first line consists of single integer n(size of the linked list) second line consists of n single space integers (elements of the list)

// Output Format:
// Return the head of the Final Linked list.

// Example:
// Input:
// ''' 5
// 1 2 3 4 5
// ''' Output:
// ''' 1 3 5 2 4 '''

// Constraints:
// 0<n<10000
// -10^6 <= Node.val <= 10^6


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) { 
        if(head==NULL||head->next==NULL){
            return head;
        }

        ListNode* ODD = head;
        ListNode* EVEN = head->next;

        ListNode* evenStart = head->next;

        while(EVEN != NULL && EVEN->next != NULL){
            ODD->next =  EVEN->next;
            EVEN->next = EVEN->next->next;

            ODD = ODD->next;
            EVEN = EVEN->next;
        }

        ODD->next = evenStart;

        return head;

 }
};