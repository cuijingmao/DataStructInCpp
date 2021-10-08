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
