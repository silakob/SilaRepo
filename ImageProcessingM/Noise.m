clear all;
close all;
clc;

m = 0.15;
v = 0.012;
OB = imread('eight.tif');
OB1 = imnoise(I, 'gaussian',m,v);
subplot(3,3,1);imshow(OB); title('Origin');
subplot(3,3,2);imshow(OB1); title('Noise');


window33 = zeros(3,3);
window55 = zeros(5,5);
[r c] = size(OB);
OB3MEAN = OB1;
OB3MODE = OB1;
OB3MEDIAN = OB1;
OB5MEAN = OB1;
OB5MODE = OB1;
OB5MEDIAN = OB1;


for i = 1 : r-4
    for j = 1 : c-4
        w = 0;
        for b = i : i+4 
            w = w+1;
            z = 1;
            for a = j : j+4
                window55(w,z) = OB1(b,a);
                if( b < i+2 && a < j+2)
                    window33(w,z) = OB1(b,a);
                end
                z = z+1;
            end
        end
        OB5MEAN(i,j) = mean(mean(window55));
        OB5MODE(i,j) = mode(mode(window55));
        OB5MEDIAN(i,j) = median(median(window55));
        OB3MEAN(i,j) = mean(mean(window33));
        OB3MODE(i,j) = mode(mode(window33));
        OB3MEDIAN(i,j) = median(median(window33));
    end
end

subplot(3,3,4);imshow(OB5MEAN); title('Mean5');
subplot(3,3,5);imshow(OB5MODE); title('Mode5');
subplot(3,3,6);imshow(OB5MEDIAN); title('Median5');

subplot(3,3,7);imshow(OB3MEAN); title('Mean3');
subplot(3,3,8);imshow(OB3MODE); title('Mode3');
subplot(3,3,9);imshow(OB3MEDIAN); title('Median3');
