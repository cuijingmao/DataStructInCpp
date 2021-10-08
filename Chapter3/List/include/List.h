#ifndef LIST_H
#define LIST_H


#include "ListNode.h" //�б�ģ����

template <template T> class List { //�б�ģ����
private:
    int _size; ListNodePosi(T) header; ListNodeNodePosi(T) trailer; //��ģ��ͷ�ڱ���β�ڱ�

protected:
    void init(); //�б���ʱ�ĳ�ʼ��
    int clear();  //������нڵ�
    void copyNodes(ListNodePosi(T), int); // �����б�����λ��p���n��
    void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T) ,int);   //�鲢
    void mergeSort(ListNodePosi(T)& ,int); //�Դ�p��ʼ������n���ڵ� �鲢����
    void selectionSort(ListNodePosi(T),int); // �Դ�p��ʼ������n���ڵ�  ѡ������
    void insertionSort(ListNodePosi(T), int); // �Դ�p��ʼ������n���ڵ�  ��������

public:
    //���캯��
    List(){init();} // Ĭ��
    List(List<T> const& L);   //���帴���б�L
    List(List<T> const& L, Rank r,int n)   //�����б�L���Ե�r�����n��
    List(ListNodePosi(T) p, int n);     //�����б�����λ��p���n��

    //��������
    ~List(); //�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�

    //ֻ�����ʽӿ�
    Rank size() const { return _size} //��ģ
    bool empty() const { return _size <= 0;}  //�п�
    T& operator[] (Rank r) const ; //���أ�֧��ѭ�ȷ���
    ListNodePosi(T) first() const { return header->succ;}   // �׽ڵ�λ��
    ListNodePosi(T) last()  const { return trailer->prev;}  //β�ڵ�λ��

    bool valid(ListNodePosi(T) p) //�ж�λ��p�Ƿ����Ϸ�
    {
        return p && (trailer!=p) && (header != p);  //
    }

    ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;  // �����������
    ListNodePosi(T) search(T const &e) const //�����б����
    {
        return search(e,_size,trailer);
    }
    ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p ) const; // �����������
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); //��p����n-1�������ѡ�������
    ListNodePosi(T) selectMax(){  //���������
        return selectMax(header->succ,_size);
    }

    //��д���ʽӿ�
    ListNodePosi(T) insertAsFirst(T const& e); //��e�����׽ڵ����
    ListNodePosi(T) insertAsLast(T const& e); //��e����ĩ�ڵ����
    ListNodePosi(T) insertA(ListNodePosi(T)p, Tconst& e);  //��e��Ϊp�ĺ�̲���
    ListNodePosi(T) insertB(ListNodePosi(T)p, T const& e); //��e����p��ǰ������
    T remove(ListNodePosi(T)p);  //ɾ���Ϸ�λ��p���Ľڵ㣬���ر�ɾ���ڵ�
    void merge(List<T>  & L) {    //ȫ�б�鲢
        merge(first(),size, L.first(),L._size);
    }

    void sort(ListNodePosi(T)p, int n); // �б���������
    void sort(){sort(first(),_size);}   // �б���������
    int deduplicate(); //����ȥ��
    int uniquify(); // ����ȥ��
    void reveerse(); //ǰ����

    //����
    void traverse(void(*) (T&));  //��������ʵʩvisit����������ָ�룬ֻ����ֲ����޸ģ�
    void traverse(VST &);         //����������ʵʩvisit�������������󣬿�ȫ�����޸ģ�

}









#endif // LIST_H
