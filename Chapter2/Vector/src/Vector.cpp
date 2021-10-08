#include "Vector.h"
#include "Fib.h"

template <typename T> //元素类型
void Vector<T>::copyFrom（T const * A,Rank lo, Rank hi) { //以数组区间A[lo,hi)为蓝本复制向量
    _elem = new T[_capacity = 2* (hi-lo)]; _size =0;  //分配空间，规模清零
    while(lo<hi){
        _elem[_size++] = A[lo++]; //复制至_elem[0,hi-lo)
    }
}

template <typename T> Vector<T>& Vector<T>::opertor= (Vector<T> const& V) { //重载
    if(_elem) delete[] _elem;   //释放原有内容
    copyFrom(V._elem,0,V.size()); //整体复制
    return *this; // 返回当前对象的引用，以便能链式赋值
}

template <typename T> void Vector<T>::expand() { //向量空间不足时扩容
    if(_size < _capacity) return; //尚未满员时，不必扩容
    if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;  // 不低于最小容量
    T* oldElem =_elem; _elem= new T[_capacity <<=1 ]; //容量加倍
    for(int i =0; i<_size; i++)
        _elem[i] = oldElem[i];  //复制原向量内容
    delete[] oldElem; //释放原有空间
}

template <typename T> void Vector<T>::shrink() { //装填因子过小时压缩向量所占空间
    if(_capacity < DEFAULT_CAPACITY <<1) return; // 不致收缩到DEFAULT_CAPACITY以下
    if(_size <<2 > _capacity) return;  // 以25%为界
    T* oleElem = _elem; _elem = new T[_capacity >>=1]; //容量减半
    for(int i=0; i<_size; i++) _elem[i] = oldElem[i]; //复制原向量内容
    delete[] oldElem; //释放原空间
}

template <typename T> T& Vector<T>::operator[] (Rank r) const // 重载下标运算符
{
     return _elem[r];
}

//置乱器
template <typename T> void permute (Vector<T> & V){ //随机置乱向量，使各元素等概率出现于各位置
    for(int i=V.size(); i>0; i--) //自后向前
       swap(V[i-1],V[rand()% i]); //V[i-1]与V[0,i)中某一随机元素交换
}

template <typename T> void Vector<T>::unsort(Rank lo,Rank hi){ //等概率随机置乱区间[lo,hi)
    T* V= _elem + lo; // 将子向量_elem[lo,hi)视作另一向量V[0,hi-lo)
    for(Rank i= hi-lo; i>0; i--) //自后向前
        swap(V[i-1],V[rand()%i]); // 将V[i-1]与V[o,i)中某一元素随机交换
}

template <typename T> static bool lt(T* a, T* b) { return lt(*a,*b);}  //less than
template <typename T> static bool lt(T&a, T&b) { return a<b ;} //less than
template <typename T> static bool eq(T* a, T*b) { return eq(*a, *b);} //equal
template <typename T> static bool eq(T&a, T&b) { return a==b;} //equal

//无序向量的顺序查找，返回最后一个元素e的位置，失败时，返回lo-1
template <typename T>
Rank Vector<T>::find(T const&e, Rank lo,Rank hi) const {
    while((lo<hi--) && (e!= _elem[hi]));  //从后向前,顺序查找
    return hi; // 若hi<lo ,则意味着失败，否则hi即命中元素的秩
}

// 将e作为秩为r元素插入
template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
    expand(); //若有必要，扩容
    for(int i= _size; i > r; i--) _elem[i] = _elem[i-1]; // 自后向前，后继元素顺次后移一个单元
    _elem[r] = e; _size++; //置入新元素并更新容器
    return r; //返回秩
}

//删除区间[lo,hi)
template <typename T> int Vector<T>::remove(Rank lo,Rank hi){
    if(lo==hi) return 0; //出于效率考虑，单独处理退化情况，比如remove(0,0);
    while(hi<_size) _elem[lo++] =_elem[hi++]; //将[hi, _size)顺次前移hi-lo个单元
    _size = lo; //更新规模，直接丢弃尾部[lo,_size-hi)区间
    shrink(); //若有必要，则缩容
    return hi-lo; //返回被删除元素的数目
}

//单元素删除remove(r)
template <typename T>  T Vector<T>::remove(Rank r) {
    T e = _elem[r]; //备份被删除元素
    remove(r,r+1);  //调用区间删除算法，等效于对区间[r,r+1)的删除
    return e; //返回被删除元素
}

//删除无序向量中重复元素（高效版）
template <typename T> int Vector<T>::deduplicate(){
    int oldSize=_size;  //记录原记录
    Rank i=1;  // 从_elem[1]开始
    while(i < _size){ //自前向后逐一考查各元素_elem[i]
            (find(_elem[i],0,i)  < 0 ) ?  // 在其前缀中寻找与之雷同者（至多一个）
            i++: remove(i);
    }
    return oldSize - _size; //向量规模变化量，即被删除元素总数
}

//借助函数指针机制
template <typename T> void Vector<T>::traverse(void (*visit) (T&))
{
    for(int i=0; i <_size; i++)  visit(_elem[i]);  //遍历向量
}

