// Práctica 1 E.C - Objetivo 2, crear una celda lógica, FA, una Celda A.L
// y probarlas con su Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

`timescale 1ns/10ps

module cal_tb;
  wire t_out, t_c_out;
  reg t_a, t_b, t_arit, t_c_in;
  reg [1:0] t_s;
  // module cal(output wire out, c_out, input wire a, b, arit, c_in, input wire [1:0] s);
  //   //Declaración de conexiones o variables internas:
  //   wire fa_out, cl_out;
  //   //Estructura interna: Instancias de puertas y sus conexiones
  //   cl cl1(cl_out, a, b, s);
  //   fa fa1(c_out, fa_out, a, b, c_in);
  //   mux2_1 mux2_1_1(out, cl_out, fa_out, arit);
  // endmodule
  
  cal cal1(t_out, t_c_out, t_a, t_b, t_arit, t_c_in, t_s);
    initial
      begin
        $monitor("tiempo=%0d arit=%b a=%b b=%b c_in=%b s=%b out=%b c_out=%b", $time, t_arit, t_a, t_b, t_c_in, t_s, t_out, t_c_out);
        $dumpfile("cal_tb.vcd");
        $dumpvars;

        t_arit = 1;
        t_s = 2'b00;
        
        t_a = 0;
        t_b = 0;
        t_c_in = 0;
        #20;

        t_a = 0;
        t_b = 0;
        t_c_in = 1;
        #20;

        t_a = 0;
        t_b = 1;
        t_c_in = 0;
        #20;

        t_a = 0;
        t_b = 1;
        t_c_in = 1;
        #20;

        t_a = 1;
        t_b = 0;
        t_c_in = 0;
        #20;

        t_a = 1;
        t_b = 0;
        t_c_in = 1;
        #20;

        t_a = 1;
        t_b = 1;
        t_c_in = 0;
        #20;

        t_a = 1;
        t_b = 1;
        t_c_in = 1;
        #20;

        $finish;
      end
endmodule
