// Práctica 1 E.C - Objetivo 2, crear una celda lógica, FA, una Celda A.L
// y probarlas con su Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

module fa(output wire cout, sum, input wire a, b, cin);
  assign {cout, sum} = a + b + cin;
endmodule
