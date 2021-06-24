// Problem Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
	int ans = 0;
	int zigZag(TreeNode* root, bool left){
		if(!root) return - 1;
		
		int l = zigZag(root->left, false);
		int r = zigZag(root->right, true);
		
		ans = max(ans, max(l + 1, r + 1));
		
		if(left){
			return l + 1; 
		} else {
			return r + 1;
		}
	}
	int longestZigZag(TreeNode* root) {
		zigZag(root, true); zigZag(root, false);
		return ans;
	}
};