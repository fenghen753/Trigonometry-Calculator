﻿// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <math.h>
int main()
{
    double COS(double x);
    double t =  150;
    double X=COS(t);
    std::cout << X;
}

double COS(double x)
{
    double pi = 3.1415926;
    x=x/180*pi;
    for (;1;)
    {
        if (x > pi)
        {
            x = x -2* pi;
        }
        if (x < -pi )
        {
            x = x + 2*pi;
        }
        if (-pi  <= x && x <= pi )
        {
            break;
        }
    }
    double result;
    double temp=0;
    int symbol = 1;
    
    
    for (int i = 2;i < 999;i = i + 2)
    {
        symbol = symbol * (-1);       
        double mi_x = 1;
        double jicheng = 1;
        for (int j = 1;j <= i;j = j + 1)
        {
            mi_x = mi_x * x;
            jicheng = jicheng * j ;
        }
        temp = temp + symbol * mi_x / jicheng;
    }
    result = 1 + temp;
    return result;
}

