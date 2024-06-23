fs = 256;% sampling frequency

load ('C:\Users\vimal\Desktop\edfm\sdb1_edfm_FP2-FP4');
t =[0:length(val)-1]/fs;
FP2_FP4=val;
subplot (5,1,1);
plot(t,FP2_FP4, 'color', 'r'); ylabel('FP2-F4', 'color', 'r');
title('CAP sleep Database "sdb1" - 10sec of signal from 5 channels');

load ('C:\Users\vimal\Desktop\edfm\sdb1_edfm_F4-C4');
t =[0:length(val)-1]/fs;
F4_C4=val;
subplot (5,1,2);
plot(t,F4_C4, 'color', 'g'); ylabel('F4-C4', 'color', 'g');

load ('C:\Users\vimal\Desktop\edfm\sdb1_edfm_C4-P4');
t =[0:length(val)-1]/fs;
C4_P4=val;
subplot (5,1,3);
plot(t,C4_P4, 'color', 'b'); ylabel('C4-P4', 'color', 'b');

load ('C:\Users\vimal\Desktop\edfm\sdb1_edfm_P4-O2');
t =[0:length(val)-1]/fs;
P4_O2=val;
subplot (5,1,4);
plot(t,P4_O2, 'color', 'm'); ylabel('P4-O2', 'color', 'm');

load ('C:\Users\vimal\Desktop\edfm\sdb1_edfm_C4-A1');
t =[0:length(val)-1]/fs;
C4_A1=val;
subplot (5,1,5);
plot(t,C4_A1, 'color', 'k'); ylabel('C4-A1', 'color', 'k');