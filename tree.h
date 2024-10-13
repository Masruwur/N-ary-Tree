#include<vector>
#include<iostream>

using namespace std;

template<typename type>
class TreeNode{
    type val;
    vector<TreeNode*> children;
    TreeNode* parent;

    public:
    TreeNode(){
        parent=nullptr;
    }
    TreeNode(type val){
        this->val = val;
        parent = nullptr;
    }

    TreeNode(type val,TreeNode* parent){
        this->val = val;
        this->parent = parent;
    }

    void addChild(TreeNode* child){
        children.push_back(child);
        child->setParent(this);
    }

    void removeChild(TreeNode* child){
        
        vector<int>::iterator target = find(children.begin(),children.end(),child);

        if(target!=children.end()){
            children.erase(target);
        }

        child->setParent(nullptr);
    }

    bool hasChild(){
        return children.size()>0;
    }

    bool isLeaf(){
        return children.size()==0;
    }

    bool isRoot(){
        return parent==nullptr;
    }

    void setParent(TreeNode* parent){
        this->parent = parent;
    }

    TreeNode* getParent(){
        return parent;
    }

    vector<int>& getChildren(){
        return children;
    }

    int degree(){
        return children.size();
    }

    TreeNode* nthChild(int n){
        if(n<=0 || n>children.size()) return nullptr;

        return children[n-1];
    }

    void setValue(type x){
        val = x;
    }

    type getValue(){
        return val;
    }

    int size(){
        if(isLeaf()) return 1;
        int sum=1;

        for(int i=0;i<children.size();i++){
            sum += children[i]->size();
        }

        return sum; 
    }

    void traverse(){
        cout<<getValue()<<" ";
         
        if(isLeaf()) return;

        for(int i=0;i<children.size();i++){
            children[i]->traverse();
        }

    }

    int height(){
        if(isLeaf()) return 1;

        int maxSubHeight=0;
        for(int i=0;i<children.size();i++){
            maxSubHeight = max(maxSubHeight,children[i]->height());
        }

        return 1 + maxSubHeight;
    }

    

};

template<typename type>
class Tree{
    TreeNode<type>* root;

    public:
    Tree(){
        root = new TreeNode<type>();
    }
    Tree(type val){
        root = new TreeNode<type>(val);
    }
    Tree(TreeNode<type>& node){
        root = &node;
    }
    ~Tree(){
        //pass
    }

    TreeNode<type>* getRoot(){
        return root;
    }


    void addSubtree(TreeNode<type>& subtree,TreeNode<type>& parent){
        parent.addChild(&subtree);
    }

    void addSubtree(TreeNode<type>& subtree){
        root->addChild(&subtree);
    }

    

    void removeSubtree(TreeNode<type>& subtree,TreeNode<type>& parent){
        parent.removeChild(&subtree);
    }

    int size(){
        if(root==nullptr) return 0;
        
        return root->size();
    }

    void traverse(){
        if(root==nullptr) return;

        root->traverse();
    }

    int height(){
        return root->height();
    }


};