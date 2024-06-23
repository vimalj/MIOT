fs = 2048; 

load ('C:\Users\vimal\Desktop\edfm\rsvp_10Hz_02a_edfm_PO8');
t =[0:length(val)-1]/fs;
PO8=val;
subplot (5,1,1);
plot(t,PO8, 'color', 'r'); ylabel('PO8', 'color', 'r');
title('EEG signal RSVP task 02a edfm 10 sec of signal from 5 channels');

load ('C:\Users\vimal\Desktop\edfm\rsvp_10Hz_02a_edfm_PO7');
t =[0:length(val)-1]/fs;
PO7=val;
subplot (5,1,2);
plot(t,PO7, 'color', 'g'); ylabel('PO7', 'color', 'g');

load ('C:\Users\vimal\Desktop\edfm\rsvp_10Hz_02a_edfm_P8');
t =[0:length(val)-1]/fs;
P8=val;
subplot (5,1,3);
plot(t,P8, 'color', 'b'); ylabel('P8', 'color', 'b');

load ('C:\Users\vimal\Desktop\edfm\rsvp_10Hz_02a_edfm_P7');
t =[0:length(val)-1]/fs;
P7=val;
subplot (5,1,4);
plot(t,P7, 'color', 'm'); ylabel('P7', 'color', 'm');

load ('C:\Users\vimal\Desktop\edfm\rsvp_10Hz_02a_edfm_O1');
t =[0:length(val)-1]/fs;
O1=val;
subplot (5,1,5);
plot(t,O1, 'color', 'k'); ylabel('O1', 'color', 'k');