#include <iostream>
#include <queue>
using namespace std;
#define MAXN 10

template<class T> struct node{
    T data;
    struct node* child[MAXN];
};

template<class T> class Tree{
    node<T>* root;
public:
    void preorder(node<T> *t){
        int m=MAXN;
        if(t!=nullptr){
            cout << t->data << endl;
            for(int i=0; i<m; ++i)
                preorder(t->child[i]);
        }
    }
    void levorder(node<T>* t, int m){
        node<T>* p;
        queue<node<T>*> q;
        q.push(t);
        while(q.size()){
            p = q.front();
            q.pop();
            cout << p->data << endl;
            for(int i=0; i<m; ++i)
                if(p->child[i]!=nullptr)
                    q.push(p->child[i]);
        }
    }
};