#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;


//�����ݼ��� a^n��ͨ���㷨�� O(logn)

__int64 powerN(__int64 a, int n){
    __int64 pow =1;
    __int64 p = a;
    while(0 < n){
        if(n & 1)
            pow*=p;
        n >>= 1;
        p *= p;
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
    int n = powerN(3,5);
    cout<<n;


    /**
    �������岿��
    */
    clock_end= clock();
    cout <<endl<< "������ʱ�� "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" ����"<< endl;
    return 0;
}
