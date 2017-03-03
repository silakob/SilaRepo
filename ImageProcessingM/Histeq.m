clear all;
close all;
clc;


OB = imread('tire.tif');
subplot(2,3,1);imshow(OB); title('Original Image');
%figure;imshow(OB); title('Original Image');


J = histeq(OB);
subplot(2,3,2);imshow(J); title('Histeq Image');
subplot(2,3,3);imhist(OB,64); title('Hist64 Image');
subplot(2,3,4);imhist(J,64); title('Histeq Hist64 Image');
subplot(2,3,5);imhist(OB,10); title('Hist10 Image');
subplot(2,3,6);imhist(J,10); title('Histeq Hist10 Image');
