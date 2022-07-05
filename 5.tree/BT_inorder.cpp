/* 
Implement a binary tree 
build tree :  Preorder order traversal
Print tree :  In order traversal
*/
#include<iostream>
#include<queue>
using namespace std;
class node
{
private:
public:
    int data;
    node *left;
    node *right;
    node(int n) : data(n), left(nullptr), right(nullptr){};
    
};

// tree building
node* build(int arr[],int size,int i)
{
    if(arr[i]==-1|| i > size -3)
        return nullptr;
    node *root= new node(arr[i]);
    root->left=build(arr,size,2*i+1);
    root->right=build(arr,size,2*i+2);
    return root;
}

/*
In order order traversal
*/
void Print_inorder(node *root)
{
        if(root==nullptr)return;
            Print_inorder(root->left);
        cout << root->data<<" ";
            Print_inorder(root->right);
}

int main()
{
    int arr[]={1,2,3,4,5,-1,-1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i=0;
    node* root=build(arr,size,i);
    cout<<"pre order traversal ";
    Print_inorder(root);


    return 0;
}