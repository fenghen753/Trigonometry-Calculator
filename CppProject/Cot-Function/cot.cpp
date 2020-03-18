#include <iostream>
#include <cmath>
using namespace std;
#define  PI 3.1415926
#define _USE_MATH_DEFINES
#include <math.h>     // 5，6行保证使用pi，写成M_PI,也可以用宏定义的PI
double cottest(double a)
{	
	int quotient=1;
	// cot函数周期为pi

	//double和fioat型不能用%符号求余 ！！ 所以(a - int(a) + int(a) % 180)是相当与 a%180  
	if ((a - int(a) + int(a) % 180) == 0)
	{
	printf("不能输入180的倍数，因为该值在正切函数中是没有意义的！！！\n\a");
	exit(0);
	}
	else if (a > 180)    //double转化成int，向下取整
	{
		
		quotient =a/180;      //若a=365.3，则quotient=365/180=2 ，a=365.3-2*180= 5.3 
		a = a - quotient * 180;
	}
	else if(a < -180)     //向上取整，如 -359.7-> 359  ,抹去小数点
	{
		quotient = a / 180;        //若a=-365.3，则quotient=-365/180=-2 ，a=-365.3-（-2）*180 = -5.3 
		a = a - quotient * 180;
	}
	//化为主区间 -90<x<90
	if(a>=90)   
	{
		a = a - 180;
	}
	else if (a <= -90)
	{
		a = a + 180;
	}
	double newa = a * PI / 180.0;
	//根据cot函数的泰勒公式展开，取前面的4项。
	double cotx = 1.0 / newa - newa / 3.0 - pow(newa,3)/ 45 - 2 * pow(newa,5)/ 945.0;
	return cotx;
}
int main()
{
	double x;
	cout << "请输入要求的余切的度数值:";
	cin >> x;
	cout << "该余切函数的值是：" <<cottest(x)<<endl;
	return 0;
}

