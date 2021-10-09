#include "List.h"

//列表初始化
template <template T> void List<T>::init() {
    header = new ListNode<T>; //创建头哨兵节点
    trailer = new ListNode<T>;  //创建尾哨兵节点
    header->succ= trailer; header->pred= NULL;
    trailer->pred = header; trailer->succ = NULL;

    _size = 0; //记录规模
}


//重载下标操作符
template <typename T>
T& List<T>::operator[] (Rank r) const{
    ListNodePosi(T) p=first(); // 从首节点出发
    while(0 <r--) p = p->succ;  //顺数第r个节点即是
    return p->data; //目标节点，返回其中所存元素
}


// 查找
// 在无序列表内节点p（可能是trailer）的n个前驱中，找到等于e的最后者
template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const {
    while( 0< n--){ //对于p的最近的n个前驱,从右向左
        if(e == (p = p->pred)->data) return p; //逐个比对，直至命中或范围越界
    }
    return NULL:  //p越出左边界意味着区间内不含e，查找失败
}// 失败时，返回NULL O(n)


//插入

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{
    _size++;  return header->insertAsSucc(e); //e当首节点插入
}

template <typename T> ListNodePosi(T) Lsit<T>::insertAsLast(T const& e)
{
    _size++; return trailer->insertAsPred(e);  //e当作尾节点插入
}
template <typename T> ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const&e)
{
    _size++; return p->insertAsSucc(e);  //e当作p的后继插入
}
template <typename T> ListNodePosi(T) List<T>::insertB(ListNodePosi(T)p, T const& e)
{
    _size++; return p->insertAsPred(e); //e当作p的前驱插入
}

//前插入
// 将e紧靠当前节点之前 插入于当前节点所属列表（设有哨兵头节点header）
template <typename T>
ListPosiNode(T) ListNode<T>::insertAsPred(T const& e)
{
    LsitNodePosi(T) x = new ListNode(e,pred, this); //创建新节点
    pred->succ=x; pred =x; //设置正向连接
    return x; // 返回新节点的位置
}

//后插入
// 将e紧随当前节点之后插入当前节点所属列表（设有哨兵尾节点trailer)
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e)
{
    ListNodePosi(T) x = new ListNode(e,this,succ); //创建新节点
    succ->pred =x; succ =x; //设置逆向链接
    return x; //返回新节点的位置
}


//基于复制的构造

//列表内部方法：复制列表中自位置p起的n项
void List<T>::copyNodes(ListNodePosi(T) p, int n) { //p合法，且至少有n-1个真后继
    init(); // 创建头、尾哨兵并作初始化
    while(n--) { insertAsLast(p->data); p = p->succ; }  //将自p起的n项依次作为末节点插入
}

// 复制列表中自位置p起的n项
template <typename T>
List<T>::List(ListNodePosi(T) p, int n) { copyNodes(p,n);}

//整体复制列表L
template <typename T>
List<T>::List(List<T> const& L) { copyNodes(L.first(),L._size)}

template <typename T>
List<T>::List(List<T> const& L, int r, int n) { copyNodes(L[r],n);}


//删除合法节点p,返回其数值
template <typename T> Tlist<T>::remove(ListNodePosi(T) p) {
    T e= p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p; _size--;  //释放节点，更新规模
    return e;  //返回备份的数据
}

//列表析构器
template <typename T> List<T>::~List()
{
    clear(); delete header; delete trailer;
}

//清空列表
template <typename T> int List<T>::clear() {
    int oldSize =_size;
    while(0 < _size) remove(header->succ); //反复删除首节点，直至列表变空
    return oldSize;
}

//删除无序列表的重复节点
template <typename T> int List<T>::deduplicate() {
    if( _size <2) return 0;
    int oldSize = _size;
    ListNodesPosi(T) p = header; Rank r =0;  //p从首节点开始
    while(trailer != (p= p->succ)) {
        ListNodePosi(T) q = find(p->data, r, p) ; //在p的r个前驱中查找雷同者
        q? remove(q):r++;
    }
    return  oldSize -_size;  //返回被删除节点总数
}

//借助函数指针遍历
template <typename T> void List<T>::traverse( void(* visit) (T&)){
    for(ListNodePosi(T) p=header->succ;  p != trailer; p=p->succ)  visit(p->data;
}
//借助函数对象机制遍历
template <typename T> template<typename VST>
void List<T>::traverse( VST& visit)
{
    for(ListNodePosi(T) p=header->succ; p!= trailer; p=p->succ) visit(p->data);
}


//有序列表唯一化

template <typename T> int List<T>::uniquify()
{
    if(_size <2) return 0;
    int olsSize = _size;
    ListNodePosi(T) p = first(); ListNodePosi(T) q;  //p为各区段起点，q为其后继
    while(trailer != (q= p->succ)) {
        if( p->data != q->data) p=q;
        else remove(q);
    }
    return oldSize - _size; //返回被删除元素数
}


