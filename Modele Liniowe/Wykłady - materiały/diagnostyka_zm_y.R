#Liniowoœæ
#funkcja kwadratowa zamiast liniowej
x<-seq(1:30);
eps<-rnorm(30);
y<-x^2-10*x+30+25*eps;
reg<-lm(y~x);
summary(reg);
p<-predict(reg);
plot(y~x);
lines(p~x);
r<-residuals(reg);
plot(r~x);
abline(h = 0)

#Niezale¿noœæ
#Silna zale¿noœæ pomiêdzy ka¿d¹ kolejn¹ par¹ obserwacji
require(MASS)
x<-seq(1:30);
#eps<-numeric(30) 
S = matrix(0.99,2,2) + 0.01*diag(c(1,1))
S
for(i in 1:15) eps[c(2*i-1,2*i)] = mvrnorm(1,c(0,0),S)
y<--10*x+30+25*eps;
reg<-lm(y~x);
summary(reg);
p<-predict(reg);
plot(y~x);
lines(p~x);
r<-residuals(reg);
plot(r~x);
abline(h = 0)

#Sta³oœæ wariancji
#przyrost wariancji ze wzrostem x
x<-seq(1:100);
y<-100*x+30+10*x*rnorm(100);
reg<-lm(y~x);
p<-predict(reg);
r<-residuals(reg);
plot(y~x);
lines(p~x);
plot(r~x);
abline(h = 0)

#Normalnoœæ
time<-read.table('CH01TA01.txt', col.names=c("size", "hours"));
#colnames(time) = c("size", "hours")
reg1<-lm(hours~size, time);
r<-residuals(reg1);
h<-hist(r, breaks = seq(min(r)-0.1,max(r)+0.1,length.out = 8));
m<-mean(r);
s<-sd(r);
xfit<-seq(min(r),max(r),length=40);
d<-dnorm(xfit,m,s);
d <- d*diff(h$mids[1:2])*length(r) 
lines(d~xfit, col='blue');
qqnorm(r)
qqline(r)
shapiro.test(r)


#Obserwacje odstaj¹ce
#Przyk³ad obs. odstaj¹cej wp³ywaj¹cej na Intercept i s^2, 
#ale nie wp³ywaj¹cy na Slope
x<-seq(from=1, to=100, by=5);
y<-30+50*x+200*rnorm(20);
x1<-50;
y1<-30+50*50+10000;
x2<-c(x,x1);
y2<-c(y,y1);
reg1<-lm(y~x);
reg2<-lm(y2~x2);
summary(reg1);
summary(reg2);

p<-predict(reg2);
plot(y2~x2);
lines(p~x2);
r<-residuals(reg2);
plot(r~x2);
abline(h=0)

#Przyk³ad obs. odstaj¹cej wp³ywaj¹cej na Slope, 
x3<-100;
y3<-30+50*100-10000;
x4<-c(x,x3);
y4<-c(y,y3);
reg3<-lm(y4~x4);
summary(reg3);


p<-predict(reg3);
plot(y4~x4);
lines(p~x4);
r<-residuals(reg3);
plot(r~x4);
abline(h=0)


#Œrodki zaradcze
#Brak liniowoœci
#przyk³ad 1
x<-(seq(1:30))^2;
e<-rnorm(30);
y<-sqrt(x)+30+e;
reg<-lm(y~x);
summary(reg);
p<-predict(reg);
plot(y~x);
lines(p~x);
r<-residuals(reg);
plot(r~x);
abline(h = 0)

x2 = sqrt(x)
reg<-lm(y~x2);
summary(reg);
p<-predict(reg);
plot(y~x2);
lines(p~x2);
r<-residuals(reg);
plot(r~x2);
abline(h = 0)

#przyk³ad 2
x<-seq(1:30);
eps<-rnorm(30);
y<-x^2-10*x+30+25*eps;
reg<-lm(y~x);
summary(reg);
p<-predict(reg);
plot(y~x);
lines(p~x);
r<-residuals(reg);
plot(r~x);
abline(h = 0)

x_tilde = x^2
reg2<-lm(y~x+x_tilde);
summary(reg2);
p<-predict(reg2);
plot(y~x);
lines(p~x);
r<-residuals(reg2);
plot(r~x);
abline(h = 0)


#Transformacja Boxa-Coxa
require(MASS)
plasma<-read.table('plasma.txt',
               col.names=c("age", "plasma"));
#colnames(plasma) = c("age", "plasma")
plot(plasma$plasma~plasma$age)
boxcox(plasma$plasma~plasma$age)
plot((plasma$plasma)^(-0.5)~plasma$age)
