b= [7 5.65 5.62 5.09 5.04]';
A= [1 1; 1 0.3679; 1 0.1353; 1 0.0498; 1 0.0183];

A_pinverse=pinv(A);

x_ext= A_pinverse * b