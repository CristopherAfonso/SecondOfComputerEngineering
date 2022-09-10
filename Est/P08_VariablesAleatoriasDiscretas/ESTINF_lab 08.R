#==================================================================
# ESTADÍSTICA - GRADO DE INGENIERÍA INFORMÁTICA - ULL
# PRÁCTICA DE LABORATORIO 08: Principales distribuciones discretas
# Profesores de laboratorio: Carlos González Martín; Sergio Alonso
#==================================================================

#  Además de las tablas estadíssticas de la asignatura, es posible realizar con
#  mayor disponibilidad los cálculos habituales de las distribuciones estadísticas
#  mediante algunos comandos de R

#  Un ejemplo, para el caso de la binomial es
#      dbinom(x, size, prob, log = FALSE)                         cálculo de la probabilidad
#      pbinom(q, size, prob, lower.tail = TRUE, log.p = FALSE)    cálculo de la función de distribución
#      qbinom(p, size, prob, lower.tail = TRUE, log.p = FALSE)    cálculo de cuantiles
#      rbinom(n, size, prob)                                      generación de números aleatorios   

library(visualize)                #libreria para representar distribuciones
library(descriptr)                #libreria para representar algunas distribuciones

# CÁLCULO Y VISUALIZACIÓN DE PROBABILIDADES E INVERSA DE PROBABILIDADES, CUANTILES, DE VARIAS DISTRIBUCIONES DISCRETAS

#=====================================================================
# 1. Uniforme{1,2,...,9}   distribucion UNIFORME en {1,2,...,n}, unif
#=====================================================================
# Recordemos que la distribución uniforme de tamaño n asigna igual probabilidad a los n sucesos posibles

library(HH) #esta librería es para visulaización de datos

x<-1:9
plot(x, ddiscunif(x,size=9), ylim=c(0,0.12), xlim=c(1,9),type = "h", lwd=3, col="blue",lab=c(9,7,7),main="DistribuciÃ³n Uniforme (1:9)",xlab="valores")
pdiscunif(3,size=9)   # valor de la probabilidad en 3

x<-3
plot(x, ddiscunif(x,size=9), ylim=c(0,0.12), xlim=c(1,9),type = "h", lwd=3, col="blue",lab=c(9,7,7),main="Distribución Uniforme (1:9)",xlab="valores")
pdiscunif(3,size=9)   # función de distribución en 3

x<-1:3
plot(x, ddiscunif(x,size=9), ylim=c(0,0.12), xlim=c(1,9),type = "h", lwd=3, col="blue",lab=c(9,7,7),main="Distribución Uniforme (1:9)",xlab="valores")
1-pdiscunif(3,size=9)  # 1 - funciÃ³n de distribuciÃ³n en 3

x<-4:9
plot(x, ddiscunif(x,size=9), ylim=c(0,0.12), xlim=c(1,9),type = "h", lwd=3, col="blue",lab=c(9,7,7),main="Distribución Uniforme (1:9)",xlab="valores")
pdiscunif(7,size=9) -pdiscunif(3,size=9)  #combinando dos expresiones

x<-4:7
plot(x, ddiscunif(x,size=9), ylim=c(0,0.12), xlim=c(1,9),type = "h", lwd=3, col="blue",lab=c(9,7,7),main="Distribución Uniforme (1:9)",xlab="valores")
1-(pdiscunif(7,size=9) -pdiscunif(3,size=9))  #combinando  expresiones

x<-c(1:3,8:9)
plot(x, ddiscunif(x,size=9), ylim=c(0,0.12), xlim=c(1,9),type = "h", lwd=3, col="blue",lab=c(9,7,7),main="Distribución Uniforme (1:9)",xlab="valores")

qdiscunif(0.4,size=9)  # cuantil de orden 0.4 de la uniforme discreta utilizada (punto crítico)
x<-1:9
plot(x, pdiscunif(x,size=9), type = "S", col="red",lab=c(9,7,7),lwd=3, main="Función de distribución de una U(1,...,9)")
abline(h=0.4, lty="dashed",col="red",lwd=2)

#==============================================================
# 2. BINOMIAL (12,0.25)  distribucion BINOMIAL__ B(n,p)
#==============================================================
# Recordemos que la binomial es el resultado de realizar n pruebas de Bernoulli independientes de probabilidad p y contar los éxitos
# Por tanto, los valores posibles de la binomial son 0, 1, 2, ... n-1, n.
# Ver en https://www.rdocumentation.org/packages/descriptr/versions/0.4.1/topics/dist_binom_plot la documentación sobre dist_binom_plot
# Ver en https://www.rdocumentation.org/packages/visualize/versions/4.3.0/topics/visualize.binom la documentación sobre visualize.binom

