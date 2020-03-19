%麦克劳林展开式进行tan函数进行计算 10阶
function[output] = tan(input)

output = input +  (1.0/3.0) * power(input,3) +  (2.0/15.0) * power(input,5) +  (17.0/315.0) * power(input,7)  +  (62.0/2835.0) * power(input,9) ;
