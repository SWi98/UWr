eps=rnorm(25)
x=runif(25, 0,10)
y=2*x+3+eps

plot(y~x, pch=19, col="blue")

DataF=data.frame(y,x)

LinMod=lm(y~x, DataF) #model liniowa

summary(LinMod) # wszystkie rodzaje cech modele liniowej 

abline(a=LinMod$coefficients[1],b=LinMod$coefficients[2], lwd=2)

LinMod$coefficients #wartosci hat(b_0), hat(beta_1)

LinMod$residuals  #wartosci bledów

LinMod$fitted.values  #wartosci na prostej

points(LinMod$fitted.values~x, col="red", pch=19)

confint(LinMod)  #przedzialy ufnosci dla hat(b_0), hat(beta_1)

#predict

predict(LinMod)    #predykcja dla LinMod w punktach x

predict(LinMod)-LinMod$fitted.values

X0=data.frame(x=c(5))

b=predict(LinMod, X0)   #predykcja dla LinMod w punkcie x=5

a=LinMod$coefficients

b-a[1]-5*a[2]

X0=data.frame(x=c(1:10)) #predykcja dla LinMod w punktach 1:10

predict(LinMod, X0)


X0=data.frame(x=c(5))

predict(LinMod, X0, interval = "confidence")  #predykcja dla x=5+ przedzial ufnosci

predict(LinMod, X0, interval = "prediction")  #predykcja dla x=5+ przedzial predykcyjny

