clear all;
close all;
clc;


OB = imread('cameraman.tif');
subplot(2,2,1);imshow(OB); title('Original Image');


LEN = 21;
THETA = 11;
PSF = fspecial('motion', LEN, THETA);
blurred = imfilter(OB, PSF, 'conv', 'circular');
subplot(2,2,2);imshow(blurred); title('Blurred Image');


% LEN = 35;
% THETA = 11;
% PSF = fspecial('motion', LEN, THETA);
% blurred = imfilter(OB, PSF, 'conv', 'circular');
% subplot(2,2,3);imshow(blurred); title('Blurred Image');
% 
% 
% LEN = 50;
% THETA = 11;
% PSF = fspecial('motion', LEN, THETA);
% blurred = imfilter(OB, PSF, 'conv', 'circular');
% subplot(2,2,4);imshow(blurred); title('Blurred Image');

wnr1 = deconvwnr(blurred, PSF, 0.0001);
subplot(2,2,3); imshow(wnr1); title('Deblurred Image');

