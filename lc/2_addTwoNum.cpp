#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	struct node* next;
	int data;
}node;

node* allocateNode(int);

void insertNode(node** head, int data){
	node* t = *head;
	*head = allocateNode(data);
	(*head)->next = t;
}

node* allocateNode(int data){
	node* n = new node;
	n->next = NULL;
	n->data = data;
	return n;
}

void printList(node* head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void addAB(node* headA, node* headB){
	int carry = 0,sum = 0,lsd = 0;
	while( headA && headB ){
		sum = headA->data + headB->data + carry;
		carry = sum / 10;
		lsd = sum % 10;
		headA->data = headB->data = lsd;
		headA = headA->next;
		headB = headB->next;
	}
	if( headA ){
		while( headA ){
			sum = headA->data + carry;
			carry = sum / 10;
			lsd = sum % 10;
			headA->data = lsd;
			headA = headA->next;
		}
	}
	else{
		while( headB){
			sum = headB->data + carry;
			carry = sum / 10;
			lsd = sum % 10;
			headB->data = lsd;
			headB = headB->next;
		}
	}
}

int main(void){
	node* headA = NULL;
	node* headB = NULL;
	insertNode(&headA,3);
        insertNode(&headA,4);
        insertNode(&headA,2);

        insertNode(&headB,4);
        insertNode(&headB,6);
//        insertNode(&headB,5);

	printList(headA);
	printList(headB);
	addAB(headA,headB);
	printList(headA);
	return 0;
}


/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

class Solution {

public:



    ListNode* adjustCarry(int carry){

        ListNode* head = NULL;

        ListNode* last = NULL;

        int sum = 0;

        ListNode* n = NULL;

        while(carry / 10){

            sum = carry % 10;

            n = new ListNode(sum);

            

            if(!last){

                head = last = n;

            }

            else

            {

                last->next = n;

                last = n;

            }

            carry = carry/10;

        }

        if(carry){

            n = new ListNode(carry);

            

            if(!last){

                head = last = n;

            }

            else

            {

                last->next = n;

                last = n;

            }  

        }

        return head;

    }

    

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* headA = l1;

        ListNode* headB = l2;

        ListNode* prevA = NULL;

        ListNode* prevB = NULL;

        

        int carry = 0,sum = 0,lsd = 0;

        while( headA && headB ){

                sum = headA->val + headB->val + carry;

                carry = sum / 10;

                lsd = sum % 10;

                headA->val = headB->val = lsd;

                prevA = headA;

                prevB = headB;

                headA = headA->next;

                headB = headB->next;

        }

        if( headA ){

                while( headA ){

                        sum = headA->val + carry;

                        carry = sum / 10;

                        lsd = sum % 10;

                        headA->val = lsd;

                        prevA = headA;

                        headA = headA->next;

                }

                ListNode* carryList = adjustCarry(carry);

                prevA->next = carryList;

                return l1;

        }

        else if(headB){

                while( headB){

                        sum = headB->val + carry;

                        carry = sum / 10;

                        lsd = sum % 10;

                        headB->val = lsd;

                        prevB = headB;

                        headB = headB->next;

                }

                ListNode* carryList = adjustCarry(carry);

                prevB->next = carryList;

                return l2;

        }

        ListNode* carryList = adjustCarry(carry);

        prevA->next = carryList;

        return l1;

    }

};
