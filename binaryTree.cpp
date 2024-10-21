#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class BTNode
{ public:
  int data;
  BTNode* left;
  BTNode* right;

  BTNode(int data)
  {
    this->data=data;
    this->left=NULL;
    this->right=NULL;
  }
  ~BTNode()
  {
    delete left;
    delete right;
  }

};

void print(BTNode* root)
{
    if(root==NULL)
    {
        return ;
    }
    cout<<root->data<<":";
    if(root->left)
    {
        cout<<"Left->"<<root->left->data<<" ";
    }
    if(root->right)
    {
        cout<<"Right->"<<root->right->data<<" ";
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}

BTNode* takeInputLevelWise()
{
  cout<<"Enter root data: ";
  int data;
  cin>>data;
  BTNode* root= new BTNode(data);
  queue<BTNode*> q;
  q.push(root);
  while(!q.empty())
  {
    BTNode* front=q.front();
    q.pop();
    cout<<"Enter left child of "<<front->data<<endl;
    int leftData;
    cin>>leftData;
    if(leftData!=-1)
    {
      BTNode* leftChild=new BTNode(leftData);
      q.push(leftChild);
      front->left=leftChild;
    }
    cout<<"Enter right child of "<<front->data<<endl;
    int rightData;
    cin>>rightData;
    if(rightData!=-1)
    {
      BTNode* rightChild=new BTNode(rightData);
      q.push(rightChild);
      front->right=rightChild;
    }

  }
  return root;
}

void printLevelWise(BTNode* root)
{
  
  queue<BTNode*> q;
  q.push(root);
  while(!q.empty())
  {
    BTNode* front=q.front();
    q.pop();
    cout<<front->data<<":";
    if(front->left)
    {
      cout<<"left->"<<front->left->data<<" ";
      q.push(front->left);
    }
    if(front->right)
    {
      cout<<"right->"<<front->right->data<<" ";
      q.push(front->right);
    }
    cout<<endl;
  }
}

int countNode(BTNode* root)
{
  if(root==NULL)
  {
    return 0;
  }
  int ans=0;
  if(root->left)
  {
    ans+=countNode(root->left);
  }
  if(root->right)
  {
    ans+=countNode(root->right);
  }
  return ans+1;
}

int countLeafNode(BTNode* root)
{
  if(root==NULL)
  {
    return 0 ;
  }
  int ans=0;
  if(root->left==NULL && root->right==NULL)
  {
    ans++;
    return ans;

  }
   return countLeafNode(root->left)+countLeafNode(root->right);
 
}

int minValue(BTNode* root)
{
  if(root==NULL)
  {
    return INT_MAX;
  }
  int minVal=root->data;
  int leftMin=minValue(root->left);
  int rightMin=minValue(root->right);
 return  min(minVal,min(leftMin,rightMin));
}


int maxValue(BTNode* root)
{
  if(root==NULL)
  {
    return INT_MIN;
  }
  int maxVal=root->data;
  int leftMax=minValue(root->left);
  int rightMax=minValue(root->right);
 return  max(maxVal,max(leftMax,rightMax));
}


int height(BTNode* root)
{
  if(root==NULL)
  {
    return 0;
  }
  int ans=0;
  int leftheight=height(root->left);
  int rightheight=height(root->right);
  return max(leftheight,rightheight)+1;
}


void printPreOrder(BTNode* root)
{
  if(root==NULL)
  {
    return; 
  }
  cout<<root->data<<" ";
  printPreOrder(root->left);
  printPreOrder(root->right);
}


void printPostOrder(BTNode* root)
{
  if(root==NULL)
  {
    return; 
  }
  printPostOrder(root->left);
  printPostOrder(root->right);
  cout<<root->data<<" ";

}

void inOrderPrint(BTNode* root)
{
  if(root==NULL)
  {
    return; 
  }
  printPostOrder(root->left);
    cout<<root->data<<" ";
     printPostOrder(root->right);


}


int main()
{
   BTNode* root= takeInputLevelWise();
   cout<<endl;
   printLevelWise(root);
   cout<<endl;
   cout<<"\nMax element in the tree is: "<<maxValue(root)<<endl;
   cout<<"\nMin element in the tree is: "<<minValue(root)<<endl;
   cout<<"\nTotal Nodes in the tree is: "<<countNode(root)<<endl;
   cout<<"\nTotal leaf node in the tree is: "<<countLeafNode(root)<<endl;
   cout<<"\nHeight of the tree is: "<<height(root)<<endl;
   cout<<"\npre order traversal of tree is: ";
   printPreOrder(root);
   cout<<endl;
   cout<<"\npost order traversal of tree is: ";
   printPostOrder(root);
   cout<<endl;
   cout<<"\nin order traversal of tree is: ";
   inOrderPrint(root);
   cout<<endl;

   return 0;


}