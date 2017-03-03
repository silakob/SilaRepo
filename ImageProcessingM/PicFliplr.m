clear all;
close all;
clc;
OB = imread('cameraman.tif');
subplot(2,2,1);imshow(OB); title('Original Fig');

OB1 = OB;
subplot(2,2,2);imshow(OB1'); title('Transpose Fig');

OB2 = OB;
subplot(2,2,3);imshow(fliplr(OB2)); title('Flip left to right Fig');

OB3 = OB;
subplot(2,2,4);imshow(flipud(OB3)); title('Flip up to down Fig');
K = imfinfo('cameraman.tif')