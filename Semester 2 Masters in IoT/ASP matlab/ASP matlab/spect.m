%% Description: script file to demo the use of the fft and spectrogram functions 
% Author: Dr Barry Kirkpatrick
% Date: 04/02/19

%% setup variables and open files

% read in speech file
[x, fs]=audioread('C:\Users\vimal\Desktop\speech_a.wav')

%% plot the signal in time and frequency domain
figure
plot(x)

% plot fft of a window of 512 samples, experiment with different lengths
N = 512;
s = x(2001:2000+N);

% apply a hamming window
hamm_win = hamming(N);
s_win = s.*hamm_win;

figure
hold on
plot(s)
plot(s_win)
hold off

% get the fft and plot
s_win_fft = fft(s_win);
s_fft = fft(s);

figure
hold on
plot(abs(s_win_fft))
plot(abs(s_fft))
hold off

% get the spectrogram
figure
spectrogram(x, hamm_win, N-1)
