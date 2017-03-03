clear all;
close all;
clc;

z = 0.05;
OB = imread('tire.tif');
subplot(421);imshow(OB); title('Original Image');
% A = adapthisteq(OB,'ClipLimit',z,'Distribution','rayleigh');
% B = adapthisteq(OB,'ClipLimit',z,'Distribution','exponential');
% C = adapthisteq(OB,'ClipLimit',z,'Distribution','uniform');

A = adapthisteq(OB,'NumTiles',[3 3],'ClipLimit',z,'Distribution','rayleigh');
B = adapthisteq(OB,'NumTiles',[5 5],'ClipLimit',z,'Distribution','exponential');
C = adapthisteq(OB,'NumTiles',[7 7],'ClipLimit',z,'Distribution','uniform');



subplot(422);imhist(OB); title('HistOBImage');
subplot(423);imshow(A); title('A rayleigh + NumTiles + ClipLimit');
subplot(424);imhist(A); title('HistA rayleigh + NumTiles + ClipLimit');
subplot(425);imshow(B); title('B exponential + NumTiles + ClipLimit');
subplot(426);imhist(B); title('HistB exponential + NumTiles + ClipLimit');
subplot(427);imshow(C); title('C uniform + NumTiles + ClipLimit');
subplot(428);imhist(C); title('HistC uniform + NumTiles + ClipLimit');