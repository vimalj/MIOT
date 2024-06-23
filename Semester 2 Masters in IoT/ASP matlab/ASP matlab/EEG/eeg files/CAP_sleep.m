close all; clear all; clc; 
% Data taken from Physiobank CAP sleep database
load ('C:\Users\vimal\Desktop\edfm\brux1_edfm_p4-o2');
fs = 256;   % sampling frequency
t =[0:length(val)-1]/fs;

figure 
plot(t,val); 
xlabel('Time (s)'), ylabel('Amplitude (uV)'), 
title(' EEG signal brux1 p4-o2 in Time Domain'); %EEG signal in time domain

%get fft to represent eeg signal in frequency domain
x_fft=fft(val);
step = fs/(length(x_fft)-1)
freq = 0:step:fs;
figure
plot(freq, abs(x_fft))
xlabel('Frequency [Hz]'), title(' EEG signal brux1 p4-o2 in Frequency Domain');

EEG=val;

figure;
Hd = alpha1;
a= filter(Hd,EEG);
subplot (5,1,1);
plot(a);title('ALPHA 8-12 Hz'); %ALPHA BAND PASS FILTER (8-12)

Hd = beta1;
b= filter(Hd,EEG);
subplot (5,1,2);
plot(b);title('BETA 13-30 Hz');     %BETA  BAND PASS FILTER (13-30)

Hd = delta1;
d= filter(Hd,EEG);
subplot (5,1,3);
plot(d);title('DELTA 0.5-4 Hz');     %Delta LOW PASS filter (0.5-4)

Hd = theta1;
t= filter(Hd,EEG);
subplot (5,1,4);
plot(t);title('THETA 4-8 Hz');     %THETA BAND PASS FILTER (4-8)

Hd = gamma1;
g= filter(Hd,EEG);
subplot (5,1,5);
plot(g);title('GAMMA 30-100 Hz');     %GAMMA BAND PASS FILTER (4-8)


figure
spectrogram(a);title('Spectrogram of EEG brux1 p4-o2 alpha')
figure
spectrogram(b);title('Spectrogram of EEG brux1 p4-o2 beta')
figure
spectrogram(d);title('Spectrogram of EEG brux1 p4-o2 delta')
figure
spectrogram(t);title('Spectrogram of EEG brux1 p4-o2 theta')
figure
spectrogram(g);title('Spectrogram of EEG brux1 p4-o2 gamma')


