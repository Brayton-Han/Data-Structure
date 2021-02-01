#include <iostream>
#include <stack>
using namespace std;
#define MAXN 10

template<class T> struct TreeNode{
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

template<class T> class Binary_Tree{
    TreeNode* root;
public:
    void preorder(TreeNode<T>* t){
        if(t!=nullptr){
            cout << t->data << endl;
            for(t=t->left; t!=nullptr; t=t->right)
                preorder(t);
        }
    }
    void postorder(TreeNode<T>* t){
        if(t!=nullptr){
            for(t=t->left; t!=nullptr; t=t->right)
                postorder(t);
            cout << t->data << endl;
        }
    }
    void InOrder(TreeNode<T>* subTree){
        if(subTree!=nullptr) {
            InOrder(subTree->left);
            cout << subTree->data << endl;
            InOrder(subTree->right);
        }
        cout << subTree->data << endl;
    }       
    void Destroy(TreeNode<T>* subTree){
        if(subTree!=NULL){
            Destroy(subTree->leftChild);
            Destroy(subTree->rightChild);
            delete subTree;
        }
    }
    void CreateBinTree(istream& in, TreeNode<char>*& BT){
        stack<TreeNode<char>*> s;
        TreeNode<char> *p, *t;
        int k; char ch;
        BT = nullptr;
        in >> ch;
        while(ch!=EOF){
            switch(ch){
                case '(': s.push(p); k=1; break;
                case ')': s.pop(t); break;
                case ',': k=2; break;
                default: p = new TreeNode(ch);
                         if(BT==nullptr)
                            BT = p;
                         else if(k==1){
                             t = s.top();
                             t->left = p;
                         }
                         else{
                             t = s.top();
                             t->right = p;
                         }
            }
            in >> ch;
        }
    }
};