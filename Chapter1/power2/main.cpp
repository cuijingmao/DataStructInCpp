#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;


//�ݺ����Ķ���ݹ�汾power2()

inline __int64 sqr(__int64 a) { return a*a ;}

__int64 power2(int n){  //�ݺ���2^n�㷨���Ż��ݹ�棩 o(logn)
    if(0==n) return 1;  // �ݹ��
    return (n&1) ? sqr(power2(n>>1))<<1 : sqr(power2(n>>1));
}

// �ݺ���2^n�㷨���Ż������棩
__int64 power2_I(int n){
    __int64 pow=1; //�ۼ�����ʼ��Ϊ2^0
    __int64 p=2; //�۳����ʼ��Ϊ2
    while(0 < n){
        if(n &1)  //���ݵ�ǰ����λ�Ƿ�Ϊ1�������Ƿ�
            pow *= p;   //����ǰ�۳�������ۼ���
        n >>= 1; //ָ������
        p *= p;  // �۳����Գ�
    }
    return pow;
}

int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    �������岿��
    */
    int n = power2_I(5);
    cout<<n;


    /**
    �������岿��
    */
    clock_end= clock();
    cout <<endl<< "������ʱ�� "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" ����"<< endl;
    return 0;
}
