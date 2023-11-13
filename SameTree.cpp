#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		bool sameLeft = false;
		bool sameRight = false;
		if (p == nullptr && q == nullptr)
			return true;
		if (p == nullptr && q != nullptr)
			return false;
		if (p != nullptr && q == nullptr)
			return false;
		if (p->val != q->val)
			return false;
		sameLeft = isSameTree(p->left, q->left);
		sameRight = isSameTree(p->right, q->right);
		if (sameLeft && sameRight)
			return true;
		return false;
	}
};


int main() {
	TreeNode left(0);
	TreeNode right(1);
	TreeNode root(2, &left, &right);
	TreeNode left1(0);
	TreeNode right1(1);
	TreeNode root1(2, &left1, &right1);
	bool sol = Solution().isSameTree(&root, &root1);
	cout << sol;
}