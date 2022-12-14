#==================================================================
# ESTAD?STICA - GRADO DE INGENIER?A INFORM?TICA - ULL
# PR?CTICA DE LABORATORIO 04: Estad?stica descriptiva de una variable (2)
# Profesores de laboratorio: Carlos Gonz?lez Mart?n; Sergio Alonso
#==================================================================


# Comandos utiles para buscar los conjuntos de datos (datasets) disponibles en R
# tanto del paquete b?sico como de diferentes librer?as que se van a?adiendo

# Se necesita instalar las librerias: datasets, HSAUR3, load, plyr y DescTools

data()   # muestra los datasets de la libreria datasets (conjunto de datos de las librerias base)
library(help="datasets")  #mismo efecto que la sentencia anterior

data(iris) #carga una librer?a de datos del conjunto
iris

library(HSAUR3)
ls("package:HSAUR3")             #indica en la consola los datasets asociados a esa libreria 
ls("package:datasets")

library(datasets.load)   #interfase para cargar datos
datasets.load()   #permite cargar datos de datasets asociados a las librerias instaladas desde una ventana emergente
getDatasetInfo()  #nos indica el directorio de los actuales datasets disponibles
datasets(package="HSAUR3")   #nos indica el directorio de los datasets asociados a la libreria especifica

dat <- as.data.frame(data(package = .packages(all.available = TRUE))$results)  #nos indica el directorio de los actuales datasets

ls()

help.start()   # nos proporciona ayuda a diferentes niveles de informaci?n


# ESTAD?STICA DESCRIPTIVA DE UNA VARIABLE

# CONJUNTO DE DATOS: AUTO
library(ISLR)
data(Auto)
head(Auto)

attach(Auto)
str(Auto)

Auto$origin<-factor(origin,levels=c(1,2,3),labels=c("American","European","Japanese"),ordered=FALSE)

#esta listo para ser usado


# CONJUNTO DE DATOS: DIAMONDS
data("diamonds", package = "ggplot2")
head(diamonds)
str(diamonds)
attach(diamonds)

#esta listo para ser usado
#diamonds$dee<-2*z/(x+y)


# CONJUNTO DE DATOS: SKULLS
data("skulls", package = "HSAUR3")
head(skulls)
str(skulls)
#esta listo para ser usado


#=====================
# FINAL DE LA PR?CTICA
#=====================