#________________________________________________________________________
# ESTADÍSTICA - GRADO DE INGENIERÍA INFORMÁTICA - ULL
#
# PRÁCTICA DE LABORATORIO 01: Operaciones básicas con R
# Profesores de laboratorio: Carlos González Martín, Sergio Alonso;
# Autor de la práctica: Miguel A. Glez. Sierra
#________________________________________________________________________

# Asignación numérica

a<-2          
3->b                # constante
c=5                 # constante
c = 7               # constante

# Asignación no numérica

a<-"2"                 # constante
b<-"casado"            # constante
is.numeric(b)          

# Asignación a un vector

a<-c(1,5,3,2,9,-1)              # vector 
b<-c("d","g","m","z","13")      # vector
c <- 4:15                       # vector usando el iterador :, que ya devuelve un vector

# Asignación para trabajar con matrices

d <- matrix( 1:10, nrow=2)                # matriz
d

d <- matrix( 1:10, ncol=2 )               # matriz
d

d <- matrix( 1:12, nrow=3,ncol=4 )        # matriz
d

d <- matrix( 1:1000, ncol=5 )             # matriz
d

d<-matrix(c(18,15,12,27,5, 4,9,7,-7,-5,-4,-2), nrow=3)
d<-matrix(c(18,15,12,27,5, 4,9,7,-7,-5,-4,-2), ncol=3)
d<-matrix(c(18,15,12,27,5, 4,9,7,-7,-5,-4,-2), nrow=4,ncol=3)
d<-matrix(c(18,15,12,27,5, 4,9,7,-7,-5,-4,-2), nrow=3,ncol=4)
d

# Acceso a los elementos de una matriz

d[3,2]     # elemento que ocupa el lugar (3,2) en la matriz d
d[2,]      # elementos que forman la fila 2 en la matriz d 
d[,3]      # elementos que forman la columnas 3 en la matriz d

dim(d)                                         # dimensiones de una matriz

# gestión del workspace

remove(d)                                      # elimina un objeto
ls()                                           # lista los objetos del workspace
remove(a,c)                                    # elimina varios objetos
remove(list=ls())                              # elimina todos los objetos

# construcción de vectores desde secuencias
a <- seq( from=5, to=23, by=.5 )               # crear un vector mediante sequence dado el incremento
a <- seq( from=5, to=23, length=100 )          # crear un vector mediante sequence dado el tamaño del vector
a1<-rep(3,10)                                  # crear un vector mediante rep, repitiendo el 3 10 veces
a1<-rep(1:10,3)                                # crear un vector mediante rep, repitiendo 1:10 tres veces

# construcción de vectores desde generación de valores aleatorios
b <- rnorm(100)                        # generación de valores de una distribución normal
b <- runif(100)                           # generación de valores de una distribución uniforme, ir aumentando el número de valores
hist(b)                                    # un histograma simple


c <- cbind(a,b)                        # combina columnas en una matriz
d <- rbind(a,b)                        # combina filaS en una matriz
dt <- t(d)                             # transpuesta de una matriz
e <- cbind(c,dt)                       # combina columnas en una matriz
e

colnames(e) <- c("nom1","nom2","nom3","nom4")  # poner nombre a columnas de una matriz
rownames(e) <- paste("obs",1:100, sep="-")      # poner nombre a filas de una matriz
e

# nombre a filas y columnas de manera conjunta
dim(e)
dimnames(e) <- list( paste("obs",1:100, sep=""),c("nom1","nom2","nom3","nom4"))

letters                                           # conjunto de caracteres que usa R
f<-c(letters,letters,letters)                     # vector de caracteres
f
                                     
f[79:100]<-NA                                     # añadimos NA hasta una longitud de 100
f

h <- data.frame(e,f)                              # data frame
dim(h)                                            # las dimensiones del data frame
str(h)                                            # la estructura del data fame
remove(list=ls())  

a <- 1:20                            # vector
b <- 31:50                           # vector 
      
# Operaciones con vectores

sqrt(a)
a+b                                 
a-b
a*b
a/b
b^a

# Operaciones con matrices
# formamos la matriz A

A<-matrix(1:12,nrow=3)      
A
log(A)
A[2,3]
A[2,]
A[,3]
C<-A[c(1,3),2:3]
C

# formamos la matriz B   
B<-matrix(-8:3,nc=3, byrow= TRUE)       
B
A+B                                 # no es posible realizar la operación
A+t(B)                              # realiza la suma elemento a elemento
A*t(B)                              # realiza el producto elemento a elemento   
C1<-B%*%A                           # producto de matrices  
C1

remove(list=ls()) 


A<-matrix(c(30,18,42,66,45,96,78,42,114),nrow=3, byrow=TRUE)
A
det(A)                            # determinante
eigen(A)                          # diagonaliza la matriz
D<-solve(A)                       # matriz inversa
D
A%*%D
remove(list=ls())  

# ejemplo de bucle 
h <- seq(from=1, to=12)
s <- c()
for(i in 3:15)
   { s[i] <- h[i] * 10 }
s
remove(list=ls())  

# ejemplo simple de gráfica
curve(3*x+10,-10,10)
curve(x^2-3*x+10,-10,10, add=TRUE)
curve(x^3,-10,10, add=TRUE)
curve(x^4,-10,10, add=TRUE)

# Ejercicios de la práctica
# Resuelve el siguiente sistema de ecuaciones
# 7a+6b+3c+2d=10
# 5a+3d=5
# 4a-2b+5c+4=15
# 6b-2c+d=12

# Matriz de coeficientes
# La ecuación 3 la normalizamos y queda:
# 7a+6b+3c+2d=10
# 5a+3d=5
# 4a-2b+5c=11
# 6b-2c+d=12
# Por tanto,
A <- matrix(c(7, 5, 4, 0, 6, 0, -2, 6, 3, 0, 5, -2, 2, 3, 0, 1), ncol = 4)
A
b <- c(10, 5, 11, 12)
b
solve(A, b)

# Construye un vector x con 25 valores aleatorio, calcula su mínimo, su máximo y ordena sus valores de menor a mayor
x <- runif(5, min = 0, max = 10)
x
min(x)
max(x)
sort(x)
# qué es order(x)
order(x)

#=====================
# FIN
#=====================