close all; clear all; clc;  % Data taken from Physiobank RSVP tasks EEG 
fs = 2048;% sampling frequency
load ('C:\Users\vimal\Desktop\edfm\rsvp_10Hz_02a_edfm_PO8');
t =[0:length(val)-1]/fs;
figure 
plot(t,val); 
xlabel('Time (s)'), ylabel('Amplitude (uV)'), 
title(' EEG signal RSVP PO8 in Time Domain'); %EEG signal in time domain

%EEG signal in frequency domain by FFT
x_fft=fft(val);
step = fs/(length(x_fft)-1)
freq = 0:step:fs;

figure
plot(freq, abs(x_fft))
xlabel('Frequency [Hz]'), title(' EEG signal RSVP PO8 in Frequency Domain');

EEG_vimal=val;

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
plot(t);title('THETA 4-8 Hz');     %THETA BAND PASS FILTER (4-8)

Hd = gamma;
g= filter(Hd,EEG_vimal);
subplot (5,1,5);
plot(g);title('GAMMA 30-100 Hz');     % GAMMA BAND PASS FILTER (30-100)

figure
spectrogram(a);title('Spectrogram of EEG RSVP PO8 alpha')
figure
spectrogram(b);title('Spectrogram of EEG RSVP PO8 beta')
figure
spectrogram(d);title('Spectrogram of EEG RSVP PO8 delta')
figure
spectrogram(t);title('Spectrogram of EEG RSVP PO8 theta')
figure
spectrogram(g);title('Spectrogram of EEG RSVP PO8 gamma')


