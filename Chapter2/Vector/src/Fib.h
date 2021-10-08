#ifndef FIB_H
#define FIB_H


class Fib{  //Fibonacci������
private:
    long  f,g; // f=fib(k-1), g=fib(k)
public:
    Fib(int n)  //��ʼ��Ϊ��С��n����СFibonacci��
    {
        f=1; g=0; while(g < n) next(); //fib(-1), fib(0),O(log_phi(n))��ʱ��
    }
    long get() { return g;}  //��ȡ��ǰFibonacci��
    long next() { g+=f; f= g-f; return g;}
    int prev() {f=g-f; g -=f; return g;}
};













#endif // FIB_H
