clc;
clear;

RGB = imread('pillsetc.png');
imshow(RGB); figure;
I = rgb2gray(RGB); % conver to grey scale

%level = graythresh(I) computers a global threshold (level) that can be
%used to convert an intensity image to a binary image with im2bw. level is
%a normalized intensity value that lies in the range[0,1].
threshold = graythresh(I);

bw = im2bw(I, threshold);
imshow(bw); figure;

%BW2 = bwareaopen(BW, P) removes from a binary image all connected
%components(object) that have fewer than PO pixels, producing another
%binary inage, BW2. The default connectivity is 8 for two dimension, 26 for
%three dimensions, and conndef(ndims(BW), 'maximal') for higher dimensions.
%BW2 remove all object containing fewer than 30 pixels
bw = bwareaopen(bw,30);

%fill a gap in the pen's cap

se = strel('disk',2);
bw = imclose(bw,se);
imshow(bw);
%fill any holes, so that regionprops can be used to estimate the area
%enclosed by each of the boundaries 
%bw = imfill(bw,'holes');

imshow(bw);
[B,L] = bwboundaries(bw,'noholes');

%Display the label matrix and draw each boundary
imshow(label2rgb(L, @jet, [.5 .5 .5]))
hold on
for k = 1:length(B)
    boundary = B{k};
    plot(boundary(:,2), boundary(:,1), 'w', 'LineWidth', 2)
end
stats = regionprops(L, 'Area', 'Centroid');

threshold = 0.94;

% loop over the boundaries
for k = 1:length(B)
    c = 3;
    boundary = B{k};
    
    delta_sq = diff(boundary).^2;
    perimeter = sum(sqrt(sum(delta_sq,2)));
    area = stats(k).Area;
    
    metric = 4*pi*area/perimeter^2;
    
    metric_string = sprintf('%2.2f',metric);
    
    if metric > stats(k).Centroid;
        plot(centroid(1), centroid(2),'ko');
    end
    
    text(boundary(1,2)-35,boundary(1,1)+13,metric_string,'Color','y','FontSize',14,'FontWeight','bold');
end

title(['Metrics closer to 1 indicate that','the object is approximately round']);