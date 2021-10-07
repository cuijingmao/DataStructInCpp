#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;


/***
计算第n个Fibonacci数
*/

// 二分递归版 O(2^n)
__int64 fib(int n){
    return (2>n)?
        (__int64 )n   //到达递归基则直接取值
        :fib(n-1)+ fib(n-2); // 否则，递归计算前两项，其和为正解
}

// 线性递归版 O(n)
__int64 fib(int n, __int64 & prev){
    if(0 ==n ){ // 若到达递归基，则
            prev=1; return 0; //直接取值: fib(-1), fib(0)=0
    }
    else {
        __int64 prevPrev; prev = fib(n-1, prevPrev);  //递归计算前两项
        return prevPrev + prev; //其和即为正解
    }
}

// 动态规划策略， 迭代版  O(n)
__int64  fibI(int n){
    __int64 f=1, g=0; // 初始化： fib(-1); fib(0);
    while(0 < n--)
    { g += f; f = g-f;} //依据原始定义，通过n次加法和减法计算fib(n)
    return g;
}


// 借鉴power2算法和矩阵运算，可是实现时间复杂度为 O(log(n))
// [fib(n), fib(n-1)] = power([0,1;1,1],n) * [0,1];
__int64 fibM(int n){
    int pow[2]= {0,1};
    int p[4]=  {0,1,1,1};
    int a,b,c,d,e,f; // 六个过渡变量，临时保存p的4个分量
                     //和pow的两个分量，因为各分量间存在交叉引用
    while(0 < n) {
        if( n & 1){
            e = pow[0]*p[0] + pow[1] * p[1];
            f = pow[0]*p[2] + pow[1] * p[3];
            pow[0]=e;
            pow[1]=f;
        }
        n >>= 1;  //指数减半
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
    程序主体部分
    */
    int n =30;
    cout<<fibI(n);


//    __int64 num;
//    cout<<fib(n,num);
//    cout<<fibI(n);


    /**
    程序主体部分
    */
    clock_end= clock();
    cout <<endl<< "程序用时： "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" 毫秒"<< endl;
    return 0;
}
