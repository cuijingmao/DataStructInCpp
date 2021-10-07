#include <iostream>
#include <time.h>

using namespace std;


// 统计整数二进制展开式中数位1的总数: O(ones)正比于数位1的总数
int countOnes1(unsigned int n){
   int ones = 0;  //计数器复位
   while(0 < n){
    ones++;
    n &= n-1;  //清除当前最右的1
   }
   return ones;
}



int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    程序主体部分
    */

     int n = countOnes1(4294967295);

    /**
    程序主体部分
    */
    clock_end= clock();
    cout<<n<<endl;
    cout<<clock_start << " "<<clock_end<<endl;
    cout << "程序用时： "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" 毫秒"<< endl;
    return 0;
}
