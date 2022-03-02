eps=rnorm(100)
x1=runif(100, 0,1)
x2=runif(100, 4.5,4.65)
x3=runif(100,0.1,0.2)
x4=runif(100,2,5)
x5=runif(100, -2,1)

y=2*x1+3*x2+x3-2*x4+5*x5-4+eps

DataF=data.frame(y,x1,x2,x3,x4,x5)


plot(y~x1, pch=19, col="blue")
plot(y~x2, pch=19, col="blue")
plot(y~x3, pch=19, col="blue")
plot(y~x4, pch=19, col="blue")
plot(y~x5, pch=19, col="blue")


LinMod=lm(y~x1+x2+x3+x4+x5, DataF) 

summary(LinMod) 

a=summary(LinMod) 


a$coefficients
a$coefficients[,3]

library("car")
an=anova(LinMod) #Type 1 sum of squares  
An=Anova(LinMod) #Type 2 sum of squares  

an$`Sum Sq`

