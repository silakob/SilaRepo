clc;
clear all;

S = ['abc ';'defg';'hi  ']; % Array of String size(3,4)
C = cellstr(S) %Pointer -> size(3)

name = ['Thomas' 'R.' 'Lee'];
name1 = strcat('Thomas', 'R', 'Lee')