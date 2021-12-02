#include<iostream>

using namespace std;

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
        int sum = 0;
        ListNode* cur = new ListNode();
        ListNode* result = cur;
        
        while(l1 != nullptr || l2 != nullptr) {
            if(l1 != nullptr) {
                sum+= l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                sum+= l2->val;
                l2 = l2->next;
            }
            
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            
            if(sum > 9) {
                sum = 1;
            } else {
                sum = 0;
            }
        }
        if(sum != 0) {
            cur->next = new ListNode(sum);
        }
        
        result = result->next;
        
        return result;
    
    }      
};

int main()
{



    return 0;
}