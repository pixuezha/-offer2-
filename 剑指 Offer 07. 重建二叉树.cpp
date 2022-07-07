#include <iostream>
#include<vector>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* pHead = nullptr;
        if (preorder.empty() || inorder.empty())
            return pHead;
        int i = 0;
        for ( i; i < inorder.size(); i++)
        {
            if (inorder[i] == preorder[0])
                break;
        }
        vector<int> pl(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> pr(preorder.begin() +i + 1, preorder.end());
        vector<int> il(inorder.begin() , inorder.begin() + i );
        vector<int> ir(inorder.begin() + i+1, inorder.end());
        pHead = new TreeNode(preorder[0]);
        pHead->left = buildTree(pl, il);
        pHead->right = buildTree(pr, ir);

        return pHead;
    }
};

int main()
{
    vector<int> preord{ 3,9,20,15,7 };
    vector<int> inorder{ 9,3,15,20,7 };
    Solution s;

    TreeNode* pHead = s.buildTree(preord, inorder);
    while (pHead)
    {
        cout << pHead->val<<endl;
        pHead = pHead->left;
    }
}



