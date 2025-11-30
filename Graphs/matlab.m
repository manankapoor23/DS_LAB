clc
clear all
a = [2,3,4;1,2,5;3,4,6];
n = size(a,1);
x = [1;1;1];
lamda_old = 0; 
tol = 0.001;
err =1 ;
while err>tol
    y = a*x;
    lamda_new= max(abs(y));
    x=y/lamda_new;

    err = abs(lamda_new-lamda_old);
    lamda_old=lamda_new;

end

fprintf('dominant eigen value : %f\n',lamda_new);
fprintf('corresponding eigen vector\n');
disp(x);
