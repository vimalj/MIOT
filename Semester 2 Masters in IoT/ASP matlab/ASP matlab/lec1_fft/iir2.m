%script demo basic filtering 23/01/2019

N=100;
x=zeros(N,1);
x(5)=1;
y=zeros(N,1);

for n=2:N;
    y(n)= 2*x(n)+3*x(n-1)+ 2*y(n-1);
end

figure 
hold on
stem(x)
stem(y)
legend('x[n]','y[n]')
hold off