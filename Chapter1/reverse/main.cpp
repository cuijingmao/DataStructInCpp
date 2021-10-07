#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;

//���Եݹ��
void reverse(int* ,int, int);

void  reverse(int* A,int n) { reverse(A,0,n-1);}

void reverse(int* A, int lo, int hi) {   // ���鵹�ã���ݹ���ݹ�棩
    if(lo < hi){
        swap(A[lo],A[hi]);
        reverse(A,lo+1,hi-1); //�ݹ鵹��
    }
    //else���������ֵݹ��
}


int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    �������岿��
    */
     int A[]={1,2,3,4,5,6,7};
     reverse(A,7);
     for(int i=0;i<7;i++){
        cout<<A[i]<<" ";
     }



    /**
    �������岿��
    */
    clock_end= clock();
    cout <<endl<< "������ʱ�� "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000000<<" ΢��"<< endl;
    return 0;
}
