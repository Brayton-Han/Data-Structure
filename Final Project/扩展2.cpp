#include <bits/stdc++.h>
namespace DS{
    struct node{
        int data, num, left, right;
        node(){}
        node(const int& val, const int& pos): data(val), num(1), left(pos), right(pos){}
        node(const int& val, const int& m, const int& l, const int& r): data(val), num(m), left(l), right(r){}
    };
    class LinearTable{
    private:
        size_t cnt;
        node *head, *tail;
        int bottom, top;
        std::unordered_map<int, node*>* map;
    public:
        LinearTable(){
            cnt = bottom = 0; top = -1;
            head = tail = nullptr;
            map = new std::unordered_map<int, node*>;
        }
/*
        LinearTable(std::vector<int>::iterator begin, std::vector<int>::iterator end){
            cnt = mark = bottom = top = 0;
            start = new node;
            head = tail = new node;
            start->front = nullptr; start->next = tail;
            tail->front = start; tail->next = nullptr;
            map = new std::unordered_map<int, node*>;
            while(begin!=end)
                push_back(*(begin++));
        }

        LinearTable(std::deque<int>::iterator begin, std::deque<int>::iterator end){
            cnt = mark = bottom = top = 0;
            start = new node;
            head = tail = new node;
            start->front = nullptr; start->next = tail;
            tail->front = start; tail->next = nullptr;
            map = new std::unordered_map<int, node*>;
            while(begin!=end)
                push_back(*(begin++));
        }
*/
        const int front() const {
            //if(head == tail)
            //    std::cerr << "SegmentationFault" << std::endl;
            //else
                return head->data;
        }

        const int back() const {
            // if(head == tail)
            //    std::cerr << "SegmentationFault" << std::endl;
            // else
                return tail->data;
        }

        void push_front(const int& val){
            cnt++;
            if(cnt==1 || val!=head->data){
                node* n = new node(val, bottom-1);
                if(cnt==1) tail = n;
                head = n;
            }else{
                head->num++;
                head->left--;
            }
            map->insert({--bottom, head});
        }

        void push_front(int& num, const int& value){
            if(num<=0) return;
            cnt += num;
            if(cnt==num || value!=head->data){
                node* n = new node(value, num, bottom-num, bottom-1);
                if(cnt==num) tail = n;
                head = n;
            }else{
                head->num += num;
                head->left -= num;
            }
            while(num--)
                map->insert({--bottom, head});
        }

        void push_back(const int& val){
            cnt++;
            if(cnt==1 || val!=tail->data){
                node* n = new node(val, top+1);
                if(cnt==1) head = n;
                tail = n;
            }else{
                tail->num++;
                tail->right++;
            }
            map->insert({++top, tail});
        }

        void push_back(int& num, const int& value){
            if(num<=0) return;
            cnt += num;
            if(cnt==num || value!=tail->data){
                node* n = new node(value, num, top+1, top+num);
                if(cnt==num) head = n;
                tail = n;
            }else{
                tail->num += num;
                tail->right += num;
            }
            while(num--)
                map->insert({++top, tail});
        }

        void pop_front(){
            if(cnt==0) return;
            cnt--;
            if(head->num==1){
                delete[] head;
                if(cnt) 
                    head = map->find(bottom+1)->second;
                else
                    head = tail = nullptr;
            }else{
                head->num--;
                head->left++;
            }
            map->erase(bottom++);
        }

        void pop_front(int& pop_size){
            if(pop_size>=cnt) clear();
            else
                while(pop_size--)
                    pop_front();
        }

        void pop_back(){
            if(cnt==0) return;
            cnt--;
            if(tail->num==1){
                delete[] tail;
                if(cnt)
                    tail = map->find(top-1)->second;
                else
                    head = tail = nullptr;  
            }else{
                tail->num--;
                tail->right--;
            }
            map->erase(top--);
        }

        void pop_back(int& pop_size){
            if(pop_size>=cnt) clear();
            else
                while(pop_size--)
                    pop_back();
        }

        int& operator[](const int& temp){
            //size_t i = temp;
            //if(i<0 || i>=this->cnt){
            //    std::cerr << "SegmentationFault" << std::endl;
            //    return tail->data;
            //}
            node* t = map->find(temp+bottom)->second;
            if(t->num==1)
                return t->data;
            else if(t->left==temp+bottom || t->right==temp+bottom){
                t->num--;
                node* n = new node(t->data, temp+bottom);
                map->find(temp+bottom)->second = n;
                return n->data;
            }else{
                if(t->right-(temp+bottom)<=temp+bottom-t->left){
                    node* n = new node(t->data, temp+bottom);
                    node* m = new node(t->data, t->right-(temp+bottom), temp+bottom+1, t->right);
                    t->num = temp+bottom - t->left; t->right = temp+bottom-1;
                    int temp = m->left;
                    while(temp<=m->right)
                        map->find(temp++)->second = m;
                }else{
                    node* n = new node(t->data, temp+bottom);
                    node* m = new node(t->data, temp+bottom-t->left, t->left, temp+bottom-1);
                    t->num = t->right-(temp+bottom); t->left = temp+bottom+1;
                    int temp = m->left;
                    while(temp<=m->right)
                        map->find(temp++)->second = m;
                }
            }
        }
        const int operator[](const int& temp) const {
            //size_t i = temp;
            //if(i<0 || i>=this->cnt){
            //    std::cerr << "SegmentationFault" << std::endl;
            //    return tail->data;
            //}
            return map->find(temp+bottom)->second->data;
        }

        void swap(DS::LinearTable& B){
            std::swap(this->head, B.head);   std::swap(this->tail, B.tail);   
            std::swap(this->cnt, B.cnt);     std::swap(this->bottom, B.bottom);
            std::swap(this->top, B.top);     std::swap(this->map, B.map);
        }

        void clear(){
            while(cnt)
                pop_back();
            bottom = 0; top = -1;
        }
        
        size_t size() const { return cnt; }

        bool empty(){ return cnt==0; }

        ~LinearTable(){}
    };
}

int main() {
    DS::LinearTable testLinearTable;
    std::cout << (testLinearTable.empty() ? 1 : 0) << std::endl;
    int n;
    std::cin >> n;
    testLinearTable.push_back(n);
    testLinearTable.push_front (2);
    testLinearTable.push_front (3);
    testLinearTable.push_back(4);
    std::cout << testLinearTable.size() << ' ' << testLinearTable.front() << ' ' << testLinearTable.back() << std::endl;
    testLinearTable.pop_back();
    testLinearTable.pop_front();
    std::cout << testLinearTable.size() << ' ' << testLinearTable.front() << ' ' << testLinearTable.back() << std::endl;
    testLinearTable[0] = 5;

    DS::LinearTable testLinearTable2;
    testLinearTable2.push_back(6);
    testLinearTable2.push_front (7);
    testLinearTable2.push_back(8);
    testLinearTable2.push_front (9);
    testLinearTable2[1] = 10;
    std::cout << (testLinearTable2.empty() ? 1 : 0) << std::endl;

    testLinearTable.swap(testLinearTable2);

    int len = testLinearTable.size();
    for (int x = 0; x < len; x++)
        std::cout << testLinearTable[x] << ' ';
    std::cout << std::endl;
    len = testLinearTable2.size();
    for (int x = 0; x < len; x++)
        std::cout << testLinearTable2[x] << ' ';
    std::cout << std::endl;

    return 0;
}
