#ifndef LISTNODE_H
#define LISTNODE_H

#define int Rank; //��
#define ListNodePosi(T) ListNode<T>* //�б��ڵ�λ��

//�б��ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
template <typename T> struct ListNode{
    //��Ա
    T data;  ListNodePosi(T) pred; ListNodePosi(T) succ; // ��ֵ��ǰ�������
    //���캯��
    ListNode() {} //���header��trailer�Ĺ���
    ListNode(T e, ListNodePosi(T) p =NULL, ListNodePosi(T) s= NULL)
        :data(e),pred(p),succ(s){}   //Ĭ�Ϲ�����

    //�����ӿ�
    ListNodePosi(T) insertAsPred(T const& e); //������ǰ�ڵ�֮ǰ�����½ڵ�
    ListNodePosi(T) insertAsSucc(T const& e); //���浱ǰ�ڵ�֮������½ڵ�
};





#endif // LISTNODE_H