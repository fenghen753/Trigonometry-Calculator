clear
clc
a = inputdlg('请输入要求的余切的度数值:','求余弦值');
a=str2double(a{1});
quotient=1;
if a>= 180
    quotient =floor(a / 180); 
    a = a - quotient * 180;
elseif a <= -180
   quotient = ceil(a / 180); 
   a = a - quotient * 180; 
end
if a==0
   h=warndlg('不能输入180的倍数，因为在余切函数中是没有意义的！！！');
end
if a>=90
    a = a -180;
elseif a<= -90
    a= a+180;
end
a = a * pi / 180.0; 
cottx = 1.0 / a - a / 3.0 - a^3/ 45 - 2 * a^5/ 945.0;
msgbox(num2str(cottx))