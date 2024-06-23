close all; clear all; clc;
figure;  % Data taken from Physiobank RSVP tasks EEG
load ('C:\Users\vimal\Desktop\plm1_edfm');
EEGP07=val;
plot(EEGP07);

figure;
Hd = alpha1;
a= filter(Hd,EEGP07);
subplot (5,1,1);
plot(a);title('ALPHA 8-12 Hz'); %ALPHA BAND PASS FILTER (8-12)

Hd = beta1;
b= filter(Hd,EEGP07);
subplot (5,1,2);
plot(b);title('BETA 13-30 Hz');     %BETA  BAND PASS FILTER (13-30)

Hd = delta1;
d= filter(Hd,EEGP07);
subplot (5,1,3);
plot(d);title('DELTA 0.5-4 Hz');     %Delta LOW PASS filter (0.5-4)

Hd = theta1;
t= filter(Hd,EEGP07);
subplot (5,1,4);
plot(t);title('THETA 4-8 Hz');     %THETA- BAND PASS FILTER (4-8)