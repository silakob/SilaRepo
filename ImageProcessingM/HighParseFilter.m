% Padding Filter

clc;
OB = imread('cameraman.tif');
%subplot(2,3,1);imshow(OB); title('Original');
[r c] = size(OB);
OB1 = zeros(r+2,c+2);
OB1 = OB;

t1 = [1 0; 0 1];
t2 = [0 -1 0; -1 4 -1; 0 -1 0];
Temp_t1 = zeros(2,2);
Temp_t2 = zeros(3,3);

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
subplot(1,3,1);imshow(OB1); title('Padding');


OB2 = OB1;
OB3 = OB1;
y = zeros(3,3);
h = zeros(2,2);

for i = 1 : r
    for j = 1 : c
        w = 0;
        for b = i : i+2 
            w = w+1;
            z = 1;
            %k = 1;
            for a = j : j+2
                y(w,z) = OB1(b,a);
                if( b < i+2 && a < j+2)
                    h(w,z) = OB1(b,a);
                end
                z = z+1;
            end
        end
        for g = 1 : 2
            Temp_t1(g,g) = h(g,g);
        end
        Temp_t2 = t2.*y;
        OB2(i,j) = sum(sum(Temp_t1));
        OB3(i,j) = sum(sum(Temp_t2));
    end
end
subplot(1,3,2);imshow(OB2); title('t1');
subplot(1,3,3);imshow(OB3); title('t2');