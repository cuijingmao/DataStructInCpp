#include "List.h"

//�б��ʼ��
template <template T> void List<T>::init() {
    header = new ListNode<T>; //����ͷ�ڱ��ڵ�
    trailer = new ListNode<T>;  //����β�ڱ��ڵ�
    header->succ= trailer; header->pred= NULL;
    trailer->pred = header; trailer->succ = NULL;

    _size = 0; //��¼��ģ
}


//�����±������
template <typename T>
T& List<T>::operator[] (Rank r) const{
    ListNodePosi(T) p=first(); // ���׽ڵ����
    while(0 <r--) p = p->succ;  //˳����r���ڵ㼴��
    return p->data; //Ŀ��ڵ㣬������������Ԫ��
}


// ����
// �������б��ڽڵ�p��������trailer����n��ǰ���У��ҵ�����e�������
template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const {
    while( 0< n--){ //����p�������n��ǰ��,��������
        if(e == (p = p->pred)->data) return p; //����ȶԣ�ֱ�����л�ΧԽ��
    }
    return NULL:  //pԽ����߽���ζ�������ڲ���e������ʧ��
}// ʧ��ʱ������NULL O(n)
