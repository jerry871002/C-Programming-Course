c17 5 2 6

module c17 (N1,N2,N3,N6,N7,N22,N23);

input N1,N2,N3,N6,N7;

output N22,N23;

wire N10,N11,N16,N19;

nand NAND2_1 (N10, N1, N3);
and AND2_1 (N11, N3, N6);
nor NOR2_1 (N16, N2, N11);
or OR2_1 (N19, N11, N7);
and AND2_2 (N22, N10, N16);
nand NAND2_2 (N23, N16, N19);

endmodule

Pattern
0 0 1 1 0