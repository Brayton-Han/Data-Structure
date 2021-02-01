#include <bits/stdc++.h>
namespace DS{
    struct node{
        int data;
        node *front, *next;
        node(){}
        node(int val): data(val), front(nullptr), next(nullptr){}
    };
    class LinearTable{
    private:
        size_t cnt;
        node *start, *head, *tail;
        int mark, bottom;
        std::unordered_map<int, node*>* map;
    public:
        LinearTable(){
            cnt = mark = bottom = 0;
            start = new node;
            head = tail = new node;
            start->front = nullptr; start->next = tail;
            tail->front = start; tail->next = nullptr;
            map = new std::unordered_map<int, node*>;
        }

        LinearTable(std::vector<int>::iterator begin, const std::vector<int>::iterator end){
            cnt = mark = bottom = 0;
            start = new node;
            head = tail = new node;
            start->front = nullptr; start->next = tail;
            tail->front = start; tail->next = nullptr;
            map = new std::unordered_map<int, node*>;
            while(begin!=end)
                push_back(*(begin++));
        }

        LinearTable(std::deque<int>::iterator begin, const std::deque<int>::iterator end){
            cnt = mark = bottom = 0;
            start = new node;
            head = tail = new node;
            start->front = nullptr; start->next = tail;
            tail->front = start; tail->next = nullptr;
            map = new std::unordered_map<int, node*>;
            while(begin!=end)
                push_back(*(begin++));
        }

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
                return tail->front->data;
        }

        void push_front(const int& val){
            cnt++;
            node* n = new node(val);
            n->front = start; n->next = head;
            start->next = n; head->front = n;
            head = n;
            map->insert({--bottom, n}); mark++;
        }

        void push_front(int num, const int& value){
            while(num--)
                push_front(value);
        }

        void push_back(const int& val){
            node* n = new node(val);
            if(head == tail)
                head = n;
            n->front = tail->front; n->next = tail;
            tail->front->next = n; tail->front = n;
            map->insert({bottom+(cnt++), n});
        }

        void push_back(int num, const int& value){
            while(num--)
                push_back(value);
        }

        void pop_front(){
            if(head == tail)
                return;
            cnt--;
            map->erase(bottom++); mark--;
            start->next = head->next; head->next->front = start;
            delete[] head;
            head = start->next;
        }

        void pop_front(int pop_size){
            while(pop_size--)
                pop_front();
        }

        void pop_back(){
            if(head == tail)
                return;
            map->erase(bottom+(--cnt));
            tail->front = tail->front->front;
            delete[] tail->front->next;
            tail->front->next = tail;
            if(start->next == tail)
                head = tail; 
        }

        void pop_back(int pop_size){
            while(pop_size--)
                pop_back();
        }

        int& operator[](const int& temp){
            //size_t i = temp;
            //if(i<0 || i>=this->cnt){
            //    std::cerr << "SegmentationFault" << std::endl;
            //    return tail->data;
            //}
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
            std::swap(this->start, B.start); std::swap(this->head, B.head);
            std::swap(this->tail, B.tail);   std::swap(this->cnt, B.cnt);
            std::swap(this->mark, B.mark);   std::swap(this->bottom, B.bottom);
            std::swap(this->map, B.map);
        }

        void clear(){
            while(head!=tail)
                pop_back();
            mark = bottom = 0;
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
