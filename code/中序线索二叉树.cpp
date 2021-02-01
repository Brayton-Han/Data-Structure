#include <iostream>
using namespace std;

template<class T> struct node{
    T data;
    node<T> *lchild, *rchild;
    int ltag, rtag;
};

template<class T> class motbt{
    node<T> head;
public:
    void createInThread(node<T>* t, node<T>*& pre){//t为根
        if(t==nullptr)
            return;
        createInThread(t->lchild, pre);//左子树线索化
        if(t->lchild==nullptr){
            t->lchild = pre;
            if(pre!=nullptr)
                t->ltag = 1;
        }//建立当前结点的前驱线索
        if(pre!=nullptr && pre->rchild==nullptr){
            pre->rchild = t;
            pre->rtag = 1;
        }//建立前驱结点的后继线索
        pre = t;//前驱跟上当前指针
        createInThread(t->rchild, pre);//右子树线索化
    }
    node<T>* pred(node<T>* t){
        if(t->ltag==1 || t->lchild==nullptr)
            return t->lchild;
        t = t->lchild;
        while(t->rtag==0)
            t = t->rchild;
        return t;
    }
    node<T>* succ(node<T>* t){
        if(t->rtag==1 || t->rchild==nullptr)
            return t->rchild;
        t = t->rchild;
        while(t!=nullptr && t->ltag==0)
            t = t->lchild;
        return t;
    }
    node<T>* first(node<T>* t){//t指向根
        node<T>* p=t; 
        while(p!=nullptr && p->ltag==0)
            p = p->lchild;
        return p;
    }
    void midorder(node<T>* head){
        while(head1=nullptr){
            cout << head->data << endl;
            head = succ(head);
        }
    }
    void left_insert(node<T>* p, node<T>* q, node<T>** p_head){
        node<T>* r;
        //p无左孩子，则将q作为p的左孩子
        if(p->ltag==1 || p->lchild==nullptr){
            q->lchild = p->lchild; q->ltag = p->ltag;
            q->rchild = p; q->rtag = 1;
            p->lchild = q; p->ltag = 0;
            if(q->lchild==nullptr)
                *p_head = q;
        }
        //否则，q作为p的原来的前驱的右孩子
        else{
            r = pred(p); 
            q->rchild = r->rchild; q->rtag = r->rtag;
            q->lchild = r; q->ltag = 1;
            r->rchild = q; r->rtag = 0;
        }
    }
    void right_insert(node<T>* p, node<T>* q){
        node<T>* r;
        //p无右孩子，则将q作为p的右孩子
        if(p->rtag==1 || p->rchild==nullptr){
            q->rchild = p->rchild; q->rtag = p->rtag;
            q->lchild = p; q->ltag = 1;
            p->rchild = q; p->rtag = 0;
        }
        //否则，q作为p的后继的左孩子
        else{
            r = succ(p); 
            q->lchild = r->lchild; q->ltag = r->ltag;
            q->rchild = r; q->rtag = 1;
            r->lchild = q; r->ltag = 0;
        }
    }
};