clear all;
close all;
clc;
g = imread('d:\Pic\34340-andltahrefhttpwwwjpo-qfuw.jpg');
K  = imfinfo('d:\Pic\34340-andltahrefhttpwwwjpo-qfuw.jpg');
im_byte = K.Width * K.Height * K.BitDepth/8;
comp_byte = K.FileSize;
comp_ratio = im_byte/comp_byte;
imwrite(g,'d:\Pic\test.jpg','Quality',0);
t = imread('d:\Pic\test.jpg');
%subplot(2,2,1); 
imshow(g); title('Original');
%subplot(2,2,2);
figure;imshow(t); title('Write');