// Práctica 1 E.C - Objetivo 4, crear el módulo ALU usando los bloques que ya
// he creado y probarlo con su Test Bench (dado por el profesor)
// Cristopher Manuel Afonso Mora - alu0101402031

module alu(output wire [3:0] R, output wire zero, carry, sign, input wire [3:0] A, B, input wire [1:0] ALUOp, input wire arit);
  //Declaración de conexiones o variables internas:
  reg [3:0] kZero = 4'b0000;
  wire [3:0] out_B, OP1, OP2;
  wire op1_A, op2_B, cpl, Cin0;
  wire Cout0, Cout1, Cout2;

  //Estructura interna: Instancias de puertas y sus conexiones

  // Objetivo 5, definir las señales que saldrán de la ALU
  assign zero = ~R[0] && ~R[1] && ~R[2] && ~R[3];
  assign sign = arit ? R[3] : 1'bx;

  // Objetivo 5, definir las señales internas que deciden el tipo de operación
  assign op1_A = ~arit || ~ALUOp[1];
  assign op2_B = ~arit || ~ALUOp[1] || ALUOp[0];
  assign cpl = arit && (ALUOp[1] || ALUOp[0]);
  assign Cin0 = ALUOp[1] || ALUOp[0];

  // Muxes y compl1 del objetivo 4
  mux2_4 mux2_4_A(OP1, kZero, A, op1_A);
  mux2_4 mux2_4_B(out_B, A, B, op2_B);
  compl1 compl1_B(OP2, out_B, cpl);

  // Celdas cal del objetivo 4
  cal cal0(R[0], Cout0, OP1[0], OP2[0], arit, Cin0, ALUOp);
  cal cal1(R[1], Cout1, OP1[1], OP2[1], arit, Cout0, ALUOp);
  cal cal2(R[2], Cout2, OP1[2], OP2[2], arit, Cout1, ALUOp);
  cal cal3(R[3], carry, OP1[3], OP2[3], arit, Cout2, ALUOp);
endmodule
