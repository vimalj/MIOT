format long;
%Value for resistors and capacitors
Cs=82.11;
Cb=88372.83;
Re=0.00375;
Rs=0.00375;
Rt=0.002745;

a=1/(Cb*(Re+Rs));
b=1/(Cs*(Re+Rs));
d=(Re*Rs)/(Re+Rs);

%State variable matrices
A=[-a a 0 ; b -b 0 ; (-a+b) 0 (a-b)]
B=[a*Re; b*Re; a*(0.5*Rs-Rt-d)+ b*(0.5*Re+Rt+d)]
C=[0 0 1 ]
D=[0]

%Transfer function
figure(1); %Figure 1
[num, den]= ss2tf(A,B,C,D,1)
G=tf(num,den)
step(G),grid;

% For Kalman filter:
% Identity matrix + diagonal element
A=[1-a a 0 ; b 1-b 0 ; (-a+b) 0 1+(a-b)]
B=[a*Re; b*Re; a* (0.5*Rs-Rt-d)+ b*(0.5*Re+Rt+d)]
C=[0 0 1 ]

Tc=1;
A=A*Tc;
B=B*Tc;
C=C;

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

% Parallel connection of outputs ye and y
sys = parallel(P,kalmf,1,1,[],[])

% Close loop around input #4 and output #2
SimModel = feedback(sys,1,4,2,1)

% Delete yv from I/O list
SimModel = SimModel([1 3],[1 2 3])
SimModel.inputname

t =[0:100]';
u= t/1.53;  % Current for discharge

n = length(t)
randn('seed',0);
w = sqrt(Q)*randn(n,1);
v = sqrt(R)*randn(n,1);
[out,x]= lsim(SimModel,[w,v,u]);

y0= 2.2 %This is initial terminal voltage
y = out(:,1)+y0; % true response,
ye = out(:,2)+ y0; % filtered response
yv = y + v; % measured response

figure(2); %Figure 2
subplot(211), plot(t,y,'b-', t,ye,'r--'), grid on;
xlabel('time (s)'),
ylabel('Cell terminal Votage (V_o)')

%Kalman filter response
figure(3); %Figure 3
plot(t,y-yv,'b-', t,y-ye, 'r--'), grid on;
xlabel('time (s)'), ylabel('Error')

%Calculate Errors
MeasErr = y-yv; %Measurement error
MeasErrCov= sum(MeasErr.*MeasErr)/length(MeasErr);
EstErr = y-ye; %Estimated error
EstErrCov = sum(EstErr.*EstErr)/length(EstErr);
%Display onto screen
MeasErrCov %Measurement error
EstErrCov %Estimated error


