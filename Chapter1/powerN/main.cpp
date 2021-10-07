#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;


//计算幂级数 a^n的通用算法， O(logn)

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
    程序主体部分
    */
    int n = powerN(3,5);
    cout<<n;


    /**
    程序主体部分
    */
    clock_end= clock();
    cout <<endl<< "程序用时： "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" 毫秒"<< endl;
    return 0;
}
