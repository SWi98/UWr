piza <- data.frame (piza)
reg1<-lm(LEAN~YEAR, piza )
c1<-predict.lm(reg1)
plot(LEAN~YEAR, piza)
lines(c1~YEAR, piza)
summary(reg1)
new<-data.frame(YEAR = c(100))
u<-predict(reg1,new)
u
