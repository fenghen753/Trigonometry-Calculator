function [y] = sin1(x)
% 借助麦克劳林展开式对sin函数进行计算
ORDER_NUM = 100; %展开的阶数
y = 0;

for i = 1 : ORDER_NUM
    %y = y + (-1)^(i-1) * x^(2*i - 1) / factorial(2*i - 1);  
    y = y + power(-1, i-1) * power(x, 2*i - 1) / factorial(2*i - 1);
end

end

