#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;

//���Եݹ��
int sum(int A[], int n){
    if(1>n){
        return 0;   //ƽ��������ݹ��
    }
    else
        return sum(A,n-1) + A[n-1];
}



int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    �������岿��
    */
     int A[]={1,2,3,4,5,6,7};
     int n = sum(A,7);
     cout<<n<<endl;




    /**
    �������岿��
    */
    clock_end= clock();
    cout << "������ʱ�� "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000000<<" ΢��"<< endl;
    return 0;
}
