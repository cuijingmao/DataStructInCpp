#include <iostream>
#include <time.h>

using namespace std;


// 统计整数二进制展开式中数位1的总数（O(logn）)
int countOnes(unsigned int n){
    int ones =0; // 计数器复位

    while( 0 < n){ //在n缩减至0之前，反复地
        ones += (1 & n);  //检查低位，若为1则计数
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
    程序主体部分
    */

     int n = countOnes(4294967295);

    /**
    程序主体部分
    */
    clock_end= clock();
    cout<<n<<endl;
    cout<<clock_start << " "<<clock_end<<endl;
    cout << "程序用时： "<<(clock_end-clock_start)/CLOCKS_PER_SEC*1000<<" 毫秒"<< endl;
    return 0;
}
