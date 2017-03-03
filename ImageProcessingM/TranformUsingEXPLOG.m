clc;
OB = imread('pout.tif');
figure;imshow(OB); title('Original');
[r c] = size(OB);
OB1 = OB;
OB1 = single(OB1);% transform to 64 bytes single array
OB1 = uint8(exp(log(OB1+2)));
figure;imshow(OB1); title('Transform');