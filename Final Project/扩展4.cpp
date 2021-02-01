#include <bits/stdc++.h>
namespace DS{
    struct node{
        int data, num;
        node *front, *next;
        node(){}
        node(const int& val): data(val), num(1), front(nullptr), next(nullptr){}
        node(const int& val, const int& m): data(val), num(m), front(nullptr), next(nullptr){}
    };
    class LinearTable{
    private:
        size_t cnt;
        node *start, *head, *tail;
        int bottom, top;
        std::unordered_map<int, node*>* map;
    public:
        LinearTable(){
            cnt = bottom = 0; top = -1;
            start = new node;
            start->next = head;
            head = tail = nullptr;
            map = new std::unordered_map<int, node*>;
        }

        LinearTable(std::vector<int>::iterator begin, std::vector<int>::iterator end){
            cnt = bottom = 0; top = -1;
            start = new node;
            start->next = head;
            head = tail = nullptr;
            map = new std::unordered_map<int, node*>;
            while(begin!=end)
                push_back(*(begin++));
        }

        LinearTable(std::deque<int>::iterator begin, std::deque<int>::iterator end){
            cnt = bottom = 0; top = -1;
            start = new node;
            start->next = head;
            head = tail = nullptr;
            map = new std::unordered_map<int, node*>;
            while(begin!=end)
                push_back(*(begin++));
        }

        const int front() const {
            if(head == tail)
                std::cerr << "SegmentationFault" << std::endl;
            else
                return head->data;
        }

        const int back() const {
            if(head == tail)
                std::cerr << "SegmentationFault" << std::endl;
            else
                return tail->data;
        }

        void push_front(const int& val){
            cnt++;
            if(cnt==1 || val!=head->data){
                node* n = new node(val);
                if(cnt==1) tail = n;
                head = n;
            }else
                head->num++;
            map->insert({--bottom, head});
        }

        void push_front(int& num, const int& value){
            if(num<=0) return;
            cnt += num;
            if(cnt==num || value!=head->data){
                node* n = new node(value, num);
                if(cnt==num) tail = n;
                head = n;
            }else
                head->num += num;
            while(num--)
                map->insert({--bottom, head});
        }

        void push_back(const int& val){
            cnt++;
            if(cnt==1 || val!=tail->data){
                node* n = new node(val);
                if(cnt==1) head = n;
                tail = n;
            }else
                tail->num++;
            map->insert({++top, tail});
        }

        void push_back(int& num, const int& value){
            if(num<=0) return;
            cnt += num;
            if(cnt==num || value!=tail->data){
                node* n = new node(value, num);
                if(cnt==num) head = n;
                tail = n;
            }else
                tail->num += num;
            while(num--)
                map->insert({++top, tail});
        }

        void pop_front(){
            if(cnt==0) return;
            cnt--;
            if(head->num==1){
                delete[] head;
                if(cnt) 
                    head = (++(map->begin()))->second;
                else
                    head = tail = nullptr;
            }else
                head->num--;
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
            }else
                tail->num--;
            map->erase(top--);
        }

        void pop_back(int& pop_size){
            if(pop_size>=cnt) clear();
            else
                while(pop_size--)
                    pop_back();
        }

        int& operator[](const int& temp){
            if(temp<0 || temp>=cnt){
                std::cerr << "SegmentationFault" << std::endl;
                exit(0);
            }
            node* t = map->find(temp+bottom)->second;
            if(t->num==1)
                return t->data;
            else{
                node* n = new node(t->data);
                map->find(temp+bottom)->second = n;
                if(temp==0) head = n;
                if(temp==cnt-1) tail = n;
                return n->data;
            }
        }
        const int operator[](const int& temp) const {
            if(temp<0 || temp>=cnt){
                std::cerr << "SegmentationFault" << std::endl;
                exit(0);
            }
            return map->find(temp+bottom)->second->data;
        }

        void swap(DS::LinearTable& B){
            std::swap(this->head, B.head); std::swap(this->tail, B.tail);   
            std::swap(this->cnt, B.cnt);   std::swap(this->bottom, B.bottom);
            std::swap(this->top, B.top);   std::swap(this->map, B.map);
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