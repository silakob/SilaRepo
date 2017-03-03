
clear all;
close all;
clc;
a = [1 0 0 0; 5 10 11 8; 9 6 7 12; 4 15 14 1]
%sum(a)
%sum(sum(a))
%z = zeroes(3,3);
b = a';
c = zeros(4,4);
c = a;
for i = 1 : 4
    for j = 1 : 4
        if(i ~= j)
            c(i,j)= a(j,i);
        end
    end
end
c;

d = diag(a);
f = fliplr(a)
