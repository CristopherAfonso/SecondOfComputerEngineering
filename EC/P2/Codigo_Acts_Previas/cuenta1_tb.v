// Práctica 2 E.C - Sesión previa, crear un test bench para el archivo
// cuenta1.v
// Cristopher Manuel Afonso Mora - alu0101402031

`timescale 1ns/10ps

module cuenta1_tb;
  reg [2:0] t_Valor;
  reg t_start, t_clk;
  reg [3:0] t_Cuenta;
  reg t_fin;
  // module cuenta1(input wire [2:0] Valor, input wire start, clk, output wire [3:0] Cuenta, output wire fin);
  // 
  // wire ResetA, CargaA, CargaQ, DesplazaQ;
  // wire [3:0] EntA, SalA;
  // wire [2:0] SalQ;
  // 
  // assign Cuenta = SalA; //Para producir salidas de tipo wire
  // 
  // sum4 sum(EntA,,, SalA, 4'b001, 1'b0); //Acarreos sin conectar a nada, el de entrada a 0
  // regA A(clk, ResetA, CargaA, EntA, SalA);
  // uc uc0(SalQ[0], start, clk, CargaQ, DesplazaQ, ResetA, CargaA, fin);
  // regQ Q(Valor, CargaQ, DesplazaQ, clk, 1'b0, SalQ); //anulamos el reset, ya que se inicializa con la carga de Valor
  // 
  // endmodule
  
  cuenta1 cuenta1_1(t_Valor, t_start, t_clk, t_Cuenta, t_fin);
    initial
      begin
        $monitor("tiempo=%0d Valor=%b start=%b clk=%b Cuenta=%b fin=%b", $time, t_Valor, t_start, t_clk, t_Cuenta, t_fin);
        $dumpfile("cuenta1_tb.vcd");
        $dumpvars;

        t_start = 0;

        t_Valor = 3'b000;
        t_clk = 0;
        #20

        t_Valor = 3'b000;
        t_clk = 1;
        #20

        t_Valor = 3'b001;
        t_clk = 0;
        #20

        t_Valor = 3'b001;
        t_clk = 1;
        #20

        t_Valor = 3'b010;
        t_clk = 0;
        #20

        t_Valor = 3'b010;
        t_clk = 1;
        #20

        t_Valor = 3'b011;
        t_clk = 0;
        #20

        t_Valor = 3'b011;
        t_clk = 1;
        #20

        t_Valor = 3'b100;
        t_clk = 0;
        #20

        t_Valor = 3'b100;
        t_clk = 1;
        #20

        t_Valor = 3'b101;
        t_clk = 0;
        #20

        t_Valor = 3'b101;
        t_clk = 1;
        #20

        t_Valor = 3'b110;
        t_clk = 0;
        #20

        t_Valor = 3'b110;
        t_clk = 1;
        #20

        t_Valor = 3'b111;
        t_clk = 0;
        #20

        t_Valor = 3'b111;
        t_clk = 1;
        #20

        t_start = 1;
        #20

        $finish;
      end
endmodule