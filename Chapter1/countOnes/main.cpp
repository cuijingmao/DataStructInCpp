#include <iostream>
#include <time.h>

using namespace std;


// ͳ������������չ��ʽ����λ1��������O(logn��)
int countOnes(unsigned int n){
    int ones =0; // ��������λ

    while( 0 < n){ //��n������0֮ǰ��������
        ones += (1 & n);  //����λ����Ϊ1�����
        n >>=1;
//        cout<<ones<<" "<<n<<endl;
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

     int n = countOnes(4294967295);

    /**
    �������岿��
    */
    clock_end= clock();
    cout<<n<<endl;
    cout<<clock_start << " "<<clock_end<<endl;
    cout << "������ʱ�� "<<(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" ����"<< endl;
    return 0;
}
