clear all;
close all;
clc;


OB = imread('tire.tif');
subplot(321);imshow(OB); title('Original Image');
subplot(322);imhist(OB); title('HistOB Image');

OB2 = imadjust(OB,[0.0 0.1],[0.2 0.7]);
OB3 = imadjust(OB,[0.2 0.3],[0.5 0.8]);

subplot(323);imshow(OB2); title('OB2 Image');
subplot(324);imhist(OB2); title('HistOB2Image');

subplot(325);imshow(OB3); title('OB3 Image');
subplot(326);imhist(OB3); title('HistOB3Image');
