#==================================================================
# ESTAD?STICA - GRADO DE INGENIER?A INFORM?TICA - ULL
# PR?CTICA DE LABORATORIO 07: Tablas cruzadas o de contingencia - Regresi?n y correlaci?n
# Profesores de laboratorio: Carlos Gonz?lez Mart?n; Sergio Alonso
#==================================================================


# busqueda de los conjuntos de datos
library(datasets.load)   #interfase para cargar datos
datasets.load()

#========================
# CONJUNTO DE DATOS: AUTO
#========================
library(ISLR)
data(Auto)
head(Auto)
str(Auto)
attach(Auto)
Auto$origin<-factor(origin,levels=c(1,2,3),labels=c("American","European","Japanese"),ordered=FALSE)
?Auto
#esta listo para ser usado


#========================
# CONJUNTO DE DATOS: IRIS
#========================
library(datasets)
data(iris)
head(iris)
attach(iris)
?iris
#esta listo para ser usado


#===========================
# CONJUNTO DE DATOS: TITANIC
#===========================
data("titanic", package = "COUNT")
head(titanic)
str(titanic)
attach(titanic)
?titanic
??titanic
#esta listo para ser usado


#=====================
# FINAL DE LA PR?CTICA
#=====================
