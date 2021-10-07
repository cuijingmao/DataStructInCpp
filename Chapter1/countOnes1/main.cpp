#include <iostream>
#include <time.h>

using namespace std;


// ͳ������������չ��ʽ����λ1������: O(ones)��������λ1������
int countOnes1(unsigned int n){
   int ones = 0;  //��������λ
   while(0 < n){
    ones++;
    n &= n-1;  //�����ǰ���ҵ�1
   }
   return ones;
}



int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    �������岿��
    */

     int n = countOnes1(4294967295);

    /**
    �������岿��
    */
    clock_end= clock();
    cout<<n<<endl;
    cout<<clock_start << " "<<clock_end<<endl;
    cout << "������ʱ�� "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" ����"<< endl;
    return 0;
}
