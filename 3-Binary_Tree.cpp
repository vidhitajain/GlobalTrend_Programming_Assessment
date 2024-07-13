#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  int maxPathSum(TreeNode *root)
  {
    int maxSum = INT_MIN;
    maxGain(root, maxSum);
    return maxSum;
  }

private:
  int maxGain(TreeNode *node, int &maxSum)
  {
    if (node == NULL)
    {
      return 0;
    }

    int leftGain = std::max(maxGain(node->left, maxSum), 0);
    int rightGain = std::max(maxGain(node->right, maxSum), 0);

    int currentPathSum = node->val + leftGain + rightGain;
    maxSum = std::max(maxSum, currentPathSum);

    return node->val + std::max(leftGain, rightGain);
  }
};

int main()
{
  TreeNode *root = new TreeNode(-10);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution solution;
  std::cout << "The maximum path sum is: " << solution.maxPathSum(root) << std::endl;

  return 0;
}
