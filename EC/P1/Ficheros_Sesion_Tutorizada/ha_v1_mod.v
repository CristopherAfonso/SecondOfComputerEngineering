//Semisumador de dos entradas de 1 bit realizado a partir de puertas 

//Primero siempre declaramos las salidas y luego las entradas
//Primero se hizo la xor y la and1
//Luego se hizo las entradas (input)


//Declaración de variables
module ha_v1(output wire sum, output wire carry, input wire a, input wire b);

    //Declaración de instancias de otros módulos/primitivas
    xor xor1(sum,a,b);
    and and1(carry,a,b);

endmodule

//Variable reg: Almacena estados(guarda valores), se va a usar normalmente para 
    //otro tipo de modelado: el de comportamiento---> código procedural 

//Todas las variables que hagamos dentro del código procedural 
//tienen que ser variables reg 

//initial
    // begin 
    //     .
    //     . Por ejemplo podemos poner sum = i + 4;
    //     .
    // end

    // always@( a ,b ,c ) Esta lista de sensibilidad puede tener variables wire
    // begin
    //     .
    //     .
    //     .

    // end

//----------------------------------------------------------------------------------

//Gestión de tiempo
    // #NUM; --> num = retardos

//----------------------------------------------------------------------------------
 
//Directiva timescale
    // `timescale 1ns/10ps --> es el tiempo más pequeño que puede dar el simulador
    // |
    // v
    // es una comilla inversa la que empieza la directiva

//---------------------------------------------------------------------------------

//System task --> sirve para visualizar lo que está pasando en el bench(no tiene
//efecto en la simulación)

    //$time;----------> muestra el tiempo 
    //$finish;--------> el primer initial que llegue a un finish termina la simulación
    //$monitor("...%d....", pepe); --> %d tendría que mostrar pepe por pantalla 
    //$dumpfire("nombrefichero.vcd");--> vdc es el formato en el que vamos a sacar
        // una especie de volcado de nuestras variables
    //dumpvars;N