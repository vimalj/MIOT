clear all; clear;
A = [1.1269 -0.4940 0.1129
    1.0000 0 0
    0 1.0000 0];

B=[-0.3832
    0.5919
    0.5191];

C=[1 0 0];
D=0;

Q=2;  
R=20;    

Plant = ss(A,[B B],C,0,-1,'INPUTNAME' , {'u' , 'w'},'OUTPUTNAME','y');

[kalmf,L,~,M,Z] = kalman(Plant,Q,R);
kalmf = kalmf(1,:);
M,    %Kalman gain

M=M'; % gain Transpose

a=A;
b=[B B 0*B];
c= [C;C];
d=[0 0 0;0 0 1];
P= ss(a,b,c,d,-1,'inputname', {'u', 'w', 'v'}, 'outputname', {'y', 'yv'});

sys= parallel(P,kalmf,1,1,[],[]);

SimModel= feedback(sys, 1, 4, 2, 1);
SimModel= SimModel([1 3], [1 2 3]);

%time data (random)
t= (0:100)';
u = sin(t/5);

%process noise (random)
rng(10,'twister');
w =sqrt(Q)* randn(length(t),1);
v=sqrt(R)* randn(length(t),1);

%simulate forward
out= lsim(SimModel,[w,v,u]);
y= out(:,1);
ye=out(:,2);
yv=y+v;

subplot(211),
plot(t,y,'b',t,ye,'r--'), xlabel('samples'),ylabel('output')
title('kalman response')

subplot(212),
plot(t,y-yv,'g',t,y-ye,'r--'), xlabel('samples'),ylabel('error')






