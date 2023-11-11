
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *headCopy = head;
		int currentValue;
		while (headCopy != nullptr) {
			currentValue = headCopy->val;
			if (headCopy->next == nullptr)
				break;
			if (currentValue == headCopy->next->val)
				headCopy->next = headCopy->next->next;
			else
				headCopy = headCopy->next;
		}
		return head;
	}
};


int main(void)
{
	ListNode x;
	x.val = 1;
	ListNode y;
	y.val = 1;
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
	ListNode *temp = s.deleteDuplicates(&x);
	Solution e;
}