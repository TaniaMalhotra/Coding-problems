#include <stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* MakeNode(int data)
{
    node* newNode = new node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
node* insert(node* root, int data)
{
    if(root == NULL)
    root = MakeNode(data);
    else if(data < root->data)
    root->left = insert(root->left, data);
    else
    root->right = insert(root->right, data);
    return root;
}
void bfs(node* root)
{
    queue<node*> visited;
    if(root!=NULL)
    {
        visited.push(root);
        while(!visited.empty())
        {
            node* front = visited.front();
            visited.pop();
            cout<<front->data<<" "<<endl;
            if(front->left) visited.push(front->left);
            if(front->right) visited.push(front->right);
        }
    }
}
void leftView(node* root)
{
    if(root!=NULL)
    {
        queue<node* > visited;
        visited.push(root);
        while(!visited.empty())
        {
            int n = visited.size();
            for(int i = 1;i<=n;i++)
            {
                node* front = visited.front();
                visited.pop();
                if(i==1)
                cout<<front->data<<endl;
                if(front->left) visited.push(front->left);
                if(front->right) visited.push(front->right);
            }
        }
    }
}
void topView(node* root)
{
    if(!root) return;
    queue<pair<node*,int>> q;
    q.push({root,0});
    map<int,int> mm;
    while(!q.empty())
    {
      auto temp = q.front();
      node* front = temp.first;
      int hd = temp.second;
      if(mm.find(hd)==mm.end())
      {
          mm[hd] = front->data;
      }
      q.pop();
      if(front->left) q.push({front->left,hd-1});
      if(front->right) q.push({front->right,hd+1});
    }
    for(auto i : mm)
    {
        cout<<i.second<<endl;
    }
}
int maxDepth(node* root)
{
    if(root==NULL)
    return 0;
    int lsubtree_h = maxDepth(root->left);
    int rsubtree_h = maxDepth(root->right);
    return 1+max(lsubtree_h,rsubtree_h);
    
}
int main()
{
    node* root = NULL;
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,20);
    root = insert(root,25);
    // bfs(root);
    // leftView(root);
    // topView(root);
    cout<<maxDepth(root);
}
