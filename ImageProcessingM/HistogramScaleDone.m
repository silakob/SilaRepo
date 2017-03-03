clc;
clear;

I = imread('pout.tif');
OI = I;
I = double(I);
maximum_value = max(max(I));
K = maximum_value+2;
[row, col] = size(I);
c = row*col;
h = zeros(1,K);
z = zeros(1,K);

% for n=1:row
%     for m=1:col
%         if I(n,m)==0
%             I(n,m)=1;
%         end
%     end
% end

for n=1:row
    for m=1:col
        t = I(n,m);
        h(t) = h(t)+1;
    end
end
pdf = h/c;
cdf(1) = pdf(1);

for x = 2:maximum_value
    cdf(x)=pdf(x)+cdf(x-1);
end

new=round(cdf*maximum_value);

new=new+1;

for p=1:row
    for q=1:col
        temp=I(p,q);
        b(p,q)=new(temp);
        t=b(p,q);
        z(t)=z(t)+1;
    end
end

subplot(2,2,1), imshow(OI),title('Original');
subplot(2,2,2), imhist(OI),title('Histogram Equalization of Image');
subplot(2,2,3), imshow(uint8(b)), title('Image');
subplot(2,2,4), bar(z), title('Histogram of Orig. Image');
