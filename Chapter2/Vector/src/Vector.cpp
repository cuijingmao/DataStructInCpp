#include "Vector.h"
#include "Fib.h"

template <typename T> //Ԫ������
void Vector<T>::copyFrom��T const * A,Rank lo, Rank hi) { //����������A[lo,hi)Ϊ������������
    _elem = new T[_capacity = 2* (hi-lo)]; _size =0;  //����ռ䣬��ģ����
    while(lo<hi){
        _elem[_size++] = A[lo++]; //������_elem[0,hi-lo)
    }
}

template <typename T> Vector<T>& Vector<T>::opertor= (Vector<T> const& V) { //����
    if(_elem) delete[] _elem;   //�ͷ�ԭ������
    copyFrom(V._elem,0,V.size()); //���帴��
    return *this; // ���ص�ǰ��������ã��Ա�����ʽ��ֵ
}

template <typename T> void Vector<T>::expand() { //�����ռ䲻��ʱ����
    if(_size < _capacity) return; //��δ��Աʱ����������
    if(_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;  // ��������С����
    T* oldElem =_elem; _elem= new T[_capacity <<=1 ]; //�����ӱ�
    for(int i =0; i<_size; i++)
        _elem[i] = oldElem[i];  //����ԭ��������
    delete[] oldElem; //�ͷ�ԭ�пռ�
}

template <typename T> void Vector<T>::shrink() { //װ�����ӹ�Сʱѹ��������ռ�ռ�
    if(_capacity < DEFAULT_CAPACITY <<1) return; // ����������DEFAULT_CAPACITY����
    if(_size <<2 > _capacity) return;  // ��25%Ϊ��
    T* oleElem = _elem; _elem = new T[_capacity >>=1]; //��������
    for(int i=0; i<_size; i++) _elem[i] = oldElem[i]; //����ԭ��������
    delete[] oldElem; //�ͷ�ԭ�ռ�
}

template <typename T> T& Vector<T>::operator[] (Rank r) const // �����±������
{
     return _elem[r];
}

//������
template <typename T> void permute (Vector<T> & V){ //�������������ʹ��Ԫ�صȸ��ʳ����ڸ�λ��
    for(int i=V.size(); i>0; i--) //�Ժ���ǰ
       swap(V[i-1],V[rand()% i]); //V[i-1]��V[0,i)��ĳһ���Ԫ�ؽ���
}

template <typename T> void Vector<T>::unsort(Rank lo,Rank hi){ //�ȸ��������������[lo,hi)
    T* V= _elem + lo; // ��������_elem[lo,hi)������һ����V[0,hi-lo)
    for(Rank i= hi-lo; i>0; i--) //�Ժ���ǰ
        swap(V[i-1],V[rand()%i]); // ��V[i-1]��V[o,i)��ĳһԪ���������
}

template <typename T> static bool lt(T* a, T* b) { return lt(*a,*b);}  //less than
template <typename T> static bool lt(T&a, T&b) { return a<b ;} //less than
template <typename T> static bool eq(T* a, T*b) { return eq(*a, *b);} //equal
template <typename T> static bool eq(T&a, T&b) { return a==b;} //equal

//����������˳����ң��������һ��Ԫ��e��λ�ã�ʧ��ʱ������lo-1
template <typename T>
Rank Vector<T>::find(T const&e, Rank lo,Rank hi) const {
    while((lo<hi--) && (e!= _elem[hi]));  //�Ӻ���ǰ,˳�����
    return hi; // ��hi<lo ,����ζ��ʧ�ܣ�����hi������Ԫ�ص���
}

// ��e��Ϊ��ΪrԪ�ز���
template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
    expand(); //���б�Ҫ������
    for(int i= _size; i > r; i--) _elem[i] = _elem[i-1]; // �Ժ���ǰ�����Ԫ��˳�κ���һ����Ԫ
    _elem[r] = e; _size++; //������Ԫ�ز���������
    return r; //������
}

