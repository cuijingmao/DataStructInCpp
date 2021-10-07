#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;


/**  最高效的版本      */
// 统计整数二进制展开式中数位1的总数: O(log2(w)), w=O(log2(n))为整数的位宽

#define POW(c) (1<<(c)) //2^c
//以2^c位为单位分组，相间地全0和全1
#define MASK(c) (((unsigned long)-1) /(POW(POW(c))+1))
/**
MASK(0):  01010101010101010101010101010101
MASK(1):  00110011001100110011001100110011
MASK(2):  00001111000011110000111100001111
MASK(3):  00000000111111110000000011111111
MASK(4):  00000000000000001111111111111111
*/

// 输出： 在n的二进制展开中，以2^(c+1)位为单位分组，各组数值已经分别等于原来
// 这2^(c+1)位中1的数目
#define ROUND(n,c) (  ((n)& MASK(c))  +  ( (n)>>POW(c) & MASK(c) )  )


void intToBitStr(unsigned long n){
    cout<<bitset<sizeof(n)*8>(n)<<endl;
}

int countOnes2(unsigned int n){

    cout<<endl<<endl<<"n的二进制表示为:           ";
    intToBitStr(n);
    cout<<"MASK(0):                   ";
    intToBitStr(MASK(0));
    cout<<"(n)& MASK(0)的值:          ";
    intToBitStr((n)& MASK(0));
    cout<<"(n)>>POW(0)                ";
    intToBitStr((n)>>POW(0));
    cout<<"(n)>>POW(0) & MASK(0)的值: ";
    intToBitStr((n)>>POW(0) & MASK(0));
    n = ROUND(n,0); //以02位为单位分组，各组内前01位与后01位累加，得到原先这02位中1的数目
    cout<<"ROUND(n,0)后n的值：        ";
    intToBitStr(n);

    cout<<endl<<endl<<"n的二进制表示为:           ";
    intToBitStr(n);
    cout<<"MASK(1):                   ";
    intToBitStr(MASK(1));
    cout<<"(n)& MASK(1)的值:          ";
    intToBitStr((n)& MASK(1));
    cout<<"(n)>>POW(1)                ";
    intToBitStr((n)>>POW(1));
    cout<<"(n)>>POW(1) & MASK(1)的值: ";
    intToBitStr((n)>>POW(1) & MASK(1));
    n = ROUND(n,1); //以04位为单位分组，各组内前02位与后02位累加，得到原先这04位中1的数目
    cout<<"ROUND(n,1)后n的值：        ";
    intToBitStr(n);

    cout<<endl<<endl<<"n的二进制表示为:           ";
    intToBitStr(n);
    cout<<"MASK(2):                   ";
    intToBitStr(MASK(2));
    cout<<"(n)& MASK(2)的值:          ";
    intToBitStr((n)& MASK(2));
    cout<<"(n)>>POW(2)                ";
    intToBitStr((n)>>POW(2));
    cout<<"(n)>>POW(2) & MASK(2)的值: ";
    intToBitStr((n)>>POW(2) & MASK(2));
    n = ROUND(n,2); //以08位为单位分组，各组内前04位与后04位累加，得到原先这08位中1的数目
    cout<<"ROUND(n,2)后n的值：        ";
    intToBitStr(n);

    cout<<endl<<endl<<"n的二进制表示为:           ";
    intToBitStr(n);
    cout<<"MASK(3):                   ";
    intToBitStr(MASK(3));
    cout<<"(n)& MASK(1)的值:          ";
    intToBitStr((n)& MASK(3));
    cout<<"(n)>>POW(3)                ";
    intToBitStr((n)>>POW(3));
    cout<<"(n)>>POW(3) & MASK(3)的值: ";
    intToBitStr((n)>>POW(3) & MASK(3));
    n = ROUND(n,3); //以16位为单位分组，各组内前08位与后08位累加，得到原先这16位中1的数目
    cout<<"ROUND(n,3)后n的值：        ";
    intToBitStr(n);

    cout<<endl<<endl<<"n的二进制表示为:           ";
    intToBitStr(n);
    cout<<"MASK(4):                   ";
    intToBitStr(MASK(4));
    cout<<"(n)& MASK(1)的值:          ";
    intToBitStr((n)& MASK(4));
    cout<<"(n)>>POW(4)                ";
    intToBitStr((n)>>POW(4));
    cout<<"(n)>>POW(4) & MASK(4)的值: ";
    intToBitStr((n)>>POW(4) & MASK(4));
    n = ROUND(n,4); //以32位为单位分组，各组内前16位与后16位累加，得到原先这32位中1的数目
    cout<<"ROUND(n,4)后n的值：        ";
    intToBitStr(n);

    return n;
}



int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    程序主体部分
    */



     cout<<"MASK(1):  ";
     intToBitStr(MASK(1));
     cout<<"MASK(2):  ";
     intToBitStr(MASK(2));
     cout<<"MASK(3):  ";
     intToBitStr(MASK(3));
     cout<<"MASK(4):  ";
     intToBitStr(MASK(4));
     unsigned int m=-1;
     cout<<"-1表示为unsigned long为:  ";
     intToBitStr(m);
     cout<<"-1除以"<<setw(7)<<POW(POW(0))+1<<" 的商为：    ";
     intToBitStr(MASK(0));
     cout<<"-1除以"<<setw(7)<<POW(POW(1))+1<<" 的商为：    ";
     intToBitStr(MASK(1));
     cout<<"-1除以"<<setw(7)<<POW(POW(2))+1<<" 的商为：    ";
     intToBitStr(MASK(2));
     cout<<"-1除以"<<setw(7)<<POW(POW(3))+1<<" 的商为：    ";
     intToBitStr(MASK(3));
     cout<<"-1除以"<<setw(7)<<POW(POW(4))+1<<" 的商为：    ";
     intToBitStr(MASK(4));

     int n = countOnes2(4294967295);
     cout<<n<<endl;





    /**
    程序主体部分
    */
    clock_end= clock();

    cout<<clock_start << " "<<clock_end<<endl;
    cout << "程序用时： "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000000<<" 微秒"<< endl;
    return 0;
}
