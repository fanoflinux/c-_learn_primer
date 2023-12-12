#include<iostream>
#include<string>

using std::string;

class TreeNode 
{
	//默认构造函数
	TreeNode() :value(string()),count(new size_t(1)),left(nullptr),right(nullptr) {}
	TreeNode(const TreeNode& rhs)
	{
		this->value = rhs.value;
		this->left = rhs.left;
		this->right = rhs.right;
		this->count = new size_t(*(rhs.count) + 1);
	}
private:
	string value;
	size_t *count;
	TreeNode* left;
	TreeNode* right;
};