template <typename T> template <typename VST> // 元素类型、操作类
void Vector<T>::traverse(VST& visit)  //借助函数对象机制
{

    for(int i=0; i <_size; i++) visit(_elem[i]); //遍历向量
}

template <typename T> struct Increase //函数对象： 递增一个T类对象
{
    virtual void operator() (T& e) {e++;} //假设T可直接递增或重载++
}

template <typename T> void increase(Vector<T> &V) //统一递增向量中的各元素
{
    V.traverse(Increase<T>());  //以Increase<T>()为基本操作进行遍历
}

// 返回向量中逆序相邻元素的总数
template <typename T> int Vector<T>::disordered() const{
    int n =0; //计数器
    for(int i=1; i<_size; i++) //逐一检查_size-1对相邻元素
      if(_elem[i-1] > _elem[i]) n++; //逆序则计数
    return n;
}

//有序向量重复元素删除算法（低效版）
template <typename T> int Vector<T>::uniquify() {
    int oldSize= _size; int i=1; //当前对比元素的秩，起始于首元素
    while(i< _size){ //从前向后，逐一比对各对相邻元素
            _elem[i-1] == _elem[i] ? remove(i): i++ ;// 若雷同，则删除后者；否则，转至后一元素
    }
    return oldSize - _size; //被删除元素总数
}

//有序向量重复元素删除算法（高效版）
template <typename T> int Vector<T>::uniquify() {
    Rank i = 0, j=0;  // 各对互异“相邻”元素的秩
    while(++j < _size) { //通过j逐一扫描， 直至末元素
        if(_elem[i] != _elem[j])  //跳过雷同者
           _elem[i++] = _elem[j];  //发现不同元素时，向前移至紧邻于前者右侧
    }
    _size = ++i; shrink(); //直接截除尾部多余元素
    return j-i; //被删除元素总数
}

//在有序向量的区间[lo,hi)内，确定不大于e的最后一个结点的秩
template <typename T>
Rank Vector<T>::search(T const&e, Rank lo, Rank hi) const {
    return (rand()%2) ? // 按各50%的概率随机使用二分查找或Fibonacci查找
        binSearch(_elem,e,lo, hi) : fibSearch(_elem,e,lo, hi);
}


//二分查找算法（版本A)：在有序向量的区间[lo,hi）内查找元素e
template <typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi)){
    while(lo<hi) { //每步迭代可能要做两次比较判断，有三个分支
            Rank mi = (lo + hi) >>1; // 以中点为轴点
            if( e < A[mi]) hi = mi; //深入前半段[lo,hi)继续查找
            else if( A[mi] <e) lo = mi +1;   //深入后半段(mi,hi)继续查找
            else  return i;  //在mi 处命中
    } //成功查找可以提前终止
    return -1; //查找失败
} //有多个命中时，不能保证返回秩最大者，查找失败时，简单地返回-1，不饿能指示失败的位置


// Fibonacci查找算法（版本A) : 在有序向量的区间[lo,hi)内查找元素e
template <typename T> static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi){
    Fib fib(hi-lo); //不小于hi-lo的最小Fibonacci数 O(log_phi(n))
    while( lo < hi ) { //每步迭代可能要做两次比较判断，有三个分支
            while(hi-lo < fib.get()) fib.prev();  //至多迭代一次
            Rank mi = lo + fib.get() -1; // 确定形如 Fib(k) -1的轴点
            if( e< A[mi]) hi =mi;  // 深入前半段{lo,hi)继续查找
            else if (A[mi] < e) lo = mi+1; //深入后半段(mi,hi)继续查找
            else  return mi; //在mi处命中
    } //成功查找可以提前中止
    return -1; // 查找失败
} //有多个命中元素时，不能保证返回最秩最大者，失败时，简单返回-1，不能指示失败的位置

// 二分查找算法（版本B）
template <typename T> static Rank binSearchB(T* A, T const & e, Rank lo, Rank hi){
    while(1 < hi-lo ){  //每步迭代仅需做一次比较判断，有两个分支，成功查找不能提前中止
        Rank mi = (lo + hi) >>1; //以中点为轴点
        (e < A[mi]) ? hi = mi: lo =mi; // 经比较后，确定深入[lo,mi) 或[mi,hi)
    } //出口时 hi = lo +1  查找区间仅含一个元素A[lo]
    return ( e==A[lo]) ? lo :-1; // 查找成功
}//有多个命中元素时，不能保证返回最秩最大者，失败时，简单返回-1，不能指示失败的位置


// 二分查找算法（版本C,推荐版）
template <typename T> static Rank binSearchC(T* A, T const& e, Rank lo, Rank hi) {
    while( lo < hi ){ //每步迭代仅需做一次比较判断，有两个分支
            Rank mi = ( lo + hi) >>1; //以中点为轴点
            (e < A[mi]) ? hi = mi: lo= mi+1;  //经比较后确定深入[lo,mi) 或 （mi,hi)
    }// 查找成功后不能提前终止
    return --lo; //循环结束时，lo为大于e的元素的最小秩，故 lo-1即不大于e的元素的最大秩
}//有多个命中元素时，总能保证返回秩最大者； 查找失败时，能够返回失败的位置
// 不变性： A[0,lo)中的元素皆不大于e;A[hi,n)中的元素皆大于e








