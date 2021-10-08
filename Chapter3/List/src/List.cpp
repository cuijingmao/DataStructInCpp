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












