#include <iostream>
#include <time.h>
using namespace std;


void bubblesort1A(int A[], int n){  //ð���㷨 �汾1A
    bool sorted = false;  //���������־�����ȼٶ���δ����
    while(!sorted){   // ����δȷ���Ѿ�ȫ������֮ǰ�����˽���ɨ�轻��
        sorted = true;  // �ٶ��Ѿ�����
        for(int i =1; i<n; i++){ //����������Լ�鵱ǰ��ΧA[0,n)�ڵĸ�����Ԫ��
                if(A[i-1]<A[i]){    //һ��A{i-1]��A[i]������
                    swap(A[i-1],A[i]); //����֮����
                    sorted =false;   //�����������ܱ�֤����Ҫ��������־
                }

        }
        n--;   //����ĩԪ�ر�Ȼ���򣬹ʿ��������������е���Ч����
    }

}  //���������ͱ���sorted���ɼ�����ǰ�˳���������������������n-1��ɨ�轻��

int main()
{
    int A[] = {2,4,1,8,5,9,7,6,3};
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
     �������岿��
    */
    bubblesort1A(A,9);

    /**
      �������岿��
    */
    clock_end= clock();

    cout<<sizeof(A)<<endl;
    for(int i=0; i<9; i++){
           cout << A[i]<< endl;
    }


    cout << "������ʱ�� "<<double(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" ����"<< endl;

    return 0;
}


