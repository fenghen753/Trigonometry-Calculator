#include <iostream>
#include <cmath>
using namespace std;
// #define  PI 3.1415926
#define _USE_MATH_DEFINES
#include <math.h>     // 5，6行保证使用pi，写成M_PI
double cottest(double a)
{	
	int quotient=1;
	if (a >= 180 ) 
	{
		quotient = a / 180;
		a = a - quotient * 180;
	}
	else if(a <= -180)
	{
		quotient = a / 180;
		a = a - quotient * 180;
	}
	else if (a == 0)
	{
		printf("不能输入0，因为0在正切函数中是没有意义的！！！\n\a");
		exit(0);  //当输入的角度是0时，则提示错误并正常结束程序的运行！
	}
	double newa = a * M_PI / 180.0;
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

