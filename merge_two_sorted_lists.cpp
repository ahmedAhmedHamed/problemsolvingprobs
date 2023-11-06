#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode *listHead = nullptr;
		ListNode *listHeadCopy = nullptr;

		if (list1 == nullptr)
			return (list2);
		if (list2 == nullptr)
			return (list1);

		if (list1->val < list2->val)
		{
			listHead = list1;
			list1 = list1->next;
		}
		else
		{
			listHead = list2;
			list2 = list2->next;
		}
		listHeadCopy = listHead;
		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				listHead->next = list1;
				listHead = listHead->next;
				list1 = list1->next;
			}
			else
			{
				listHead->next = list2;
				listHead = listHead->next;
				list2 = list2->next;
			}
		}

		while (list1)
		{
			listHead->next = list1;
			listHead = listHead->next;
			list1 = list1->next;
		}
		while (list2)
		{
			listHead->next = list2;
			listHead = listHead->next;
			list2 = list2->next;
		}

		return (listHeadCopy);
	}
};

int main(void)
{
	ListNode x;
	x.val = 1;
	ListNode y;
	y.val = 2;
	ListNode z;
	z.val = 3;
	ListNode xx;
	xx.val = 1;
	ListNode yy;
	yy.val = 2;
	ListNode zz;
	zz.val = 3;

	x.next = &y;
	y.next = &z;

	xx.next = &yy;
	yy.next = &zz;
	Solution s;
	ListNode *temp = s.mergeTwoLists(&x, &xx);
	cout << 'x';
}