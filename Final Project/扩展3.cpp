#include <bits/stdc++.h>
namespace DS{
    struct node{
        int data, num, left, right;
        node *front, *next, *side;
        node(){}
        node(const int& val): data(val), num(1), front(nullptr), next(nullptr), side(nullptr){}
        node(const int& val, const int& num, const int& l, const int& r): 
            data(val), num(num), front(nullptr), next(nullptr), side(nullptr), left(l), right(r){}
    };
    class LinearTable{
    private:
        size_t cnt;
        node *start, *head, *tail;
        int mark, bottom, top;
        std::unordered_map<int, node*>* map;
    public:
        LinearTable(){
            cnt = mark = bottom = top = 0;
            start = new node;
            head = tail = new node;
            start->front = nullptr; start->next = tail;
            tail->front = start; tail->next = nullptr;
            map = new std::unordered_map<int, node*>;
        }

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

        int front(){
            if(cnt==0)
                std::cerr << "SegmentationFault" << std::endl;
            else
                return head->data;
        }

        int back(){
            if(cnt==0)
                std::cerr << "SegmentationFault" << std::endl;
            else
                return tail->front->data;
        }

        void push_front(const int& val){
            cnt++;
            if(head==tail || val!=head->data){
                node* n = new node(val);
                n->front = start; n->next = head;
                start->next = n; head->front = n;
                head = n;
            }else
                head->num++;
            map->insert({--bottom, head}); mark++;
        }

        void push_front(int& num, const int& value){
            if(num<=0) return;
            cnt += num;
            if(head==tail || value!=head->data){
                node* n = new node(value, num, bottom-num, bottom-1);
                n->front = start; n->next = head;
                start->next = n; head->front = n;
                head = n;
            }else
                head->num += num;
            mark += num;
            while(num--)
                map->insert({--bottom, head});
        }

        void push_back(const int& val){
            cnt++;
            if(head==tail || val!=back()){
                node* n = new node(val);
                if(head == tail) head = n;
                n->front = tail->front; n->next = tail;
                tail->front->next = n; tail->front = n;
            }else
                tail->front->num++;
            map->insert({top++, tail->front});
        }

        void push_back(int& num, const int& value){
            if(num<=0) return;
            cnt += num;
            if(head==tail || value!=back()){
                node* n = new node(value, num, top, top+num-1);
                if(head == tail) head = n;
                n->front = tail->front; n->next = tail;
                tail->front->next = n; tail->front = n;
            }else
                tail->front->num += num;
            while(num--)
                map->insert({top++, tail->front});
        }

        void pop_front(){
            if(head == tail) return;
            cnt--;
            if(head->num==1){
                start->next = head->next; head->next->front = start;
                delete[] head;
                head = start->next;
            }else
                head->num--;
            map->erase(bottom++); mark--;
        }

        void pop_front(int& pop_size){
            if(pop_size>=cnt) clear();
            else
                while(pop_size--)
                    pop_front();
        }

        void pop_back(){
            if(head == tail)
                return;
            cnt--;
            if(tail->front->num==1){
                tail->front = tail->front->front;
                delete[] tail->front->next;
                tail->front->next = tail;
                if(start->next == tail) head = tail; 
            }else 
                tail->front->num--;
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
                node* n = new node(t->data);
                map->find(temp+bottom)->second = n;
                return n->data;
            }else{
                if(t->right-(temp+bottom)<=temp+bottom-t->left){
                    node* n = new node(t->data);
                    node* m = new node(t->data, t->right-(temp+bottom), temp+bottom+1, t->right);
                    t->num = temp+bottom - t->left; t->right = temp+bottom-1;
                    int temp = m->left;
                    while(temp<=m->right)
                        map->find(temp++)->second = m;
                }else{
                    node* n = new node(t->data);
                    node* m = new node(t->data, temp+bottom-t->left, t->left, temp+bottom-1);
                    t->num = t->right-(temp+bottom); t->left = temp+bottom+1;
                    int temp = m->left;
                    while(temp<=m->right)
                        map->find(temp++)->second = m;
                }
            }
            return map->find(temp-mark)->second->data;
        }
        const int operator[](const int& temp) const {
            //size_t i = temp;
            //if(i<0 || i>=this->cnt){
            //    std::cerr << "SegmentationFault" << std::endl;
            //    return tail->data;
            //}
            return map->find(temp-mark)->second->data;
        }

        void swap(DS::LinearTable& B){
            std::swap(this->start, B.start);   std::swap(this->head, B.head);
            std::swap(this->tail, B.tail);     std::swap(this->cnt, B.cnt);
            std::swap(this->mark, B.mark);     std::swap(this->bottom, B.bottom);
            std::swap(this->top, B.top); std::swap(this->map, B.map);
        }

        void clear(){
            while(head!=tail)
                pop_back();
            mark = bottom = top = 0;
        }
        
        size_t size() const { return cnt; }

        bool empty(){ return cnt==0; }

        ~LinearTable(){}
    };
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    int n, mark, data, temp;
    DS::LinearTable lt;
    std::cin >> n;
    while(n--){
        std::cin >> mark;
        switch(mark){
            case 1: std::cin >> data; lt.push_front(data); break;
            case 2: std::cin >> data; lt.push_back(data); break;
            case 3: if(lt.size()) lt.pop_front(); break;
            case 4: if(lt.size()) lt.pop_back(); break;
            case 5: std::cin >> data >> temp; if(data>=0 && data<lt.size()) lt[data] += temp; break;
            case 6: std::cin >> data; 
                    if(data>=0 && data<lt.size()) std::cout << lt[data] << std::endl; 
                    else std::cout << "SegmentationFault" << std::endl;
                    break;
            case 7: if(lt.size()) std::cout << lt.front() << std::endl; 
                    else std::cout << "SegmentationFault" << std::endl; 
                    break;
            case 8: if(lt.size()) std::cout << lt.back() << std::endl; 
                    else std::cout << "SegmentationFault" << std::endl;
                    break;
            case 9: std::cout << lt.size() << std::endl; break;
            case 10: lt.clear(); break;
        }
    }
    return 0;
}