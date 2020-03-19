// tan_function.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "tan_function.h"
using namespace std;
#define _USE_MATH_DEFINES
const double PI  =3.141592653589793238463;

int _tmain(int argc, _TCHAR* argv[])
{
	double x,y;
	cout << "输入待求的角度值";
	cin >> x;

	y = x/180 * PI;

	tan_function a(y);
	cout << "正切值为：" << a.caculate() ;
	cout << "误差为：" << tan(y)-a.caculate();
	system("pause");
	return 0;
}



tan_function::tan_function(double i)
{
	input = i;
	output = 0.0;
}


tan_function::~tan_function(void)
{
}


double tan_function::caculate()
{
	//使用麦克劳林展开近似tan函数，默认阶数为10
	double o;
	o = input +  (double(1.0/3.0)) * pow(input,3) +  double(2.0/15.0) * pow(input,5) +  double(17.0/315.0) * pow(input,7)  +  double(62.0/2835.0) * pow(input,9) ;
	return o;
}
