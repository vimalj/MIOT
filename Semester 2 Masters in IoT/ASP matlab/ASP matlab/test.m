close all; clear all; clc;
fs = 2048;% sampling frequency
T = 1/fs;

load('C:\Users\vimal\Desktop\rsvp_10Hz_02a_edfm_PO3')
N =length(val); % find the length of the data per second
t =[0:length(val)-1]/fs;% Make time axis for EEG signal
f = fs*(0:N/2-1)/N;   %Prepare freq data for plot
figure 
subplot(211), plot(t,val); 
xlabel('Time (s)'), ylabel('Amplitude (uV)'), title(' EEG signal in Time Domain'); %EEG signal
subplot(212), plot(t,val);
xlabel('Time (s)'), ylabel('Amplitude (uV)'), title('Zoomed EEG signal'), xlim([1,2])

%get fft to represent eeg signal in frequency domain
x_fft=fft(val);
step = fs/(length(x_fft)-1)
freq = 0:step:fs;

figure
plot(freq, abs(x_fft))
xlabel('Frequency [Hz]'), title(' EEG signal in Frequency Domain');