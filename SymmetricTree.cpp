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
	bool isSymmetric(TreeNode* root) {
		TreeNode* left;
		TreeNode* right;
		bool check1;
		bool check2;
		if (root == nullptr)
			return true;
		left = root->left;
		right = root->right;
		if (left == nullptr && right == nullptr)
			return true;
		if (left == nullptr && right != nullptr)
			return false;
		if (left != nullptr && right == nullptr)
			return false;
		if (left->val != right->val)
			return false;
		check1 = isSameTree(left->left, right->right);
		check2 = isSameTree(left->right, right->left);
		return check1 && check2;
	}
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
		sameLeft = isSameTree(p->left, q->right);
		sameRight = isSameTree(p->right, q->left);
		if (sameLeft && sameRight)
			return true;
		return false;
	}

};
// [2,3,3,4,5,5,4,null,null,8,9,9,8]
int main() {
	TreeNode left(8);
	TreeNode right(9);
	TreeNode root589(5, &left, &right);
	TreeNode left1(9);
	TreeNode right1(8);
	TreeNode root598(5, &left1, &right1);
	TreeNode left2(4);
	TreeNode root345(3, &left2, &root589);
	TreeNode right3(4);
	TreeNode root354(3, &root598, &right3);
	TreeNode rootroot(2, &root345, &root354);
	bool sol = Solution().isSymmetric(&rootroot);
	cout << sol;
}