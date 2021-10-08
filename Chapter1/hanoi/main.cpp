#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>
#include <stack>


using namespace std;

// ��A��nֻ���ӣ�����B,ת�Ƶ�����C��
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
    �������岿��
    */

    hanoi(4,0,1,2);


    /**
    �������岿��
    */
    clock_end= clock();
    cout <<endl<< "������ʱ�� "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" ����"<< endl;
    return 0;
}
