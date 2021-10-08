#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>
#include <stack>


using namespace std;

/***
 �л���������� �����Լ��
*/

__int64 gcdCN(__int64 a, __int64 b) {
    int r=0; // a��b��2^r��ʽ�Ĺ�����
    while( !((a&1)|| (b&1))) { // ��a��b����ż��
        a>>=1; b>>=1; r++; //��ͬʱ��2�����ۼ�r
    }//���� a��b������һΪż
    while(1){
        while(!(a&1)) a>>=1;
        while(!(b&1)) b>>=1;
        (a>b) ? a=a-b: b=b-a; //��Ϊ�� gcd(max(a,b)-min(a,b),min(a,b))
        if(a==0) return b<<r;
        if(b==0) return a<<r;
    }
}





int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    �������岿��
    */
    __int64 n=gcdCN(120,150);
    cout<<n<<endl;




    /**
    �������岿��
    */
    clock_end= clock();
    cout <<endl<< "������ʱ�� "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" ����"<< endl;
    return 0;
}