dbinom(3,size=12,prob=0.25)   # valor de la probabilidad en 3
dbinom(3,12,0.25)   # valor de la probabilidad en 3
dist_binom_prob(12, 0.25, 3, type = "exact") #atención, esta función será descartada por R en breve

x<-0:12
plot(x, dbinom(x, 12, 0.25), type = "h", col="red",main="Distribución de probabilidades Bi(12,0.25)",xlab="valores")

pbinom(3,12, 0.25)   # función de distribución en 3
dist_binom_prob(12, 0.25, 3, type = 'lower')
pbinom(3,12, 0.25, lower.tail=FALSE)  # 1 - función de distribución en 3, esto es, suceso complementario

visualize.binom(stat=c(2,5), size=12, prob=0.25, section ="tails", strict=TRUE) #probabilidad de colas

pbinom(6,12, 0.25) -pbinom(3,12, 0.25)  #combinando dos expresiones, valores 6, 5, 4.
dist_binom_prob(12, 0.25, c(4, 6), type = 'interval') 
1-(pbinom(6,12, 0.25) -pbinom(3,12, 0.25))  #combinando  expresiones, el complementario al anterior
visualize.binom(stat=c(4, 6), size=12, prob=0.25, section ="tails", strict=TRUE) #usando colas, tails

sum(dbinom(30:54, 100, 0.25)) #si el primer parámetro es un vector, devuelve un vector de probabilidades
visualize.binom(stat=c(30, 54), size=100, prob=0.25, section ="bounded") #usando acotado, bounded

qbinom(0.4,12, 0.25)  # cuantil de orden 0.4 de la binomial utilizada (punto crítico)
#gráfica de la funcion de distribución para los cuantiles solicitados
x<-0:12
plot(x, pbinom(x, 12, 0.25), type = "s", col="red", main="Función de distribución de una Bi(12,0.25)")
abline(h=0.4, lty="dashed",col="red",lwd=2)
qbinom(0.4,12, 0.25, lower.tail=FALSE)    # cuantil de orden 0.6 de la binomial utilizada (punto crítico)
abline(h=0.6, lty="dashed",col="red",lwd=2)

#asimetría o simetría según el valor de p
dist_binom_plot(12, 0.25)
dist_binom_plot(12, 0.50)
dist_binom_plot(12, 0.75)

#==============================================================
# 3. GEOMÉTRICA distribución GEOMETRICA__Geo(p)  
#==============================================================
# Recordemos que la distribución geométrica se construye también sobre pruebas de Bernoulli independientes con idéntica probabilidad de éxito, y contamos
# el número de pruebas necesarias hasta tener el primer éxito.

dgeom(10,0.25)   # valor de la probabilidad en 10

visualize.geom(stat=c(10, 100), prob=0.001,  section ="bounded", strict=FALSE) # mostramos los primeros valores posibles de la geométrica y sus probabilidades sumando los menores o iguales de 10

pgeom(10,0.25)   # función de distribución en 10
visualize.geom(stat=10,  prob=0.25, section ="lower")
pgeom(10,0.25, lower.tail=FALSE)  # 1 - funciÃ³n de distribuciÃ³n en 10
visualize.geom(stat=10, prob=0.25, section ="upper", strict=TRUE)
pgeom(30,0.25) -pgeom(10,0.25)  #combinando dos expresiones
visualize.geom(stat=c(10,31), prob=0.25,  section ="bounded", strict=TRUE)
1-(pgeom(30,0.25) -pgeom(10,0.25))  #combinando  expresiones
visualize.geom(stat=c(10,31), prob=0.25,  section ="tails")

qgeom(0.38,0.25)  # cuantil de orden 0.38 de la geométrica utilizada (punto crítico)
qgeom(0.38,0.25, lower.tail=FALSE)    # cuantil de orden 0.62 de la geométrica

#=============================================================================
# 4. BINOMIAL NEGATIVA (5,0.25)  distribución BINOMIAL NEGATIVA__BiNeg(r,p)  
#=============================================================================
# Recordemos que la distribución binomial negativa se construye también sobre pruebas de Bernoulli independientes con idéntica probabilidad de éxito, y contamos
# el número de pruebas necesarias hasta tener r éxitos. Si el número de éxitos a cumplir es 1, coincide con la geométrica.


dnbinom(10,5, 0.25)   # valor de la probabilidad en 10
visualize.nbinom(stat=c(10,10),  size=5, prob=0.25,  section ="bounded", strict=FALSE)

