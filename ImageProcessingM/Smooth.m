% Filter
clc;
OB = imread('eight.tif');
%figure;imshow(OB); title('Original');
subplot(2,3,1);imshow(OB); title('Original');
[r c] = size(OB);
OB1 = OB;

A = zeros(3,3);
for i = 1 : r-2
    for j = 1 : c-2
        m = 0
        for k = 1 : 3
            A(k,m+1) = OB(i+k-1,j+m);
            m = m+1;
        end
        B = mean(mean(A));
    	OB(i,j) = B;   
    end
end
%figure;imshow(OB); title('Lightness');


x = zeros(3,3);
for i = 1 : r-2
    for j = 1 : c-2
        w = 0;
        for b = i : i+2 
            w = w+1;
            z = 1;
            for a = j : j+2
                x(w,z) = OB1(b,a);
                z = z+1;
            end
        end
        OB1(i,j) = mean(mean(x));
    end
end
%figure;imshow(OB1); title('LightnessTeacherAlgorithm');
subplot(2,3,2);imshow(OB1); title('Filter');



%Median Filter Algorithm

OB2 = OB;
y = zeros(3,3);
for i = 1 : r-2
    for j = 1 : c-2
        w = 0;
        for b = i : i+2 
            w = w+1;
            z = 1;
            for a = j : j+2
                y(w,z) = OB2(b,a);
                z = z+1;
            end
        end
        OB2(i,j) = median(median(y));
    end
end
subplot(2,3,4.5);imshow(OB2); title('Median Filter');