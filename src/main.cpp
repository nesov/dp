// 2. Add Two Numbers

#include <iostream>
#include <string>
#include <cassert>



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

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* list) {
	ListNode* temp = list;
	while (temp){
		std::cout << temp -> val << std::endl;
		temp = temp -> next;
	}
}
	
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode res (0);
		ListNode *tail = &res; 
		int temp {0};

		while (l1 || l2 || temp){
			int sum = temp;
		
			if(l1){
				sum+=l1-> val; 
				l1 = l1 -> next;
			}
			if (l2){
				sum+=l2-> val; 
				l2 = l2 -> next;
			}
	
			temp = sum / 10;
			tail -> next = new ListNode(sum % 10);
			tail = tail->next;
		}
        return res.next;
}


int main(){
	
	ListNode* l1 =  new ListNode(2);
	l1 ->next = new ListNode(4);
	l1 ->next ->next = new ListNode(3);

	// print(l1);

	ListNode* l2 =  new ListNode(5);
	l2 ->next = new ListNode(6);
	l2 ->next ->next = new ListNode(4);
	// print(l2);


	ListNode* l3 = addTwoNumbers(l1, l2);
	print(l3);
	


	return 0;
}
