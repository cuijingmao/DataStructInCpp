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


//����

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e)
{
    _size++;  return header->insertAsSucc(e); //e���׽ڵ����
}

template <typename T> ListNodePosi(T) Lsit<T>::insertAsLast(T const& e)
{
    _size++; return trailer->insertAsPred(e);  //e����β�ڵ����
}
template <typename T> ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const&e)
{
    _size++; return p->insertAsSucc(e);  //e����p�ĺ�̲���
}
template <typename T> ListNodePosi(T) List<T>::insertB(ListNodePosi(T)p, T const& e)
{
    _size++; return p->insertAsPred(e); //e����p��ǰ������
}

//ǰ����
// ��e������ǰ�ڵ�֮ǰ �����ڵ�ǰ�ڵ������б������ڱ�ͷ�ڵ�header��
template <typename T>
ListPosiNode(T) ListNode<T>::insertAsPred(T const& e)
{
    LsitNodePosi(T) x = new ListNode(e,pred, this); //�����½ڵ�
    pred->succ=x; pred =x; //������������
    return x; // �����½ڵ��λ��
}

//�����
// ��e���浱ǰ�ڵ�֮����뵱ǰ�ڵ������б������ڱ�β�ڵ�trailer)
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e)
{
    ListNodePosi(T) x = new ListNode(e,this,succ); //�����½ڵ�
    succ->pred =x; succ =x; //������������
    return x; //�����½ڵ��λ��
}












