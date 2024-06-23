% Demo description to fft() command on a sin wave 23/01/2019

clear

fs=16000; %sampling f

f=500;  %sin wave freq
t=0:(1/fs):3;
x1= 2*sin(2*pi*f*t);
x2= 2*sin(2*pi*2*f*t);
x=x1+x2

figure
plot(t,x)
xlabel('Time [s]')

%get fft
x_fft=fft(x);

step = fs/(length(x_fft)-1)
freq = 0:step:fs;

figure
plot(freq, abs(x_fft))
xlabel('Frequency [Hz]')