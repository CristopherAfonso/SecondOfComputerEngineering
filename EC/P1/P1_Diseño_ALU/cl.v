// Práctica 1 E.C - Objetivo 2, crear una celda lógica, FA, una Celda A.L
// y probarlas con su Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

module cl(output wire out, input wire a, b, input wire [1:0] s);
  //Declaración de conexiones o variables internas:
  wire and_out, or_out, xor_out, not_out;
  //Estructura interna: Instancias de puertas y sus conexiones
  // las siguientes 4 líneas son una alternativa a la estructura interna del módulo
  // assign and_out = a & b;
  // assign or_out = a | b;
  // assign xor_out = a ^ b;
  // assign not_out = ~a;

  and and1(and_out, a, b);
  or or1(or_out, a, b);
  xor xor1(xor_out, a, b);
  not not1(not_out, a);
  mux4_1 mux_4_1(out, and_out, or_out, xor_out, not_out, s);
endmodule
