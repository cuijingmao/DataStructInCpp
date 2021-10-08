#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>
#include <stack>


using namespace std;

// 将A上n只盘子，经过B,转移到柱子C上
void hanoi(int n, int A, int B,  int C){
    if(n >0) {
        hanoi(n-1,A,C,B);
        cout<<A<<"--->"<<C<<endl;
        hanoi(n-1,B,A,C);
    }
}



int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    程序主体部分
    */

    hanoi(4,0,1,2);


    /**
    程序主体部分
    */
    clock_end= clock();
    cout <<endl<< "程序用时： "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" 毫秒"<< endl;
    return 0;
}
