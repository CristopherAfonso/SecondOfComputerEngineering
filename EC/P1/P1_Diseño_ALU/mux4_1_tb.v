// Práctica 1 E.C - Objetivo 1, crear un mux4_1 y probarlo con un Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

// Test bench
// mux_4_1_tb.v
// se diferencia de mux_4_1.v en que no tiene salidas

 `timescale 1ns/10ps

module mux4_1_tb;
  wire t_out;
  reg t_a, t_b, t_c, t_d; 
  reg [1:0] t_s;

//  mux_4(output reg out, input wire a, b, c, d, input wire [1:0] s);
//   always@(a or b or c or d or s) begin
//     case(s)
//       2'b00  : out = a;     //if s = 00, output is a
//       2'b01  : out = b;     //if s = 01, output is b
//       2'b10  : out = c;     //if s = 10, output is c
//       2'b11  : out = d;     //if s = 11, output is d
//       default: out = 2'bxx  //if s = default, output is anything
//     endcase
//   end
// endmodule

//vamos a declarar el modulo mux_4_1 en el tb cpn un initial

  mux4_1 mux1(t_out, t_a, t_b, t_c, t_d, t_s);
    initial 
      begin
        // Si una variable cambia (sin contar entre estas al tiempo), cuando el tiempo avanza un poco, se muestran por pantalla
        $monitor("tiempo=%0d t_a=%b t_b=%b t_c=%b t_d=%b t_s=%b t_out=%b", $time, t_a, t_b, t_c, t_d, t_s, t_out);
        $dumpfile("mux4_1_tb.vcd"); // Crea el archivo para ver la simulación en el GTKWave
        $dumpvars;

        t_a = 1;
        t_b = 0;
        t_c = 0;
        t_d = 0;
        t_s = 2'b00;
        #20;

        t_a = 0;
        t_b = 1;
        t_c = 0;
        t_d = 0;
        t_s = 2'b01;
        #20;

        t_a = 0;
        t_b = 0;
        t_c = 1;
        t_d = 0;
        t_s = 2'b10;
        #20;

        t_a = 0;
        t_b = 0;
        t_c = 0;
        t_d = 1;
        t_s = 2'b11;
        #20;

        $finish;        

      end
endmodule
