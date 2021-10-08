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
    ListNodePosi(T) p=first(); //
}
