// Práctica 1 E.C - Objetivo 3, crear un módulo que complemente números de
// 4 bits en complemento a 1, y probarlo con su Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

module compl1(output wire [3:0] Sal, input wire [3:0] Ent, input wire cpl);
  assign Sal = cpl ? ~Ent : Ent;
endmodule
