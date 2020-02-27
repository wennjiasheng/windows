#include<iostream>

using namespace std;


 class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 
 class Solution {
 public:
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 ListNode *l;
		 l = l1;
		 l1->val += l2->val;
		 int flag = l1->val / 10;
		 l1->val = l1->val % 10;
		 while (l1->next != nullptr  && l2->next != nullptr)
		 {
			 l1 = l1->next;
			 l2 = l2->next;
			 l1->val += l2->val + flag;
			 flag = l1->val / 10;
			 l1->val = l1->val % 10;
		 }
		 //l2 = nullptr
		 while (l1->next != nullptr)
		 {
			 l1 = l1->next;
			 l1->val += flag;
			 flag = l1->val / 10;
			 l1->val %= 10;
		 }
		 while (l2->next != nullptr)
		 {
			 l2 = l2->next;
			 l1->next = new ListNode(flag + l2->val);
			 l1 = l1->next;
			 l1->val %= 10;
			 flag = (flag + l2->val) / 10;
		 }
		 if (flag > 0)
		 {
			 l1->next = new ListNode(1);
		 }
		 return l;
	 }
 };