%Šis ir labākais variants kādu es varēju izdomāt
 %Nedaudz nokaitināja, ka visas rindas nevarēja izveidot ar start:step:end principu
 %Neesmu līdz galam apmierināts ar šo risinājumu, bet, tas darbojas un ir 3:34 naktī tāpēc šoreiz sev piedošu
 %Vismaz, ja es nemaldos tad ir O(n) izpildes laiks
 %Autors: Juris Freidenfelds
  
 %%Pirmais uzdevums 
 A = zeros(3,7); for i = 1:7 if(i==1)A(1,i) = 1; else A(1,i) = A(1,i-1)+2 ;endif ;A(2,i) = i^2; A(3,i) = 2^i; endfor 
 
 %%Otrais uzdevums
 % Reizinājums iegūst 2. un 5. kolonnas summu
 B = [0;1;0;0;1;0;0]
 A * B
 
 %Reizinājums iegūst A matricas 2. rindu
 C = [0,1,0];
 C * A
 
 %Reizinājums apgriež pirmo un otro rindu ar vietām
 D = [0,1,0;1,0,0;0,0,1]
 D * A
 
 %%Trešais uzdevums
 %Reizinājums iegūst rezultātu [1,2,3;1,2,3]
 T = [1,2,3];S = [1;1]; ST = S * T;

 %Reizinājums iegūst rezultātu [1,1;2,2;3,3]
 V = [1;2;3]; W = [1,1]; VW = V * W;


 %izmantotā literatūra - pārsvarā sintakse
 %https://en.wikibooks.org/wiki/Octave_Programming_Tutorial/Vectors_and_matrices
 %https://octave.org/doc/v4.2.1/The-if-Statement.html
 %https://octave.org/doc/v4.0.1/Matrices.html 