clc;
clear;
I = imread('rice.png');
subplot(131); imshow(I); title('Origin');
X = im2double(I);
X=X-0.2;
subplot(132); imshow(X); title('Gray');
%G = im2bw(X,0.48);
G=I;
[r,c] = size(X);
for i = 1 : r
    for j = 1 : c
        if(G(i,j) > 127)
            G(i,j) = 255;
        else
            G(i,j) = 0;
        end
    end
end

subplot(133); imshow(G); title('B&W');