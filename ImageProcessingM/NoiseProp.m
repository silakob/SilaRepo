clear;
clc;

I = imread('eight.tif');
m = 0.15;
v = 0.012;
J1 = imnoise(I, 'gaussian',m,v);
J2 = imnoise(I, 'poisson');
J3 = imnoise(I, 'speckle',v);
J4 = imnoise(I, 'salt & pepper', 0.2);
% J5 = imnoise(I, 'localvar', v);
% subplot(3,2,1); imshow(I); title('original');
 subplot(3,2,2); imshow(J1); title('gaussian');
% subplot(3,2,3); imshow(J2); title('poisson');
% subplot(3,2,4); imshow(J3); title('speckle');
% subplot(3,2,5); imshow(J4); title('salt & pepper');
% subplot(3,2,6); imshow(J5); title('localvar');