// Práctica 1 E.C - Objetivo 1, crear un mux4_1 y probarlo con un Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

// 1 Fichero / Modulo 
// Nombre igual que el modulo con extensión .v

// Module NombreMod(.......);
//...
//EndModule

//          out=.....;
//always @(...., ..., ...., ...)
//               variables
//begin
//....
//    out=...;
//....
//End
module mux4_1(output reg out, input wire a, b, c, d, input wire [1:0] s);
  always@(a or b or c or d or s)
  begin
    case(s)
      2'b00  : out = a;      //if s = 00, output is a
      2'b01  : out = b;      //if s = 01, output is b
      2'b10  : out = c;      //if s = 10, output is c
      2'b11  : out = d;      //if s = 11, output is d
      default: out = 2'bxx;  //if s = default, output is anything
    endcase
  end
endmodule
