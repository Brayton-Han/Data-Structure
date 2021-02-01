# 数据结构PJ
### By：陈俊含 19307130180
## 一、心路历程
1.从一开始就没有想过用树状结构，因为误以为线性表只有数组、向量、链表这种，再加上pdf中提到“简易的deque”，更加坚定了选择普通双向链表的决心，后来才意识到在某些操作中的不方便，但已经来不及了。

2.最开始只用了一个自己写的链表和stl的map库组成了这一数据结构，至于为什么有了map还要连接各节点，有两个考虑：
- 方便查询头尾元素，且弹出首位元素时方便更新head和tail指针（后因其他功能的实现，更新head和tail时没有采用此法）
- 方便clear()函数的实现，这样的话可以不用逐一从map查找再delete，而是可以从start开始一次性删除节点，map直接用clear()函数清空，其他指标重置即可

3.在初稿实现之后，测试情况很客观，plus测试基本稳定在5.1s，直到遇到了batch测试，我开始思考优化的方式：
- 每个节点增加成员num，记录该节点被几个元素共享
- 每次在头/尾添加元素时，判断目标元素与头部/尾部的元素是否相同，相同的话直接增加num，不另外new新节点
- 当需要使用操作符[]修改某结点的值时，new一个新节点，赋予目标位置相同的值，将其插入tail后面，更新map，返回左值

4.事实证明，这次优化后效率反而降低，原因如下：
- 效率提高的操作：push系列, clear()
- 效率降低的操作：pop系列，operator[]
- 效率降低的程度大于效率提高的程度
- 最折损效率的地方：不能通过head->next/tail->front操作更新head/tail，使用了map的find操作，每次更新操作的复杂度从O(1)变为O(log2n)
- 对于使用[]操作较少的情况，此优化应该是能够提高性能的

5.其实这其中还写过2个版本(node添加left, right变量；直接抛掉链表只用map；)，框架大体一致，但始终无法实现insert，因为一旦插入就必须更新一遍map，我也想过在node中再加一个side指针来解决，但还是不了了之，这让我真正领略了树的优点
***

## 二、功能分析
1.node节点设计
```
struct node{
        int data, num;
        node *front, *next;
        node(){}
        node(int val): data(val), num(1), front(nullptr), next(nullptr){}
        node(int val, int m): data(val), num(m), front(nullptr), next(nullptr){}
    };
```
- 此部分没有什么要解释的

2.LinearTable的私有成员（数据）
```
private:
        size_t cnt;
        node *start, *head, *tail, *work;
        int bottom, top;
        std::map<int, node*>* map;
```
- cnt记录当前表中的数据个数
- start永远不变，作为头结点
- tail就指向尾元素，不是尾元素的下一位
- work指针用来打杂，后续一些函数中需要用到，设置它是为了少new指针
- bottom记录表头键值，top记录表尾键值，在表头加元素时bottom-1，表尾加元素top+1

3.构造函数
```
LinearTable(){
        cnt = bottom = 0; top = -1;
        start = new node;
        head = tail = nullptr;
        start->front = nullptr; start->next = tail;
        map = new std::map<int, node*>;
}
LinearTable(std::vector<int>::iterator begin, std::vector<int>::iterator end){
        cnt = bottom = 0; top = -1;
        start = new node;
        head = tail = nullptr;
        start->front = nullptr; start->next = tail;
        map = new std::map<int, node*>;
        while(begin!=end)
            push_back(*(begin++));
}
LinearTable(std::deque<int>::iterator begin, std::deque<int>::iterator end){
        cnt = bottom = 0; top = -1;
        start = new node;
        head = tail = nullptr;
        start->front = nullptr; start->next = tail;
        map = new std::map<int, node*>;
        while(begin!=end)
            push_back(*(begin++));
}
```
- 第一个函数为默认构造函数，start新建一个节点，连接好start、head、tail，开辟一个map，初始化cnt、bottom、top
- 第二、三个函数是扩展操作，由vector和deque的迭代器构造，只需根据默认构造函数构造后再逐一把元素添加进去即可

4.front() && back()
```
const int front() const {
        if(cnt==0)
            std::cerr << "SegmentationFault" << std::endl, exit(0);
        else
            return head->data;
}
const int back() const {
        if(cnt==0)
            std::cerr << "SegmentationFault" << std::endl, exit(0);
        else
            return tail->data;
}
```
- 由于是单纯调用头/尾元素，所以不允许修改，故设置成const函数
- 对于空表的情况，输出“SegmentationFault”， 并正常结束程序

