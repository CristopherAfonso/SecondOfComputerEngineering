// Práctica 1 E.C - Objetivo 2 (y 4), crear una celda lógica, FA, una Celda A.L
// y probarlas con su Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031
// Como este archivo es dado por el profesorado, no lo he modificado y no
// le hago un test bench porque está bien

module mux2_1(output wire out, input wire a, input wire b, input wire s);

	assign out = s ? b : a; //oper. condicional de C, sintaxis [condicion ? valor_si_cierta : valor_si_falsa] 

endmodule
