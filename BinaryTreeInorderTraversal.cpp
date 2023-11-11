#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define vi vector<int>
#define v vector


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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> src;
		vector<int> sol;
		if (root == nullptr)
			return sol;
		src = inorderTraversal(root->left);
		vectorAppend(sol, src);
		sol.emplace_back(root->val);
		src = inorderTraversal(root->right);
		vectorAppend(sol, src);
		return sol;
	}
	void vectorAppend(vector<int> &dest, vector<int> &src) {
		for (int &i : src)
			dest.emplace_back(i);
	}
};
int main() {
	TreeNode left(0);
	TreeNode right(1);
	TreeNode root(2, &left, &right);
	vi sol = Solution().inorderTraversal(&root);
	cout << sol[0];
}
