n=100
p=6
set.seed(100)
eps=rnorm(100)
x1=runif(100, 0,0.1) #0,1
x2=runif(100, 0.2,0.55) #0,35
x3=runif(100,0.1,0.25) #0,15
x4=runif(100,2,5) #3
x5=runif(100, -2,1) #3

y=2*x1+3*x2+x3-2*x4+5*x5-4+eps

DataF=data.frame(y,x1,x2,x3,x4,x5)


LinMod=lm(y~., DataF) 

summary(LinMod)


AIC(LinMod)


#AIC

SSE=sum(residuals(LinMod)^2)
aic=n*log(SSE/n)+2*p
aic


#Partial regression plots

#dla x1:

LM1=lm(y~x2+x3+x4+x5, DataF) 
LM2=lm(x1~x2+x3+x4+x5, DataF)
plot(residuals(LM1)~residuals(LM2))

#dla x5:

LM1=lm(y~x1+x2+x3+x4, DataF) 
LM2=lm(x5~x1+x2+x3+x4, DataF)
plot(residuals(LM1)~residuals(LM2))


#the studentized deleted residuals

r = rstudent(LinMod)  # studentyzacja zewnêtrzna

qqplot(r,rt(100, n-1-p))
qqline(r)

boxplot.stats(r)$out


# dla modele lin z obzerw odst 


x5[50]=200

DataF=data.frame(y,x1,x2,x3,x4,x5)

LM3=lm(y~., DataF) 

summary(LM3)


r = rstudent(LM3)  # studentyzacja zewnêtrzna

qqplot(r,rt(100, n-1-p))
qqline(r)

boxplot.stats(r)$out



#DFFITS

df<-dffits(LinMod)

which(abs(df)>2*sqrt(p/n))

df<-dffits(LM3)

which(abs(df)>2*sqrt(p/n))


#tolerance

library("HH")

tolerance=1/vif(LinMod)

which(tolerance<0.1)

x6=2*x1-3*x3+5*x5+rnorm(100,0,0.0001)
DataF1=data.frame(y,x1,x2,x3,x4,x5,x6)

LM4=lm(y~., DataF1) 

summary(LM4)

tolerance=1/vif(LM4)

which(tolerance<0.1)


#AIC, BIC:

library("leaps")
all1<- regsubsets(y ~ ., nbest=3, DataF);
summ<-summary(all1);
cbind(summ$bic, summ$which)






a=sort(x1, index.return=T)
a$ix
a=summary(LinMod) 


a$coefficients
a$coefficients[,3]

library("car")
an=anova(LinMod) #Type 1 sum of squares  
An=Anova(LinMod) #Type 2 sum of squares  




