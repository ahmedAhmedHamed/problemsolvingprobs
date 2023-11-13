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
	TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
		map<int, TreeNode *> treeNodes;
		map<int, TreeNode *> noParentNodes;
		map<int, TreeNode *> hasParentNodes;
		TreeNode *root = nullptr;
		for (vector<int> description: descriptions) {
			int parentValue = description[0];
			int childValue = description[1];
			int isLeft = description[2];
			TreeNode *newChild;

			if (!treeNodes.contains(parentValue))
				treeNodes[parentValue] = new TreeNode(parentValue);

			if (!hasParentNodes.contains(parentValue))
				noParentNodes[parentValue] = treeNodes[parentValue];
			else
				noParentNodes.erase(parentValue);



			if (!treeNodes.contains(childValue))
				newChild = new TreeNode(childValue);
			else
				newChild = treeNodes[childValue];
			treeNodes[childValue] = newChild;
			if (isLeft)
				treeNodes[parentValue]->left = newChild;
			else
				treeNodes[parentValue]->right = newChild;



			hasParentNodes[childValue] = newChild;
			noParentNodes.erase(childValue);
		}

		root = noParentNodes.begin()->second;
		return root;
	}
};

int main() {
	vector<vector<int>> x = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
	Solution().createBinaryTree(x);
}