5.push_front函数
```
void push_front(const int& val){              //防止val被修改且避免复制val
        cnt++;
        if(cnt==1){                              //表空
            node* n = new node(val);
            n->front = start; start->next = n;
            head = tail = n;                     //tail也要更新
        }else if(val!=head->data){               //要插入的值跟首元素不同
            node* n = new node(val);
            n->front = start; n->next = head;
            start->next = n; head->front = n;
            head = n;
        }else                                    //要插入的值等于首元素
            head->num++;
        map->insert({--bottom, head});           //更新map，从-1开始
}
void push_front(int num, const int& value){   //num将会需要修改，故复制不引用，否则效率变低
        if(num<=0) return;                       //排除异常情况
        cnt += num;
        if(cnt==num){                            //表空
            node* n = new node(value, num);
            n->front = start; start->next = n;
            head = tail = n;
        }else if(value!=head->data){             //要插入的值跟首元素不同
            node* n = new node(value, num);
            n->front = start; n->next = head;
            start->next = n; head->front = n;
            head = n;
        }else                                    //要插入的值等于首元素
            head->num += num;
        while(num--)                             //更新map
            map->insert({--bottom, head});
}
```
- 见注释

6.push_back函数
```
void push_back(const int& val){
        cnt++;
        if(cnt==1){                                  //表空
            node* n = new node(val);
            n->front = start; start->next = n;
            head = tail = n;
        }else if(val!=tail->data){                   //val跟尾元素不同
            node* n = new node(val);
            n->front = tail; n->next = tail->next;
            tail->next = n;
            if(n->next) n->next->front = n;          //此处特别小心，因为tail后面可能没有因[]操作添加的节点，故需要特判
            tail = n;                                //更新tail
        }else                                        //val==尾元素
            tail->num++;
        map->insert({++top, tail});                  //更新map
}
void push_back(int num, const int& value){
        if(num<=0) return;                           //排除异常情况
        cnt += num;
        if(cnt==num){                                //表空
            node* n = new node(value, num);
            n->front = start; start->next = n;
            head = tail = n;
        }else if(value!=tail->data){
            node* n = new node(value, num);
            n->front = tail; n->next = tail->next;
            tail->next = n;
            if(n->next) n->next->front = n;
            tail = n;
        }else
            tail->num += num;
        while(num--)
            map->insert({++top, tail});
}
```
- 见注释

7.pop_front函数
```
void pop_front(){
        if(cnt==0) return;                                       //表空
        cnt--;
        if(head->num==1)                                         //节点自由
            if(start->next!=head){                               //head指向了被[]操作过的元素，所以不在start后面
                head->front->next = head->next;
                if(head->next) head->next->front = head->front;  //注意特判
                delete[] head;
                head = map->find(bottom+1)->second;              //更新head
            }else{                                               //head就在表头，直接删除
                start->next = head->next;
                if(head->next) head->next->front = start;
                delete[] head;
                head = map->find(bottom+1)->second;              //仍然不能保证下一个head就在head之后，因为可能被[]操作过，所以无奈只能用find
                if(head==nullptr) tail = nullptr;                //表空，更新tail
            }
        else{                                                    //节点不自由
            head->num--;
            head = map->find(bottom+1)->second;                  //更新head，同上不能直接更新为head->next
        }
        map->erase(bottom++);                                    //更新map
}
void pop_front(int pop_size){
        if(pop_size>=cnt) clear();
        else
            while(pop_size--)
                pop_front();
}
```
- 见注释

8.pop_back函数
```
void pop_back(){
        if(cnt==0) return;                                       //表空
        cnt--;
        if(tail->num==1)                                         //节点自由
            if(cnt==0){                                          //还剩最后一个元素
                delete[] tail;                                   //直接删掉
                start->next = head = tail = nullptr;             //初始化
            }else{                                               //还剩不止一个节点
                tail->front->next = tail->next;
                if(tail->next) tail->next->front = tail->front;
                delete[] tail;
                tail = map->find(top-1)->second;                 //更新tail
            }
        else{                                                    //节点不自由
            tail->num--;
            tail = map->find(top-1)->second;                     //更新tail
        }
        map->erase(top--);                                       //更新map
}
void pop_back(int pop_size){
        if(pop_size>=cnt) clear();
        else
            while(pop_size--)
                pop_back();
}
```
- 见注释

