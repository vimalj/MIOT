close all; clear all; clc;  % Data taken from Physiobank RSVP tasks EEG 

EEG_vimal=val;
plot(EEG_vimal); title('EEG Rapid Serial Visual Presentation');

figure;
Hd = alpha;
a= filter(Hd,EEG_vimal);
subplot (5,1,1);
plot(a);title('ALPHA 8-12 Hz'); %ALPHA BAND PASS FILTER (8-12)

Hd = beta;
b= filter(Hd,EEG_vimal);
subplot (5,1,2);
plot(b);title('BETA 13-30 Hz');     %BETA  BAND PASS FILTER (13-30)

Hd = delta;
d= filter(Hd,EEG_vimal);
subplot (5,1,3);
plot(d);title('DELTA 0.5-4 Hz');     %Delta LOW PASS filter (0.5-4)

Hd = theta;
t= filter(Hd,EEG_vimal);
subplot (5,1,4);
plot(t);title('THETA 4-8 Hz');     %THETA- BAND PASS FILTER (4-8)




