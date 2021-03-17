#include<iostream>
#include<math.h>

using namespace std;

class CRational
{
public:
	CRational(int n,int d);
	~CRational();
    void show();
    CRational add(CRational f);
    CRational multi(CRational f);

private:
    int numerator, denominator;
};

CRational::CRational(int n,int d)
{
    if (d < 0) {
        d = -d;
        n = -n;
    }
    numerator = n;
    denominator = d;
    int max;
    if (fabs(numerator) > fabs(denominator)) {
        max = fabs(numerator);
    }
    else {
        max = fabs(denominator);
    }
    for (int i = 1; i < max; i++)
    {
        if (numerator % i == 0 && denominator % i == 0) 
        {
            numerator = numerator / i;
            denominator = denominator / i;
            max / i;
            i = 1;
        }
    }
    
}
void CRational::show()
{
    cout << numerator << "/" << denominator << endl;
}
CRational CRational::add(CRational f) 
{
    CRational f3(1, 1);
    int newden = denominator * f.denominator;
    f3.numerator = numerator * f.denominator + f.numerator * denominator;
    f3.denominator = newden;
    int max;
    if (fabs(f3.numerator) > fabs(f3.denominator)) {
        max = fabs(f3.numerator);
    }
    else {
        max = fabs(f3.denominator);
    }
    for (int i = 1; i < max; i++)
    {
        if (f3.numerator % i == 0 && f3.denominator % i == 0)
        {
            f3.numerator = f3.numerator / i;
            f3.denominator = f3.denominator / i;
            max / i;
            i = 1;
        }
    }
    return f3;
}
CRational CRational::multi(CRational f) {
    CRational f3(1,1);
    f3.numerator = numerator * f.numerator;
    f3.denominator = denominator * f.denominator;
    int max;
    if (fabs(f3.numerator) > fabs(f3.denominator)) {
        max = fabs(f3.numerator);
    }
    else {
        max = fabs(f3.denominator);
    }
    for (int i = 1; i < max; i++)
    {
        if (f3.numerator % i == 0 && f3.denominator % i == 0)
        {
            f3.numerator = f3.numerator / i;
            f3.denominator = f3.denominator / i;
            max / i;
            i = 1;
        }
    }
    return f3;
}



CRational::~CRational()
{
}



int main()

{

    int a, b, c, d;//接受两个CRational对象的分子和分母

    cin >> a >> b >> c >> d;

    CRational f1(a, b);//f1对象的分子为a，分母为b

    CRational f2(c, d);

    CRational f3 = f1.add(f2);//f1+f2的结果保存到f3中

    f3.show();//显示形式：分子/分母

    f3 = f1.multi(f2);//f1*f2的结果保存到f3中

    f3.show();

    return 0;

}