9.恶心的operator[]
```
int& operator[](const int& temp){                         //可以修改元素的[]操作函数，返回值为引用
        if(temp<0 || temp>=cnt){                             //索引不合法
            std::cerr << "SegmentationFault" << std::endl;
            exit(0);
        }
        work = map->find(temp+bottom)->second;               //记录目标节点
        if(work->num==1)                                     //节点自由则直接返回左值引用
            return work->data;
        else{                                                //节点不自由，需要重新new节点
            work->num--;                                     //容易忽略，要更新
            node* n = new node(work->data);
            map->find(temp+bottom)->second = n;              //更新map
            if(temp==0){                                     //引用的是头元素，直接在插入start后
                n->front = start; n->next = head;
                start->next = n; head->front = n;
                head = n;                                    //更新head
            }else{                                           //引用的是非头元素，插入tail后面
                n->front = tail; n->next = tail->next;
                tail->next = n;
                if(n->next) n->next->front = n;              //注意特判
                if(temp==cnt-1) tail = n;                    //如果引用的是尾元素，则更新tail
            }
            return n->data;                                  //返回新节点左值引用
        }
}
const int operator[](const int& temp) const {             //此函数用于单纯的访问节点，不修改，故使用const标识符
        if(temp<0 || temp>=cnt){                             //索引不合法
            std::cerr << "SegmentationFault" << std::endl;
            exit(0);
        }
        return map->find(temp+bottom)->second->data;         //直接返回目标结点的左值引用
}
```
- 见注释

10.swap函数
```
void swap(DS::LinearTable& B){
        std::swap(this->start, B.start);   std::swap(this->head, B.head);
        std::swap(this->tail, B.tail);     std::swap(this->cnt, B.cnt);
        std::swap(this->bottom, B.bottom); std::swap(this->top, B.top);
        std::swap(this->map, B.map);
}
```
- 简单的调用stl库的swap函数交换即可，速度还是很快的

11.clear函数
```
void clear(){
        if(start->next==nullptr) return;     //本来表就是空的，不作任何操作
        work = start->next;                  //工作指针，为删除节点做准备
        while(work->next){                   //逐一删除所有元素
            work = work->next;
            delete[] work->front;
        }
        delete[] work;                       //易忽略，此时还有一个元素未删除
        cnt = bottom = 0; top = -1;          //初始化
        start->next = head = tail = nullptr; //初始化
        map->clear();                        //直接调用map的clear函数清空
}
```
- 见注释
- runtime error了n次，太搞心态了，做后发现是while循环条件写的是while(work)，所以在work跳到下一节点时变成了nullptr，无front指针，导致出错

12.size函数
```
const size_t size() const { return cnt; }
```
- 用const，防止修改

13.empty函数
```
bool empty(){ return cnt==0; }
```

14.析构函数
```
~LinearTable(){}
```
- 直接使用系统自带析构函数
***

## 三、OJ测试情况与对比
1.Base_Operation_plus:
- my：Time: 6553ms Memory: 12MB
- deque： Time: 3695ms Memory: 4MB

2.batch_push_pop_1:
- my: Time: 2430ms Memory: 377MB
- deque: Time: 38ms Memory: 28MB

3.alloc_test_1:
- my: Time: 5464ms Memory: 86MB
- deque: Time: 43ms Memory: 7MB

4.alloc_test_2:
- my: Time: 1ms Memory: 3MB
- deque: Time: 1ms Memory: 3MB
***

## 四、总结
1.因为没有用树状结构，很多操作都受到了限制，特别是insert和sort

2.一直在思考如何用链表和map把性能提升到最佳，链表查询慢，map找头尾慢，两者结合起来本应该起到不错的效果（5.1s）,但是后来的优化效果并不好，所以压缩元素的方式并不合适

3.与标准deque的性能比起来差太多，deque的底层就是一颗红黑树，所以我的差距在于还引入了链表，所以空间方面肯定差很多，时间方面差这么多有两个原因：其一是局部没有完全优化，其二是测试函数估计是有太多[]操作，导致我的优化效率大幅下降

4.在实现此结构的过程中，有很多的思考，也查阅了很多相关资料，也尝试着读了stl关于deque的代码（虽然没有很看懂），所以说收获还是挺大的。说实话花了很多时间，但是由于结构本身的局限，也难以想出一些非常好的实现方案和优化方案，还有大量
的时间花在了跟Runtime Error作对上，也压缩了思考和实现代码的时间

5.对于这次PJ还是挺不满意的，课堂pre也看到了很多新奇的实现方法，大多是我没有听说多的结构，什么跳表、红黑树、treep、替罪羊树等等，也因为自己平时课外拓展的太少了，也没有静心去扎实学习它们的勇气（因为平日里的事情都快应付不过来了），
这也是本次PJ带给我的收获吧，要主动去学习新知识，才能不断把任务做到极致
