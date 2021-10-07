#include <iostream>
#include <time.h>
using namespace std;


void bubblesort1A(int A[], int n){  //冒泡算法 版本1A
    bool sorted = false;  //整体排序标志，首先假定尚未排序
    while(!sorted){   // 在尚未确定已经全局排序之前，逐趟进行扫描交换
        sorted = true;  // 假定已经排序
        for(int i =1; i<n; i++){ //自左向右逐对检查当前范围A[0,n)内的各相邻元素
                if(A[i-1]<A[i]){    //一旦A{i-1]与A[i]逆序，则
                    swap(A[i-1],A[i]); //交换之，并
                    sorted =false;   //因整体排序不能保证，需要清除排序标志
                }

        }
        n--;   //至此末元素必然有序，故可以缩短排序序列的有效长度
    }

}  //借助布尔型变量sorted，可即视提前退出，而不致总是蛮力地做n-1趟扫描交换

int main()
{
    int A[] = {2,4,1,8,5,9,7,6,3};
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
     程序主体部分
    */
    bubblesort1A(A,9);

    /**
      程序主体部分
    */
    clock_end= clock();

    cout<<sizeof(A)<<endl;
    for(int i=0; i<9; i++){
           cout << A[i]<< endl;
    }


    cout << "程序用时： "<<double(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" 毫秒"<< endl;

    return 0;
}


