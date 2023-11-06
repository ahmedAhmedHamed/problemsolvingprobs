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
		ListNode *solutionHead;
		long long n1 = 0;
		long long n2 = 0;
		long long sol = 0;
		if (!l2)
			return l1;
		if (!l1)
			return l2;
		n1 = getNumber(l1);
		n2 = getNumber(l2);
		sol = n1 + n2;
		solutionHead = getSolHead(sol);
		return solutionHead;
	}

	ListNode *getSolHead(long long sol) {
		int number;
		ListNode *solutionList = nullptr;
		ListNode *solutionListCopy;
		number = sol % 10;
		solutionList = new ListNode(number);
		solutionListCopy = solutionList;
		sol = sol / 10;
		while (sol != 0) {
			number = sol % 10;
			solutionList->next = new ListNode(number);
			solutionList = solutionList->next;
			sol /= 10;
		}
		return solutionListCopy;
	}

	long long getNumber(ListNode *reversedlistnode) {
		if (!reversedlistnode)
			return 0;
		int digit = 1;
		long long number = 0;
		while (reversedlistnode) {
			number += reversedlistnode->val * digit;
			digit *= 10;
			reversedlistnode = reversedlistnode->next;
		}
		return number;
	}
};

int main() {
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
	ListNode *temp = s.addTwoNumbers(&x, &xx);
	cout << 'x';
}
