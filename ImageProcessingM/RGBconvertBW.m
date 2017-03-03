clc;
clear;

RGB = imread('pillsetc.png');
subplot(331);imshow(RGB);title('Original');
I = rgb2gray(RGB);

thredhold = graythresh(I);
t = .4


bw = im2bw(I,thredhold);
subplot(332);imshow(bw);title('BW');
P = 12; %P is Two dimensional connectivity to replace with 
bw2 = bwareaopen(bw,P);
subplot(333);imshow(bw2);title('bware');

% disk,2 is an circle
se = strel('disk',2);
bw3 = imclose(bw,se);
subplot(334);imshow(bw3);title('bwcircle');


bw4 = bw3 -bw2;
subplot(335);imshow(bw4);title('Difference bw3 and bw2');