pnbinom(10,5, 0.25)   # función de distribución en 10
visualize.nbinom(stat=10,  size=5, prob=0.25, section ="lower")
pnbinom(10,5, 0.25, lower.tail=FALSE)  # 1 - función de distribución en 10
visualize.nbinom(stat=10,  size=5, prob=0.25, section ="upper", strict=TRUE)
pnbinom(30,5, 0.25) -pnbinom(10,5, 0.25)  #combinando dos expresiones
visualize.nbinom(stat=c(10,31),  size=5, prob=0.25,  section ="bounded", strict=TRUE)
1-(pnbinom(30,5, 0.25) -pnbinom(10,5, 0.25))  #combinando  expresiones
visualize.nbinom(stat=c(10,31),  size=5, prob=0.25,  section ="tails")

qnbinom(0.38,5, 0.25)  # cuantil de orden 0.38 de la binomial negativa utilizada (punto crítico)
qnbinom(0.38,5, 0.25, lower.tail=FALSE)    # cuantil de orden 0.62 de la binomial negativa utilizada 

#gráfica de la funciÃ³n de distribución para los cuantiles solicitados
x<-0:70
plot(x, pnbinom(x, 5, 0.25), type = "s", col="red")
abline(h=0.38, lty="dashed",col="red",lwd=2)
abline(h=0.62, lty="dashed",col="red",lwd=2)
#comprobación del cuantil 0.38
pnbinom(11,5, 0.25)
pnbinom(12,5, 0.25)

#===============================================================================
# 5. HIPERGEOMÉTRICA (3,6,5)  distribucion HIPERGEOMETRICA__H(m,n,k) o  H(N,n,r)
#===============================================================================
# Recordemos que para construir una hipergeométrica, consideramos un conjunto de N objetos de los cuales k están marcados como éxitos, y el resto, como fracasos.
# Extraemos al azar una muestra de tamaño n que no supere N, y contamos el número de objetos éxito, x, de la muestra, que es el valor de la variable aleatoria.
# Para el sufijo hyper los parámetros son, en este orden: x (valor de éxitos de la muestra), m (éxitos), n (fracasos), k (muestra)

dhyper(2,3,6,5)   # valor de la probabilidad en 2, para 3 éxitos, 6 fracasos y tamaño muestral 5
visualize.hyper(stat=c(2, 2),   m=3, n=6, k=5,  section ="bounded",strict=FALSE)

phyper(2,3,6,5)   # función de distribución en 2
visualize.hyper(stat=2,  m=3, n=6, k=5, section ="lower")
phyper(2,3,6,5,lower.tail=FALSE)  # 1 - función de distribución en 2
visualize.hyper(stat=2,  m=3, n=6, k=5, section ="upper", strict=TRUE)
phyper(2,3,6,5) -phyper(0,3,6,5) #combinando dos expresiones
visualize.hyper(stat=c(1, 2),   m=3, n=6, k=5,  section ="bounded",strict=FALSE)
1-(phyper(2,3,6,5) -phyper(0,3,6,5))  #combinando  expresiones
visualize.hyper(stat=c(1, 2),  m=3, n=6, k=5,  section ="tails", strict=TRUE)

qhyper(0.40,3,6,5)  # cuantil de orden 0.4 de la HipergeomÃ©trica utilizada (punto crítico)
qhyper(0.40,3,6,5, lower.tail=FALSE)    # cuantil de orden 0.6 de la Hipergeométrica utilizada (punto crítico)

#==============================================================
# 6. POISSON (2.1)  distribución POISSON__ P(lambda)
#==============================================================
# Recordemos que la variable aleatoria discreta Poisson de parámetro lambda se aplica a modelos aleatorios que miden en número de sucesos que se producen
# por periodo de tiempo y por unidad de longitud, superficie... Su parámetro, lambda, es su media


dpois(5,2.1)   # valor de la probabilidad en 5
visualize.pois(stat=c(5, 5),  lambda=2.1,  section ="bounded", strict=FALSE)

ppois(5,2.1)   # función de distribución en 5
visualize.pois(stat=5,  lambda=2.1, section ="lower")
ppois(5,2.1, lower.tail=FALSE)  # 1 - función de distribución en 5
visualize.pois(stat=5,   lambda=2.1, section ="upper", strict=TRUE)
ppois(7,2.1) -ppois(3,2.1) #combinando dos expresiones
visualize.pois(stat=c(3, 8),  lambda=2.1,  section ="bounded", strict=TRUE)
1-(ppois(7,2.1) -ppois(3,2.1))  #combinando  expresiones
visualize.pois(stat=c(3, 8),  lambda=2.1,  section ="tails")
sum(dpois(5:21, 2.1))
visualize.pois(stat=c(5, 21), lambda=2.1, section ="bounded")

qpois(0.35,2.1)  # cuantil de orden 0.35 de la Poisson utilizada (punto crítico)
qpois(0.35,2.1, lower.tail=FALSE)    # cuantil de orden 0.65 de la Poisson utilizada (punto crítico)


#=====================
# FINAL DE LA PRÁCTICA
#=====================
