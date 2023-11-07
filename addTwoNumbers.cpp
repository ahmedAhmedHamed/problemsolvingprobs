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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *solutionHead = new ListNode();
		ListNode *solutionHeadCopy = solutionHead;
		ListNode *tempNode;
		ListNode *l1cpy = l1;
		int value = 0;
		int digit = 0;
		if (!l2)
			return l1;
		if (!l1)
			return l2;
		while (l1 && l2) {
			value = l1->val + l2->val;
			if (value < 10) {
				solutionHeadCopy->next = new ListNode(value);
				solutionHeadCopy = solutionHeadCopy->next;
			}
			else {
				digit = value % 10;
				solutionHeadCopy->next = new ListNode(digit);
				solutionHeadCopy = solutionHeadCopy->next;
				tempNode = l1;
				tempNode = tempNode->next;
				if (!tempNode)
					l1->next = new ListNode(1);
				while (tempNode) {
					if (tempNode->val < 9)
					{
						tempNode->val += 1;
						break;
					}
					tempNode->val = 0;
					if (tempNode->next == nullptr)
					{
						tempNode->next = new ListNode(1);
						break;
					}
					tempNode = tempNode->next;
				}

			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1) {
			solutionHeadCopy->next = l1;
			solutionHeadCopy = solutionHeadCopy->next;
			l1 = l1->next;
		}
		while (l2) {
			solutionHeadCopy->next = l2;
			solutionHeadCopy = solutionHeadCopy->next;
			l2 = l2->next;
		}
		solutionHeadCopy = solutionHead;
		solutionHead = solutionHead->next;
		delete solutionHeadCopy;
		return solutionHead;
	}
};

int main() {
	ListNode x;
	x.val = 2;
	ListNode y;
	y.val = 4;
	ListNode z;
	z.val = 3;

	ListNode xx;
	xx.val = 5;
	ListNode yy;
	yy.val = 6;
	ListNode zz;
	zz.val = 4;
	ListNode xx1;
	xx1.val = 9;

	x.next = &y;
	y.next = &z;

	xx.next = &yy;
	yy.next = &zz;
//	zz.next = &xx1;
	Solution s;
	ListNode *temp = s.addTwoNumbers(&x, &xx);
	cout << 'x';
}
