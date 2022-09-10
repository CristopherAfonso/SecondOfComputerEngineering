// Práctica 1 E.C - Objetivo 3, crear un módulo que complemente números de
// 4 bits en complemento a 1, y probarlo con su Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

`timescale 1ns/10ps

module compl1_tb;
  wire [3:0] t_Sal;
  reg [3:0] t_Ent;
  reg t_cpl;
  // module compl1(output wire [3:0] Sal, input wire [3:0] Ent, input wire cpl);
  //   assign Sal = cpl ? ~Ent : Ent;
  // endmodule

  compl1 compl1_1(t_Sal, t_Ent, t_cpl);
  initial 
    begin
      $monitor("tiempo=%0d, t_Ent=%b t_cpl=%b t_Sal=%b", $time, t_Ent, t_cpl, t_Sal);
      $dumpfile("compl1_tb.vcd");
      $dumpvars;

      t_Ent = 4'b0101;
      t_cpl = 0;
      #20;

      t_Ent = 4'b0101;
      t_cpl = 1;
      #20;

      $finish;
    end
endmodule
