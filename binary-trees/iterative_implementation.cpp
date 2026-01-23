#include <iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val=value;
        left=right=NULL;
    }
};
#include<stack>
void inorder(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while(curr!=NULL||!st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->val<<" ";
        curr=curr->right;
    }

}