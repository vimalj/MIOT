

A= [-0.313 56.7 0; -0.0139 -0.426 0; 0 56.7 0]

B=[0.232; 0.0203; 0]

C=[0 0 1]

D=0;
Q=1;
R=1;

%Transfer function
figure(1); %Figure 1
[num, den]= ss2tf(A,B,C,D)
G=tf(num,den)
step(G),grid;

% For Kalman filter:
% Identity matrix + diagonal element
A= [1-0.313 56.7 0; -0.0139 1-0.426 0; 0 56.7 1]
B=[0.232; 0.0203; 0]
C=[0 0 1]
D=0;

% Sample time=-1 for discrete model
Plant = ss(A,[B B],C,0,-1,'inputname',{'u' 'w'},'outputname','y');
Q=1; 
R=1;
[kalmf,L,P,M] = kalman(Plant,Q,R);
kalmf = kalmf(1,:);
kalmf
a = A;
b = [B B 0*B];
c = [C;C];
d = [0 0 0;0 0 1];
P = ss(a,b,c,d,-1,'inputname',{'u' 'w' 'v'},'outputname',{'y' 'yv'});

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
u = tan(t/5);

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
