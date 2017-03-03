clc;
clear;

I = imread('pout.tif');
% vary radius to seek the optimum solution
radius = .5;
%J1 = fspecial('disk', radius);
%J1 = fspecial('gaussian',radius);
%J1 = fspecial('laplacian',radius);
%J1 = fspecial('motion',radius);
%J1 = fspecial('prewitt');
J1 = fspecial('sobel');
I2 = imfilter(I,J1, 'replicate');
imshow(I); title('ORIGINAL');
figure;imshow(I2); title('Filter using J');

