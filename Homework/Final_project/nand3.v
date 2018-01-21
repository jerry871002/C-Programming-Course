nand3 3 1 2

module nand3 (N1,N2,N3,Out);

input N1,N2,N3;

output Out;

wire W1;

nand NAND2_1 (W1, N1, N2);
nand NAND2_2 (Out, W1, N3);

endmodule

Pattern
1 0 1
