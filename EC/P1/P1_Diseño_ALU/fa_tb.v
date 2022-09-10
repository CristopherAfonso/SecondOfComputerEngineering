// Práctica 1 E.C - Objetivo 2, crear una celda lógica, FA, una Celda A.L
// y probarlas con su Test Bench
// Cristopher Manuel Afonso Mora - alu0101402031

`timescale 1ns/10ps

module fa_tb;
  reg t_a, t_b, t_cin;
  wire t_cout, t_sum;
  // module fa(output wire cout, sum, input wire a, b, cin);
  //   wire sum1, carry1, carry2;
  //   assign {carry1, sum1} = a + b;
  //   assign {carry2, sum} = cin + sum1;
  //   assign {cout} = carry1 | carry2;
  // endmodule

  fa fa1(t_cout, t_sum, t_a, t_b, t_cin);
    initial 
      begin
        $monitor("tiempo=%0d t_a=%b t_b=%b t_cin=%b t_sum=%b t_cout=%b", $time, t_a, t_b, t_cin, t_sum, t_cout);
        $dumpfile("fa_tb.vcd");
        $dumpvars;

        t_a = 0;
        t_b = 0;
        t_cin = 0;
        #20;

        t_a = 0;
        t_b = 0;
        t_cin = 1;
        #20;

        t_a = 0;
        t_b = 1;
        t_cin = 0;
        #20;

        t_a = 0;
        t_b = 1;
        t_cin = 1;
        #20;

        t_a = 1;
        t_b = 0;
        t_cin = 0;
        #20;

        t_a = 1;
        t_b = 0;
        t_cin = 1;
        #20;

        t_a = 1;
        t_b = 1;
        t_cin = 0;
        #20;

        t_a = 1;
        t_b = 1;
        t_cin = 1;
        #20;

        $finish;
      end
endmodule
