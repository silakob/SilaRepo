clear all;
close all;
clc;


OB = imread('cameraman.tif');
%subplot(2,2,1);imshow(OB); title('Original Image');
figure;imshow(OB); title('Original Image');

threadholdLEN = 21;
threadholdTHETA = 11;


LEN = 1;
THETA = 1;

firstLEN = 1;
lastLEN = 180;
midLEN = firstLEN;


firstTHETA = 1;
lastTHETA = 20;
midTHETA = firstTHETA;

PSF = fspecial('motion', threadholdLEN, threadholdTHETA);
blurred = imfilter(OB, PSF, 'conv', 'circular');
figure, imshow(blurred);title('Blurred Image');


while LEN ~= threadholdLEN && THETA ~= threadholdTHETA
        midLEN = round((firstLEN + lastLEN)/2);
		midTHETA = round((firstTHETA + lastTHETA)/2);
		PSF = fspecial('motion', midLEN, midTHETA);
		wnr2 = deconvwnr(blurred, PSF, 0);
		 
        figure;imshow(wnr2); title('Deblurred Image');
        midLEN
        midTHETA
		pause;
		
        
        %ปรับค่า first กับ last
        if(midLEN ~= threadholdLEN)
            if(midLEN<threadholdLEN)
                firstLEN = midLEN;
            else
                lastLEN = midLEN;
            end
        end
        
        if(midTHETA ~= threadholdTHETA)
            if(midTHETA<threadholdTHETA)
                firstTHETA = midTHETA;
            else
                lastTHETA = midTHETA;
            end
        end
end