fs = 256;% sampling frequency

load ('C:\Users\vimal\Desktop\edfm\brux1_edfm_fp2-fp4');
t =[0:length(val)-1]/fs;
FP2_FP4=val;
subplot (5,1,1);
plot(t,FP2_FP4, 'color', 'r'); ylabel('FP2-F4', 'color', 'r');
title('CAP sleep Database "brux1" - 10sec of signal from 5 channels');

load ('C:\Users\vimal\Desktop\edfm\brux1_edfm_f4-c4');
t =[0:length(val)-1]/fs;
F4_C4=val;
subplot (5,1,2);
plot(t,F4_C4, 'color', 'g'); ylabel('F4-C4', 'color', 'g');

load ('C:\Users\vimal\Desktop\edfm\brux1_edfm_c4-p4');
t =[0:length(val)-1]/fs;
C4_P4=val;
subplot (5,1,3);
plot(t,C4_P4, 'color', 'b'); ylabel('C4-P4', 'color', 'b');

load ('C:\Users\vimal\Desktop\edfm\brux1_edfm_p4-o2');
t =[0:length(val)-1]/fs;
P4_O2=val;
subplot (5,1,4);
plot(t,P4_O2, 'color', 'm'); ylabel('P4-O2', 'color', 'm');

load ('C:\Users\vimal\Desktop\edfm\brux1_edfm_f8-t4');
t =[0:length(val)-1]/fs;
F8_T4=val;
subplot (5,1,5);
plot(t,F8_T4, 'color', 'k'); ylabel('F8-T4', 'color', 'k');