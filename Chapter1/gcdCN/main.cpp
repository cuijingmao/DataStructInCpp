#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>
#include <stack>


using namespace std;

/***
 中华更相减损术 求最大公约数
*/

__int64 gcdCN(__int64 a, __int64 b) {
    int r=0; // a和b的2^r形式的公因子
    while( !((a&1)|| (b&1))) { // 若a和b都是偶数
        a>>=1; b>>=1; r++; //则同时除2，并累加r
    }//以下 a和b至多其一为偶
    while(1){
        while(!(a&1)) a>>=1;
        while(!(b&1)) b>>=1;
        (a>b) ? a=a-b: b=b-a; //简化为： gcd(max(a,b)-min(a,b),min(a,b))
        if(a==0) return b<<r;
        if(b==0) return a<<r;
    }
}





int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    程序主体部分
    */
    __int64 n=gcdCN(120,150);
    cout<<n<<endl;




    /**
    程序主体部分
    */
    clock_end= clock();
    cout <<endl<< "程序用时： "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" 毫秒"<< endl;
    return 0;
}
