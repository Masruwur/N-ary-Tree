#include<iostream>
#include "tree.h"

using namespace std;

int main(){
   Tree<int> t(1);

   TreeNode<int> a(2);

   a.addChild(new TreeNode<int>(4));
   a.addChild(new TreeNode<int>(5));
   a.addChild(new TreeNode<int>(6));

   TreeNode<int> b(3);

   b.addChild(new TreeNode<int>(7));
   b.addChild(new TreeNode<int>(8));
   b.addChild(new TreeNode<int>(9));
   b.addChild(new TreeNode<int>(10));

   // cout<<a.isRoot()<<" "<<b.isRoot()<<endl;

   t.addSubtree(a);
   t.addSubtree(b);

   b.nthChild(2)->addChild(new TreeNode<int>(11));

   // cout<<a.isRoot()<<" "<<b.isRoot()<<endl;

   // cout<<t.size();

   cout<<t.height();


}