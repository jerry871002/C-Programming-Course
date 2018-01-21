Xor 2 1 5

module Xor3 (N1,N2,Out);

input N1,N2;

output Out;

wire W1,W2,W3,W4;

nand NAND2_1 (W1, N1, N1);
nand NAND2_2 (W2, N2, N2);
and AND2_1(W3, W1, N2);
and AND2_1(W4, W2, N1);
or  OR2_1(Out, W3, W4);

endmodule

Pattern
1 0 
