#==================================================================
# ESTADÕSTICA - GRADO DE INGENIERÕA INFORM¡TICA - ULL
# PR√ÅCTICA DE LABORATORIO 05: EstadÌstica descriptiva de dos variables
# Profesores de laboratorio: Carlos Gonz·lez MartÌn; Sergio Alonso
#==================================================================


# TABLAS ESTADÕSTICAS DE DOS O M¡S VARIABLES

setwd("Situar aquÌ el directorio de trabajo o donde se halle el dataframe HIPER200")
load("HIPER200.RData")
attach(HIPER200)

# CreaciÛn de una tabla de contingencia dentro de los paquetes b√°sicos de R

tabla1<-table(sal,cafe)
print(tabla1)               #se imprime la tabla de contingencia con frec absolutas
margin.table(tabla1,1)      #se imprime la primera marginal
margin.table(tabla1,2)      #se imprime la segunda marginal
print(prop.table(tabla1))   #se imprime la tabla de contingencia con frec relativas
print(prop.table(tabla1,1), digit=3)  #se imprime TODAS las dist. condicionadas de Y/X
print(prop.table(tabla1,2), digit=2)  #se imprime TODAS las dist. condicionadas de X/Y

# CreaciÛn de una tabla de contingencia con la libreria DescTools 

library(DescTools)
Desc(table(sal,cafe),plotit =FALSE ) #tabla de contingencia+condicionadas+marginal
# se recomienda acudir al help,  buscar Desc y luego rfrq
Desc(table(sal,cafe),rfrq="100",plotit =FALSE ) #tabla de contingencia conjunta
Desc(table(sal,cafe),rfrq="010",plotit =FALSE ) #tabla de contingencia Cafe/Sal
Desc(table(sal,cafe),rfrq="001",plotit =FALSE ) #tabla de contingencia Sal/Cafe
Desc(table(sal,cafe),rfrq="011",plotit =FALSE )
Desc(table(sal,cafe),rfrq="111",plotit =FALSE )
Desc(table(sal,cafe),rfrq="000",plotit =FALSE )

tabla2<-xtabs(~cafe+sal+genero)
print(tabla2)
f3a <- xtabs(~sal+estudios+genero, data=HIPER200)
ftable(f3a) 


# GR¡FICAS CON DOS O M¡S VARIABLES

# diagrama de rectangulos adosados y apilados
t1a<-table(sal,cafe)
print(t1a)
t1b<-table(cafe,sal)
rownames(t1a)<- c("poca", "normal", "mucha")           
colnames(t1a)<- c("no toma", "poco", "moderado", "mucho")
barplot(t1a,beside=TRUE,col=c(2,3,4),legend =rownames(t1a), sub="Cafe")
barplot(prop.table(t1a,2),beside=TRUE,sub="Cafe",col=c(2,3,4),legend =rownames(t1a))


library(lattice)

barplot(prop.table(t1a,2), beside= FALSE, col=c(2,3,4),sub="Cafe",legend.text=rownames(t1a),args.legend=list(x=4, y=0.6,  bg="white", ncol=2))

mosaicplot(t1a, col=c(2,3,4,6),main="Sal y Cafe")
mosaicplot(t1b, col=c(2,3,4),main="Cafe y Sal")

# diagrama de sectores
library(DescTools)
PlotCirc(table(sal,genero))

# Histogramas adosados y apilados
library(lattice)
histogram(~peso|genero) 

#diagrama de cajas
boxplot(peso~estudios)  
library(ggplot2)
qplot(estudios, peso, geom="boxplot")  
library(lattice)
bwplot(~peso|genero, data=HIPER200)

# ESTADISTICOS DESCRIPTIVOS DE UNA VARIABLE CONTINUA POR CADA NIVEL DE UN FACTOR m·s un diagrama de cajas
# se puede utilizar formulas del tipo a~b
library(DescTools)
Desc(peso~sal,HIPER200, digits=2, verbose=c(3),plotit=TRUE)

# o combinacion de variables y factores
Desc(peso+talla~sal+genero,HIPER200, digits=2, verbose=c(3),plotit=TRUE)
Desc(peso~.,HIPER200, digits=2, verbose=c(3),plotit=TRUE)  # pueden salir datos excesivos
Desc(.~sal,HIPER200, digits=2, verbose=c(3),plotit=TRUE)   # pueden salir datos excesivos

#=====================
# FINAL DE LA PR¡CTICA
#=====================

