#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;


//幂函数的多向递归版本power2()

inline __int64 sqr(__int64 a) { return a*a ;}

__int64 power2(int n){  //幂函数2^n算法（优化递归版） o(logn)
    if(0==n) return 1;  // 递归基
    return (n&1) ? sqr(power2(n>>1))<<1 : sqr(power2(n>>1));
}

// 幂函数2^n算法（优化迭代版）
__int64 power2_I(int n){
    __int64 pow=1; //累计器初始化为2^0
    __int64 p=2; //累乘项初始化为2
    while(0 < n){
        if(n &1)  //根据当前比特位是否为1，决定是否
            pow *= p;   //将当前累乘项计入累计器
        n >>= 1; //指数减半
        p *= p;  // 累乘项自乘
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
    int n = power2_I(5);
    cout<<n;


    /**
    程序主体部分
    */
    clock_end= clock();
    cout <<endl<< "程序用时： "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" 毫秒"<< endl;
    return 0;
}
