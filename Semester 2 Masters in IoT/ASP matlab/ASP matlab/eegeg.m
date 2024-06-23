close all; clear all; clc;
fs = 512 % fs — Sampling frequency, positive scalar. Sampling frequency, specified as a positive scalar. The sampling frequency is the number of samples per unit time. If the unit of time is seconds, the sampling frequency has units of hertz.
T = 1/fs;% sampling rate or frequency
load('C:\Users\vimal\Desktop\ASP matlab\hmwk_EEGs') % contains eeg1 and fs
N =length(EEGsig); ls = size(EEGsig); % find the length of the data per second
tx =[0:length(EEGsig)-1]/fs;% Make time axis for EEG signal
fx = fs*(0:N/2-1)/N;   %Prepare freq data for plot
figure; subplot (211), plot(tx,EEGsig); xlabel('Time (s)'), ylabel('Amplitude (uV)'), title('Original EEG signal'); %EEG waveform
subplot(212), plot(tx,EEGsig);
xlabel('Time (s)'), ylabel('Amplitude (uV)'), title('Zoom into original EEG signal at 1 to 2 seconds'), xlim([1,2]) % Used to zoom in on single ECG waveformfigure;
%The mean of the PSDs of xl 
mean_EEGsig = mean(EEGsig);
max_value=max(EEGsig);
mean_value=mean(EEGsig);
threshold=(max_value-mean_value)/2;

%Estimate the power spectrum of the 10-s epoch by computing the periodogram
%% this method is slide the window through the entire data at every 1/2 second, calculate the frequency, average it.
[p,f] = pwelch(EEGsig,hamming(fs),.5*fs, 2*fs,fs); %% 
figure; subplot(421), plot (f,10*log10(p),'r'); xlabel('freq (hz)');
ylabel('PSD Amplitude'); title('Power SPectral Density via Welchs method and hamming window');grid on; xlabel('freq (hz)');ylabel('PSD Amplitude (dB)');
subplot(422), plot (f,10*log10(p),'g'); xlabel('freq (hz)');ylabel('PSD Amplitude (dB)'); title('Power SPectral Density via Welchs method zoom in at 60 hz'); xlim([0,60]);grid on;

x= EEGsig;
[pxx,f] = periodogram(EEGsig,hamming(length(x)),length(x),fs,'power');
[pwrest,idx] = max(pxx);
fprintf('The maximum power occurs at %3.1f Hz\n',f(idx));
fprintf('The power estimate is %2.2f\n',pwrest);
subplot(423), plot(f,10*log10(pxx));title('Power SPectral Density via periodogram method and hamming window');grid on; xlabel('freq (hz)');ylabel('PSD Amplitude (dB)');
subplot(424), plot(f,10*log10(pxx));title('Power SPectral Density via periodogram method and hamming window zoom in at 60Hz');grid on; xlabel('freq (hz)');ylabel('PSD Amplitude (dB)');xlim([0,60]);
%% low pass filter
lpfLength=127; % Order/Number of Filter coefficients
fc = 30; %% cutoff frequency
Wn=(2*fc)/fs; h1=fir1(lpfLength,Wn);
figure; plot(h1);xlabel('Time in Seconds'); ylabel('Magnitude'); title('Low-pass filter'); 
fi = filtfilt(h1,1,EEGsig);
figure; plot(fi); title ('filtfilt');
%Compute the Fourier transform 
Tr1 = conv(EEGsig,h1);
figure; plot(Tr1);