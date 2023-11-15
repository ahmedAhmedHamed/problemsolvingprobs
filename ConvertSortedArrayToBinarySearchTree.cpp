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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return nullptr;
		TreeNode *root = sortedArrayToBSTWithIdx(nums, 0, nums.size());
		return root;
	}

	TreeNode *sortedArrayToBSTWithIdx(vector<int>& nums, int startidx, int endidx) {
		int mid = (startidx + endidx) / 2;
		if (startidx < 0 || startidx == endidx)
			return nullptr;
		TreeNode *root = new TreeNode(nums[mid]);
		root->right = sortedArrayToBSTWithIdx(nums, mid + 1, endidx);
		root->left = sortedArrayToBSTWithIdx(nums, startidx, mid);
		return root;
	}

};

int main() {
	vector<int> nums = {0,1,2,3,4,5};
	TreeNode *tree = Solution().sortedArrayToBST(nums);
	cout << '\n';
}
