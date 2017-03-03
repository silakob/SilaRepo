clear; 
clc;

for i=1:300
    Z = 10*i + peaks*i;
    surf(Z);
    F(i) = getframe;
    hold on
    image(Z,'CDataMapping','scaled')
end