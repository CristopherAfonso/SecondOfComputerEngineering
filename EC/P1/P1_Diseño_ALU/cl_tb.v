// Práctica 1 E.C - Objetivo 2, crear una celda lógica, FA, una Celda A.L
// y probarlas con su Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

`timescale 1ns/10ps

module cl_tb;
  reg t_a, t_b;
  reg [1:0] t_s;
  wire t_out;

//   module cl(output wire out, input wire a, b, input wire [1:0] s);
//     //Declaración de conexiones o variables internas:
//     wire and_out, or_out, xor_out, not_out;
//     //Estructura interna: Instancias de puertas y sus conexiones
//     and and1(and_out, a, b);
//     or or1(or_out, a, b);
//     xor xor1(xor_out, a, b);
//     not not1(not_out, a);
//     mux4_1 mux_4_1(out, and_out, or_out, xor_out, not_out, s);
//   endmodule

  cl cl1(t_out, t_a, t_b, t_s);
    initial 
      begin
        $monitor("tiempo=%0d t_a=%b t_b=%b t_s=%b t_out=%b", $time, t_a, t_b, t_s, t_out);
        $dumpfile("cl_tb.vcd");
        $dumpvars;

        t_a = 1;
        t_b = 0;
        t_s = 2'b00;
        #20;

        t_a = 1;
        t_b = 0;
        t_s = 2'b01;
        #20;

        t_a = 1;
        t_b = 0;
        t_s = 2'b10;
        #20;

        t_a = 1;
        t_b = 0;
        t_s = 2'b11;
        #20;

        $finish;

      end

endmodule
