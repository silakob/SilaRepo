clear; 
clc;
Z = peaks; surf(Z);
axis tight %คือ การกำหนดแกน tight
set(cga,'nextplot','replacechildern');
%record the movie
for j=1:1
    surf(sin(2*pi*j/20)*Z,Z)
    F(j) = getframe;
end


%Play the movie ten times
movie(F,20); %เล่น movie (ตัวแปร movie(คีย์เฟรม) จำนวนเฟรมที่เล่น )