#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;

//线性递归版
void reverse(int* ,int, int);

void  reverse(int* A,int n) { reverse(A,0,n-1);}

void reverse(int* A, int lo, int hi) {   // 数组倒置（多递归基递归版）
    if(lo < hi){
        swap(A[lo],A[hi]);
        reverse(A,lo+1,hi-1); //递归倒置
    }
    //else隐含了两种递归基
}


int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    程序主体部分
    */
     int A[]={1,2,3,4,5,6,7};
     reverse(A,7);
     for(int i=0;i<7;i++){
        cout<<A[i]<<" ";
     }



    /**
    程序主体部分
    */
    clock_end= clock();
    cout <<endl<< "程序用时： "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000000<<" 微秒"<< endl;
    return 0;
}
