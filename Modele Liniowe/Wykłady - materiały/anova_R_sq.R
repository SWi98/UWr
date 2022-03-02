#=================================================================
#Dane w zbiorze "CH01TA01.txt" dotycz¹ produkcji elementów do lodówek w fabryce.
#Kolumna "size" opisuje liczbê wyprodukowanych elementów,
#kolumna "hours" opisuje czas poœwiêcony na wprodukowanie elemetów.
#============================================================
time<-read.table('CH01TA01.txt', col.names=c("size", "hours"));
#colnames(time) = c("size", "hours")
reg1 = lm(hours~size,data = time)
#Analiza wariancji
anova(reg1)
#Analiza wariancji a test T dla beta_1
summary(reg1)

#residual standard error
SSE = sum(reg1$residuals^2)
n<-dim(time)[1];
dfE = n-2
MSE = SSE/dfE
s = sqrt(MSE)
s
dfE
summary(reg1)

#R^2
y = time$hours
SST = sum((y-mean(y))^2)
SSM = SST-SSE
R_sq = SSM/SST
summary(reg1)
R_sq

cor(time) # próbkowa macierz korelacji miêdzy X i Y
r = cor(time)[1,2]
r^2
R_sq

#adjusted R^2
dfT = n-1
MST = SST/dfT
R_sq_adj = 1-MSE/MST
summary(reg1)
R_sq_adj


