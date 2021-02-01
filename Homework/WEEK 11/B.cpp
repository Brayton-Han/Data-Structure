#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n, pre[1005], in[1005], cur, cnt;
unordered_map<int, int> m;

struct Treenode{
    int data;
    Treenode* left;
    Treenode* right;
};

void build(Treenode* t)
{
    int pos = m[pre[cur]];
    t->data = pre[cur];
    in[pos] = 0;
    if(in[pos-1]){
        Treenode* lef = new Treenode;
        cur++; t->left = lef; build(lef);
    }
    else
        t->left = nullptr;
    if(in[pos+1]){
        Treenode* rgt = new Treenode;
        cur++; t->right = rgt; build(rgt);
    }
    else
        t->right = nullptr;
}

void print(Treenode* t)
{
    if(t){
        print(t->left);
        print(t->right);
        cout << t->data;
        if(cnt<n)
            cout << ' ';
        cnt++;
    }
}

int main()
{
    while(cin >> n){
        for(int i=1; i<=n; ++i)
            cin >> pre[i];
        for(int i=1; i<=n; ++i){
            cin >> in[i];
            m[in[i]] = i;
        }
        pre[0] = pre[n+1] = in[0] = in[n+1] = 0;
        cur = cnt = 1;
        Treenode* root = new Treenode;
        build(root);
        print(root);
        cout << endl;
    }
    return 0;
}
