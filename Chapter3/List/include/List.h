#ifndef LIST_H
#define LIST_H


#include "ListNode.h" //列表模板类

template <template T> class List { //列表模板类
private:
    int _size; ListNodePosi(T) header; ListNodeNodePosi(T) trailer; //规模、头哨兵、尾哨兵

protected:
    void init(); //列表创建时的初始化
    int clear();  //清除所有节点
    void copyNodes(ListNodePosi(T), int); // 复制列表中自位置p起的n项
    void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T) ,int);   //归并
    void mergeSort(ListNodePosi(T)& ,int); //对从p开始的连续n个节点 归并排序
    void selectionSort(ListNodePosi(T),int); // 对从p开始的连续n个节点  选择排序
    void insertionSort(ListNodePosi(T), int); // 对从p开始的连续n个节点  插入排序

public:
    //构造函数
    List(){init();} // 默认
    List(List<T> const& L);   //整体复制列表L
    List(List<T> const& L, Rank r,int n)   //复制列表L中自第r项起的n项
    List(ListNodePosi(T) p, int n);     //复制列表中自位置p起的n项

    //析构函数
    ~List(); //释放（包括头、尾哨兵在内的）所有节点

    //只读访问接口
    Rank size() const { return _size} //规模
    bool empty() const { return _size <= 0;}  //判空
    T& operator[] (Rank r) const ; //重载，支持循秩访问
    ListNodePosi(T) first() const { return header->succ;}   // 首节点位置
    ListNodePosi(T) last()  const { return trailer->prev;}  //尾节点位置

    bool valid(ListNodePosi(T) p) //判断位置p是否对外合法
    {
        return p && (trailer!=p) && (header != p);  //
    }

    ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;  // 无序区间查找
    ListNodePosi(T) search(T const &e) const //有序列表查找
    {
        return search(e,_size,trailer);
    }
    ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p ) const; // 有序区间查找
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); //在p及其n-1个后继中选出最大者
    ListNodePosi(T) selectMax(){  //整体最大者
        return selectMax(header->succ,_size);
    }

    //可写访问接口
    ListNodePosi(T) insertAsFirst(T const& e); //将e当作首节点插入
    ListNodePosi(T) insertAsLast(T const& e); //将e当作末节点插入
    ListNodePosi(T) insertA(ListNodePosi(T)p, Tconst& e);  //将e作为p的后继插入
    ListNodePosi(T) insertB(ListNodePosi(T)p, T const& e); //将e当作p的前驱插入
    T remove(ListNodePosi(T)p);  //删除合法位置p处的节点，返回被删除节点
    void merge(List<T>  & L) {    //全列表归并
        merge(first(),size, L.first(),L._size);
    }

    void sort(ListNodePosi(T)p, int n); // 列表区间排序
    void sort(){sort(first(),_size);}   // 列表整体排序
    int deduplicate(); //无序去重
    int uniquify(); // 有序去重
    void reveerse(); //前后倒置

    //遍历
    void traverse(void(*) (T&));  //遍历，依实施visit操作（函数指针，只读或局部性修改）
    void traverse(VST &);         //遍历，依次实施visit操作（函数对象，可全局性修改）

}









#endif // LIST_H
