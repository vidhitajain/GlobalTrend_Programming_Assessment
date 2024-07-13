#include <iostream>
#include <string>
#include <queue>
#include <sstream>

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode *root)
  {
    if (!root)
      return "";

    std::string result;
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      if (node)
      {
        result += std::to_string(node->val) + ",";
        q.push(node->left);
        q.push(node->right);
      }
      else
      {
        result += "null,";
      }
    }

    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(const std::string &data)
  {
    if (data.empty())
      return nullptr;

    std::stringstream ss(data);
    std::string item;
    std::getline(ss, item, ',');
    TreeNode *root = new TreeNode(std::stoi(item));
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();

      if (std::getline(ss, item, ','))
      {
        if (item != "null")
        {
          TreeNode *leftNode = new TreeNode(std::stoi(item));
          node->left = leftNode;
          q.push(leftNode);
        }
      }

      if (std::getline(ss, item, ','))
      {
        if (item != "null")
        {
          TreeNode *rightNode = new TreeNode(std::stoi(item));
          node->right = rightNode;
          q.push(rightNode);
        }
      }
    }

    return root;
  }
};

void printTree(TreeNode *root)
{
  if (!root)
    return;
  std::queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();
    if (node)
    {
      std::cout << node->val << " ";
      q.push(node->left);
      q.push(node->right);
    }
    else
    {
      std::cout << "null ";
    }
  }
  std::cout << std::endl;
}

int main()
{
  Codec codec;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  std::string serialized = codec.serialize(root);
  std::cout << "Serialized tree: " << serialized << std::endl;

  TreeNode *deserialized = codec.deserialize(serialized);
  std::string serializedAgain = codec.serialize(deserialized);
  std::cout << "Serialized tree again: " << serializedAgain << std::endl;

  // Optional: print the deserialized tree to verify structure
  std::cout << "Deserialized tree: ";
  printTree(deserialized);

  return 0;
}
