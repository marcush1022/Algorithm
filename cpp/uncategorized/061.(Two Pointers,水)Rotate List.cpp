/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

class Solution {
public:
	int getLength(ListNode *head)
	{
	    if(head==NULL)
	        return 0;
		ListNode *p=head;
		int len=0;
		while(p)
		{
			p=p->next;
			len++;
		}
		cout<<len;
		return len;
	}
	
    	ListNode* rotateRight(ListNode* head, int k) {
		
		int len=getLength(head);
		if(len==0 || k==0 ||len==1)
		    return head;
		int rotate=k%len;
		if(rotate==0)
		    return head;
		
		ListNode *left=head, *right=head;
		ListNode *newHead;
		for(int i=0;i<rotate; i++)
			right=right->next;
		
		while(right->next)
		{
			left=left->next;
			right=right->next;
		}
		
		newHead=left->next;
		left->next=NULL;
		right->next=head;
		
		return newHead;
    }
};










