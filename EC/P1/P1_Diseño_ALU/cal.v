// Práctica 1 E.C - Objetivo 2, crear una celda lógica, FA, una Celda A.L
// y probarlas con su Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

module cal(output wire out, c_out, input wire a, b, arit, c_in, input wire [1:0] s);
  //Declaración de conexiones o variables internas:
  wire fa_out, cl_out;
  //Estructura interna: Instancias de puertas y sus conexiones
  cl cl1(cl_out, a, b, s);
  fa fa1(c_out, fa_out, a, b, c_in);
  mux2_1 mux2_1_1(out, cl_out, fa_out, arit);
endmodule
