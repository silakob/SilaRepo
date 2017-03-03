% Padding Filter

clc;
OB = imread('pout.tif');
%subplot(2,3,1);imshow(OB); title('Original');
[r c] = size(OB);
OB1 = zeros(r+2,c+2);
OB1 = OB;

A = zeros(3,3);

% Padding
e = 1;
for i = 1 : r
    d = 1;
    f = 1;
    for j = 1 : c
        if(j > c-2 && j < c+1) %Right padding
            OB1(i,c+d) = OB(i,d);
            d = d+1;
        end
        if(i < 3) %Bottom padding
            OB1(r+e,j) = OB(e,j);
            if(j < 3) %crosswise padding
                OB1(r+e,c+f) = OB(e,j);
                f = f+1;
            end
        end
    end
    e = e+1;
end
subplot(2,2,1);imshow(OB1); title('Padding');

OB2 = OB1;
OB3 = OB1;
OB4 = OB1;




%Mean
y = zeros(3,3);
for i = 1 : r
    for j = 1 : c
        w = 0;
        for b = i : i+2 
            w = w+1;
            z = 1;
            for a = j : j+2
                y(w,z) = OB2(b,a);
                z = z+1;
            end
        end
        OB2(i,j) = mean(mean(y));
    end
end
subplot(2,2,2);imshow(OB2); title('Mean');




%Median
y = zeros(3,3);
for i = 1 : r
    for j = 1 : c
        w = 0;
        for b = i : i+2 
            w = w+1;
            z = 1;
            for a = j : j+2
                y(w,z) = OB3(b,a);
                z = z+1;
            end
        end
        OB3(i,j) = median(median(y));
    end
end
subplot(2,2,3);imshow(OB3); title('Median');




%Mode
y = zeros(3,3);
for i = 1 : r
    for j = 1 : c
        w = 0;
        for b = i : i+2 
            w = w+1;
            z = 1;
            for a = j : j+2
                y(w,z) = OB4(b,a);
                z = z+1;
            end
        end
        OB4(i,j) = mode(mode(y));
    end
end
subplot(2,2,4);imshow(OB4); title('Mode');




