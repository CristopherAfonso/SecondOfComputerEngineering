//Test bench
//ha_v1_tb.v


//Se diferencia de ha_v1.v en que no tiene salidas

`timescale 1ns/10ps

module ha_v1_tb;
reg t_a,t_b;
wire t_sum,t_carry;
    // module ha_v1(output wire sum, output wire carry, input wire a, input wire b);

    //     //Declaración de instancias de otros módulos/primitivas
    //     xor xor1(sum,a,b);
    //     and and1(carry,a,b);

    // endmodule

    //Vamos a declara el módulo ha_v1 en el tb cpn un initial

    ha_v1 ha1(t_sum, t_carry, t_a, t_b);
        initial 
            begin

                t_a = 0;
                t_b = 0;
                #20ns;

                t_a = 0;
                t_b = 1;
                #20ns;

                t_a = 1;
                t_b = 0;
                #20ns;

                t_a = 1;
                t_b = 1;
                #20ns;

                $finish;

            

        end

endmodule

//Compilar iverilog -o ha ha_v1_tb.v ha_v1.v