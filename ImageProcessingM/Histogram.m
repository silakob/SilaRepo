clc;
clear;

OB = imread('pout.tif');
%subplot(331);imshow(OB);title('Original');
[r c] = size(OB);

a = zeros(256);
b=a;
for i = 1 : r
    for j = 1 : c
        k = OB(i,j);
        a(k) = a(k) + 1;
    end
end

for t = 1 : 256-2
    b(t) = (a(t) + a(t+1) + a(t+2))/3;
end

subplot(121);plot(a);
subplot(122);plot(b);