//Test bench
//fa_v1_tb.v
//Se diferencia de fa_v1.v en que no tiene salidas

`timescale 1ns/10ps

module fa_v1_tb;
  reg t_a, t_b, t_c_in;
  wire t_sum,t_carry_c_out;

// module fa(output wire sum, output wire c_out, input wire a, input wire b, input wire c_in);

//   wire carry_ha1;
//   wire carry_ha2;
//   wire sum_ha1;

//   ha_v1_1 ha1(sum_ha1, carry_ha1, a, b);
//   ha_v1_1 ha2(sum, carry_ha2, c_in, sum_ha1);
//   or or1(c_out, carry_ha1, carry_ha2);

// endmodule

    //Vamos a declara el módulo fa_v1 en el tb cpn un initial

    fa_v1 fa1(t_sum, t_carry_c_out, t_a, t_b, t_c_in);
        initial 
            begin

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

//Compilar iverilog -o fa fa_v1_tb.v fa_v1.v ha_v1_1.v