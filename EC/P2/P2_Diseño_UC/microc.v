// Practica 2 E.C - Paola Janeth Astudillo Capote - Cristopher Manuel Afonso Mora
//                  alu0101XXXXXX                 - alu0101402031
// Archivo "microc.v": Contiene la declaracion de un procesador pequeño

//Microcontrolador sin memoria de datos de un solo ciclo
module microc(input wire clk, reset, s_ret, s_rre, s_inc, s_inm, we3, wez, input wire [2:0] op, output wire z, output wire [5:0] opcode);
  // Declaramos variables internas del modulo microc
  wire [15:0] out_mem_prog;
  wire [9:0] out_mux_pc, DIR, DIR_SALTO, mux_to_mux, const1, sum_to_mux,RR_to_mux, sum_out;
  wire [7:0] INM, WD3, OUT_ALU, RD2, RD1;
  wire [3:0] RA1, RA2, WA3;
  wire Z_ALU;
  assign const1 = 10'b1;
  assign opcode = out_mem_prog[15:10];
  assign DIR_SALTO = out_mem_prog[9:0];
  assign INM = out_mem_prog[11:4];

  // Instanciar e interconectar pc, memprog, regfile, alu, sum, biestable Z y mux's
  memprog memoria(clk, DIR, out_mem_prog);
  sum sumador(const1, DIR, sum_out); // Modulo encargado de hacer que el P.C avance una posicion en cada instruccion
  regfile bancoreg (clk, we3, out_mem_prog[11:8], out_mem_prog[7:4], out_mem_prog[3:0], WD3, RD1, RD2);
  alu alu1(RD1, RD2, op, OUT_ALU, Z_ALU);
  ffd ffz(clk, reset, Z_ALU, wez, z);
  registro #(10) PC(clk, reset, out_mux_pc, DIR);
  registro_en #(10) RR(clk, reset, s_rre, sum_out, RR_to_mux); // Registro que guarda la dirección de retorno en cada 'jal'
  mux2 #(10) mux_S_INC(DIR_SALTO, sum_out, s_inc, mux_to_mux);
  mux2 mux_S_INM(OUT_ALU, INM, s_inm, WD3);
  mux2 #(10) mux_S_RET(mux_to_mux, RR_to_mux, s_ret, out_mux_pc);

endmodule

//        li R1, 1
//        li R2, 2
//        li R3, 8
// bucle: add R3, R1, R3
//        jal dec
//        jnz bucle
//        j fin
// dec:   sub R2, R1, R2
//        ret
// fin:   j fin