#include <iostream>
#include <time.h>
#include <bitset>
#include <iomanip>

using namespace std;


/**  ���Ч�İ汾      */
// ͳ������������չ��ʽ����λ1������: O(log2(w)), w=O(log2(n))Ϊ������λ��

#define POW(c) (1<<(c)) //2^c
//��2^cλΪ��λ���飬����ȫ0��ȫ1
#define MASK(c) (((unsigned long)-1) /(POW(POW(c))+1))
/**
MASK(0):  01010101010101010101010101010101
MASK(1):  00110011001100110011001100110011
MASK(2):  00001111000011110000111100001111
MASK(3):  00000000111111110000000011111111
MASK(4):  00000000000000001111111111111111
*/

// ����� ��n�Ķ�����չ���У���2^(c+1)λΪ��λ���飬������ֵ�Ѿ��ֱ����ԭ��
// ��2^(c+1)λ��1����Ŀ
#define ROUND(n,c) (  ((n)& MASK(c))  +  ( (n)>>POW(c) & MASK(c) )  )


void intToBitStr(unsigned long n){
    cout<<bitset<sizeof(n)*8>(n)<<endl;
}

int countOnes2(unsigned int n){

    cout<<endl<<endl<<"n�Ķ����Ʊ�ʾΪ:           ";
    intToBitStr(n);
    cout<<"MASK(0):                   ";
    intToBitStr(MASK(0));
    cout<<"(n)& MASK(0)��ֵ:          ";
    intToBitStr((n)& MASK(0));
    cout<<"(n)>>POW(0)                ";
    intToBitStr((n)>>POW(0));
    cout<<"(n)>>POW(0) & MASK(0)��ֵ: ";
    intToBitStr((n)>>POW(0) & MASK(0));
    n = ROUND(n,0); //��02λΪ��λ���飬������ǰ01λ���01λ�ۼӣ��õ�ԭ����02λ��1����Ŀ
    cout<<"ROUND(n,0)��n��ֵ��        ";
    intToBitStr(n);

    cout<<endl<<endl<<"n�Ķ����Ʊ�ʾΪ:           ";
    intToBitStr(n);
    cout<<"MASK(1):                   ";
    intToBitStr(MASK(1));
    cout<<"(n)& MASK(1)��ֵ:          ";
    intToBitStr((n)& MASK(1));
    cout<<"(n)>>POW(1)                ";
    intToBitStr((n)>>POW(1));
    cout<<"(n)>>POW(1) & MASK(1)��ֵ: ";
    intToBitStr((n)>>POW(1) & MASK(1));
    n = ROUND(n,1); //��04λΪ��λ���飬������ǰ02λ���02λ�ۼӣ��õ�ԭ����04λ��1����Ŀ
    cout<<"ROUND(n,1)��n��ֵ��        ";
    intToBitStr(n);

    cout<<endl<<endl<<"n�Ķ����Ʊ�ʾΪ:           ";
    intToBitStr(n);
    cout<<"MASK(2):                   ";
    intToBitStr(MASK(2));
    cout<<"(n)& MASK(2)��ֵ:          ";
    intToBitStr((n)& MASK(2));
    cout<<"(n)>>POW(2)                ";
    intToBitStr((n)>>POW(2));
    cout<<"(n)>>POW(2) & MASK(2)��ֵ: ";
    intToBitStr((n)>>POW(2) & MASK(2));
    n = ROUND(n,2); //��08λΪ��λ���飬������ǰ04λ���04λ�ۼӣ��õ�ԭ����08λ��1����Ŀ
    cout<<"ROUND(n,2)��n��ֵ��        ";
    intToBitStr(n);

    cout<<endl<<endl<<"n�Ķ����Ʊ�ʾΪ:           ";
    intToBitStr(n);
    cout<<"MASK(3):                   ";
    intToBitStr(MASK(3));
    cout<<"(n)& MASK(1)��ֵ:          ";
    intToBitStr((n)& MASK(3));
    cout<<"(n)>>POW(3)                ";
    intToBitStr((n)>>POW(3));
    cout<<"(n)>>POW(3) & MASK(3)��ֵ: ";
    intToBitStr((n)>>POW(3) & MASK(3));
    n = ROUND(n,3); //��16λΪ��λ���飬������ǰ08λ���08λ�ۼӣ��õ�ԭ����16λ��1����Ŀ
    cout<<"ROUND(n,3)��n��ֵ��        ";
    intToBitStr(n);

    cout<<endl<<endl<<"n�Ķ����Ʊ�ʾΪ:           ";
    intToBitStr(n);
    cout<<"MASK(4):                   ";
    intToBitStr(MASK(4));
    cout<<"(n)& MASK(1)��ֵ:          ";
    intToBitStr((n)& MASK(4));
    cout<<"(n)>>POW(4)                ";
    intToBitStr((n)>>POW(4));
    cout<<"(n)>>POW(4) & MASK(4)��ֵ: ";
    intToBitStr((n)>>POW(4) & MASK(4));
    n = ROUND(n,4); //��32λΪ��λ���飬������ǰ16λ���16λ�ۼӣ��õ�ԭ����32λ��1����Ŀ
    cout<<"ROUND(n,4)��n��ֵ��        ";
    intToBitStr(n);

    return n;
}



int main()
{
    clock_t clock_start, clock_end;
    clock_start = clock();
    /**
    �������岿��
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
     cout<<"-1��ʾΪunsigned longΪ:  ";
     intToBitStr(m);
     cout<<"-1����"<<setw(7)<<POW(POW(0))+1<<" ����Ϊ��    ";
     intToBitStr(MASK(0));
     cout<<"-1����"<<setw(7)<<POW(POW(1))+1<<" ����Ϊ��    ";
     intToBitStr(MASK(1));
     cout<<"-1����"<<setw(7)<<POW(POW(2))+1<<" ����Ϊ��    ";
     intToBitStr(MASK(2));
     cout<<"-1����"<<setw(7)<<POW(POW(3))+1<<" ����Ϊ��    ";
     intToBitStr(MASK(3));
     cout<<"-1����"<<setw(7)<<POW(POW(4))+1<<" ����Ϊ��    ";
     intToBitStr(MASK(4));

     int n = countOnes2(4294967295);
     cout<<n<<endl;





    /**
    �������岿��
    */
    clock_end= clock();

    cout<<clock_start << " "<<clock_end<<endl;
    cout << "������ʱ�� "<<(double)(clock_end-clock_start)/CLOCKS_PER_SEC*1000000<<" ΢��"<< endl;
    return 0;
}
