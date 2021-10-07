#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;


/***
�����n��Fibonacci��
*/

// ���ֵݹ�� O(2^n)
__int64 fib(int n){
    return (2>n)?
        (__int64 )n   //����ݹ����ֱ��ȡֵ
        :fib(n-1)+ fib(n-2); // ���򣬵ݹ����ǰ������Ϊ����
}

// ���Եݹ�� O(n)
__int64 fib(int n, __int64 & prev){
    if(0 ==n ){ // ������ݹ������
            prev=1; return 0; //ֱ��ȡֵ: fib(-1), fib(0)=0
    }
    else {
        __int64 prevPrev; prev = fib(n-1, prevPrev);  //�ݹ����ǰ����
        return prevPrev + prev; //��ͼ�Ϊ����
    }
}

// ��̬�滮���ԣ� ������  O(n)
__int64  fibI(int n){
    __int64 f=1, g=0; // ��ʼ���� fib(-1); fib(0);
    while(0 < n--)
    { g += f; f = g-f;} //����ԭʼ���壬ͨ��n�μӷ��ͼ�������fib(n)
    return g;
}


// ���power2�㷨�;������㣬����ʵ��ʱ�临�Ӷ�Ϊ O(log(n))
// [fib(n), fib(n-1)] = power([0,1;1,1],n) * [0,1];
__int64 fibM(int n){
    int pow[2]= {0,1};
    int p[4]=  {0,1,1,1};
    int a,b,c,d,e,f; // �������ɱ�������ʱ����p��4������
                     //��pow��������������Ϊ����������ڽ�������
    while(0 < n) {
        if( n & 1){
            e = pow[0]*p[0] + pow[1] * p[1];
            f = pow[0]*p[2] + pow[1] * p[3];
            pow[0]=e;
            pow[1]=f;
        }
        n >>= 1;  //ָ������
        a = p[0] * p[0] + p[2] * p[1];
        b = p[1] * p[0] + p[3] * p[1];
        c = p[0] * p[2] + p[2] * p[3];
        d = p[1] * p[2] + p[3] * p[3];
        p[0]=a; p[1]=b; p[2] = c; p[3] = d;
    }
    return pow[0];
}

int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    �������岿��
    */
    int n =30;
    cout<<fibI(n);


//    __int64 num;
//    cout<<fib(n,num);
//    cout<<fibI(n);


    /**
    �������岿��
    */
    clock_end= clock();
    cout <<endl<< "������ʱ�� "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" ����"<< endl;
    return 0;
}
