// Practica 2 E.C - Paola Janeth Astudillo Capote - Cristopher Manuel Afonso Mora
//                  alu0101337418                 - alu0101402031
// Archivo "microc_tb.v": Contiene el testbench del archivo "microc_tb.v"

`timescale 1 ns/10 ps // Fija la unidad de tiempo de simulación y su precision

module microc_tb; // Instanciamos el modulo a testear
  // Declaramos las señales
  wire [5:0] Test_opcode;
  reg[2:0] Test_op;
  reg clk, reset, Test_s_ret, Test_s_rre, Test_s_inc, Test_s_inm, Test_we3, Test_wez;
  wire t_z;

  microc t_microc(clk, reset, Test_s_ret, Test_s_rre, Test_s_inc, Test_s_inm, Test_we3, Test_wez, Test_op, t_z, Test_opcode);
  
  always 
  begin
    clk <= 1;
    #20;
    clk <= 0;
    #20;
  end

  initial 
    begin
      reset <= 1;
      #10;
      reset <= 0;
    end

  initial
    begin
      $dumpfile("microc.vcd");
      $dumpvars;

      #20; // li R1, 1
      Test_s_inm = 1;
      Test_we3 = 1;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 1;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // li R2, 2
      Test_s_inm = 1;
      Test_we3 = 1;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 1;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // li R3, 8
      Test_s_inm = 1;
      Test_we3 = 1;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 1;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // add R3, R1, R3
      Test_s_inm = 0;
      Test_we3 = 1;
      Test_op = 3'b010;
      Test_wez = 1;
      Test_s_inc = 1;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // jal dec
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 0;
      Test_s_rre = 1;
      Test_s_ret = 0;
      #40;

      // sub R2, R1, R2
      Test_s_inm = 0;
      Test_we3 = 1;
      Test_op = 3'b011;
      Test_wez = 1;
      Test_s_inc = 1;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // ret
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 0;
      Test_s_rre = 0;
      Test_s_ret = 1;
      #40;

      //jnz bucle
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 0;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // add R3, R1, R3
      Test_s_inm = 0;
      Test_we3 = 1;
      Test_op = 3'b010;
      Test_wez = 1;
      Test_s_inc = 1;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40; // aqui

      // jal dec
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 0;
      Test_s_rre = 1;
      Test_s_ret = 0;
      #40;

      // sub R2, R1, R2
      Test_s_inm = 0;
      Test_we3 = 1;
      Test_op = 3'b011;
      Test_wez = 1;
      Test_s_inc = 1;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // ret
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 0;
      Test_s_rre = 0;
      Test_s_ret = 1;
      #40;

      //jnz bucle
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 1;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // j fin
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 0;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // j fin
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 0;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // j fin
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 0;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      // j fin
      Test_s_inm = 0;
      Test_we3 = 0;
      Test_op = 3'b000;
      Test_wez = 0;
      Test_s_inc = 0;
      Test_s_rre = 0;
      Test_s_ret = 0;
      #40;

      $finish;
    end 
endmodule