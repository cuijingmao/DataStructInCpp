#ifndef FIB_H
#define FIB_H


class Fib{  //Fibonacci数列类
private:
    long  f,g; // f=fib(k-1), g=fib(k)
public:
    Fib(int n)  //初始化为不小于n的最小Fibonacci项
    {
        f=1; g=0; while(g < n) next(); //fib(-1), fib(0),O(log_phi(n))的时间
    }
    long get() { return g;}  //获取当前Fibonacci数
    long next() { g+=f; f= g-f; return g;}
    int prev() {f=g-f; g -=f; return g;}
};













#endif // FIB_H
