#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;

//线性递归版
int sum(int A[], int n){
    if(1>n){
        return 0;   //平凡情况，递归基
    }
    else
        return sum(A,n-1) + A[n-1];
}



int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    程序主体部分
    */
     int A[]={1,2,3,4,5,6,7};
     int n = sum(A,7);
     cout<<n<<endl;




    /**
    程序主体部分
    */
    clock_end= clock();
    cout << "程序用时： "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000000<<" 微秒"<< endl;
    return 0;
}