//ɾ������[lo,hi)
template <typename T> int Vector<T>::remove(Rank lo,Rank hi){
    if(lo==hi) return 0; //����Ч�ʿ��ǣ����������˻����������remove(0,0);
    while(hi<_size) _elem[lo++] =_elem[hi++]; //��[hi, _size)˳��ǰ��hi-lo����Ԫ
    _size = lo; //���¹�ģ��ֱ�Ӷ���β��[lo,_size-hi)����
    shrink(); //���б�Ҫ��������
    return hi-lo; //���ر�ɾ��Ԫ�ص���Ŀ
}

//��Ԫ��ɾ��remove(r)
template <typename T>  T Vector<T>::remove(Rank r) {
    T e = _elem[r]; //���ݱ�ɾ��Ԫ��
    remove(r,r+1);  //��������ɾ���㷨����Ч�ڶ�����[r,r+1)��ɾ��
    return e; //���ر�ɾ��Ԫ��
}

//ɾ�������������ظ�Ԫ�أ���Ч�棩
template <typename T> int Vector<T>::deduplicate(){
    int oldSize=_size;  //��¼ԭ��¼
    Rank i=1;  // ��_elem[1]��ʼ
    while(i < _size){ //��ǰ�����һ�����Ԫ��_elem[i]
            (find(_elem[i],0,i)  < 0 ) ?  // ����ǰ׺��Ѱ����֮��ͬ�ߣ�����һ����
            i++: remove(i);
    }
    return oldSize - _size; //������ģ�仯��������ɾ��Ԫ������
}

//��������ָ�����
template <typename T> void Vector<T>::traverse(void (*visit) (T&))
{
    for(int i=0; i <_size; i++)  visit(_elem[i]);  //��������
}

template <typename T> template <typename VST> // Ԫ�����͡�������
void Vector<T>::traverse(VST& visit)  //���������������
{

    for(int i=0; i <_size; i++) visit(_elem[i]); //��������
}

template <typename T> struct Increase //�������� ����һ��T�����
{
    virtual void operator() (T& e) {e++;} //����T��ֱ�ӵ���������++
}

template <typename T> void increase(Vector<T> &V) //ͳһ���������еĸ�Ԫ��
{
    V.traverse(Increase<T>());  //��Increase<T>()Ϊ�����������б���
}

// ������������������Ԫ�ص�����
template <typename T> int Vector<T>::disordered() const{
    int n =0; //������
    for(int i=1; i<_size; i++) //��һ���_size-1������Ԫ��
      if(_elem[i-1] > _elem[i]) n++; //���������
    return n;
}

//���������ظ�Ԫ��ɾ���㷨����Ч�棩
template <typename T> int Vector<T>::uniquify() {
    int oldSize= _size; int i=1; //��ǰ�Ա�Ԫ�ص��ȣ���ʼ����Ԫ��
    while(i< _size){ //��ǰ�����һ�ȶԸ�������Ԫ��
            _elem[i-1] == _elem[i] ? remove(i): i++ ;// ����ͬ����ɾ�����ߣ�����ת����һԪ��
    }
    return oldSize - _size; //��ɾ��Ԫ������
}

//���������ظ�Ԫ��ɾ���㷨����Ч�棩
template <typename T> int Vector<T>::uniquify() {
    Rank i = 0, j=0;  // ���Ի��조���ڡ�Ԫ�ص���
    while(++j < _size) { //ͨ��j��һɨ�裬 ֱ��ĩԪ��
        if(_elem[i] != _elem[j])  //������ͬ��
           _elem[i++] = _elem[j];  //���ֲ�ͬԪ��ʱ����ǰ����������ǰ���Ҳ�
    }
    _size = ++i; shrink(); //ֱ�ӽس�β������Ԫ��
    return j-i; //��ɾ��Ԫ������
}

