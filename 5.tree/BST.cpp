#include <iostream>
#include <vector>
using namespace std;
class node
{

public:
    int data;
    node *leftchild;
    node *rightchild;
    node(int n) : data(n), leftchild(nullptr), rightchild(nullptr){};
};

/*  inserting element in a BST*/
node *insert(node *t, int key)
{
    if (t == nullptr)
    {
        node *temp = new node(key);
        return temp;
    }
    /*  if the element is already present in the tree 
        node will return its own address
     */
    else if (key < t->data)
    {
        t->leftchild = insert(t->leftchild, key);
    }
    else
    {
        t->rightchild = insert(t->rightchild, key);
    }
    return t;
}

/*take vector array of elements and
  pass each element to the insert function  */
node *BST(vector<int> arr)
{
    int n = arr.size();
    node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}
/*
    In order traversal in a BST will print elements in accessending order
 */
void PrintInorder(node *root)
{
    if (root == nullptr)
        return;
    PrintInorder(root->leftchild);
    cout << root->data << " ";
    PrintInorder(root->rightchild);
}

int main()
{
    vector<int> arr{30, 20, 40, 10, 25, 35, 50};

    node *root = BST(arr);
    //cout << root->leftchild->data;
    PrintInorder(root);
    cout<<endl;
    // insert new data 34
    insert(root, 34);
    PrintInorder(root);

    return 0;
}