//����������������[lo,hi)�ڣ�ȷ��������e�����һ��������
template <typename T>
Rank Vector<T>::search(T const&e, Rank lo, Rank hi) const {
    return (rand()%2) ? // ����50%�ĸ������ʹ�ö��ֲ��һ�Fibonacci����
        binSearch(_elem,e,lo, hi) : fibSearch(_elem,e,lo, hi);
}


//���ֲ����㷨���汾A)������������������[lo,hi���ڲ���Ԫ��e
template <typename T> static Rank binSearch(T* A, T const& e, Rank lo, Rank hi)){
    while(lo<hi) { //ÿ����������Ҫ�����αȽ��жϣ���������֧
            Rank mi = (lo + hi) >>1; // ���е�Ϊ���
            if( e < A[mi]) hi = mi; //����ǰ���[lo,hi)��������
            else if( A[mi] <e) lo = mi +1;   //�������(mi,hi)��������
            else  return i;  //��mi ������
    } //�ɹ����ҿ�����ǰ��ֹ
    return -1; //����ʧ��
} //�ж������ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���򵥵ط���-1��������ָʾʧ�ܵ�λ��


// Fibonacci�����㷨���汾A) : ����������������[lo,hi)�ڲ���Ԫ��e
template <typename T> static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi){
    Fib fib(hi-lo); //��С��hi-lo����СFibonacci�� O(log_phi(n))
    while( lo < hi ) { //ÿ����������Ҫ�����αȽ��жϣ���������֧
            while(hi-lo < fib.get()) fib.prev();  //�������һ��
            Rank mi = lo + fib.get() -1; // ȷ������ Fib(k) -1�����
            if( e< A[mi]) hi =mi;  // ����ǰ���{lo,hi)��������
            else if (A[mi] < e) lo = mi+1; //�������(mi,hi)��������
            else  return mi; //��mi������
    } //�ɹ����ҿ�����ǰ��ֹ
    return -1; // ����ʧ��
} //�ж������Ԫ��ʱ�����ܱ�֤������������ߣ�ʧ��ʱ���򵥷���-1������ָʾʧ�ܵ�λ��

// ���ֲ����㷨���汾B��
template <typename T> static Rank binSearchB(T* A, T const & e, Rank lo, Rank hi){
    while(1 < hi-lo ){  //ÿ������������һ�αȽ��жϣ���������֧���ɹ����Ҳ�����ǰ��ֹ
        Rank mi = (lo + hi) >>1; //���е�Ϊ���
        (e < A[mi]) ? hi = mi: lo =mi; // ���ȽϺ�ȷ������[lo,mi) ��[mi,hi)
    } //����ʱ hi = lo +1  �����������һ��Ԫ��A[lo]
    return ( e==A[lo]) ? lo :-1; // ���ҳɹ�
}//�ж������Ԫ��ʱ�����ܱ�֤������������ߣ�ʧ��ʱ���򵥷���-1������ָʾʧ�ܵ�λ��


// ���ֲ����㷨���汾C,�Ƽ��棩
template <typename T> static Rank binSearchC(T* A, T const& e, Rank lo, Rank hi) {
    while( lo < hi ){ //ÿ������������һ�αȽ��жϣ���������֧
            Rank mi = ( lo + hi) >>1; //���е�Ϊ���
            (e < A[mi]) ? hi = mi: lo= mi+1;  //���ȽϺ�ȷ������[lo,mi) �� ��mi,hi)
    }// ���ҳɹ�������ǰ��ֹ
    return --lo; //ѭ������ʱ��loΪ����e��Ԫ�ص���С�ȣ��� lo-1��������e��Ԫ�ص������
}//�ж������Ԫ��ʱ�����ܱ�֤����������ߣ� ����ʧ��ʱ���ܹ�����ʧ�ܵ�λ��
// �����ԣ� A[0,lo)�е�Ԫ�ؽԲ�����e;A[hi,n)�е�Ԫ�ؽԴ���e








