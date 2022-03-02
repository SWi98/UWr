#==================================
piza <- data.frame (piza)
reg1<-lm(LEAN~YEAR, piza )
reg1
summary(reg1)
reg1$residuals
confint(reg1)

#===================================
#Moc testu dla beta_1 = 1.5
n<-25; 
sig2<-2500; 
ssx<-19800; 
alpha<-.05; 
sig2b1<-sig2/ssx; 
df=n-2;
tc<-qt(1-alpha/2,df);
beta1 = 1.5
delta<-beta1/sqrt(sig2b1);
prob1<-function(delta){pt(tc,df,delta)}
prob2<-function(delta){pt(-tc,df,delta)}
power<-1-prob1(delta)+prob2(delta);
power

#Funkcja mocy testu
beta1<-seq(from=-2.0, to= 2.0, by= .05);
delta<-beta1/sqrt(sig2b1);
prob1<-function(delta){pt(tc,df,delta)}
prob2<-function(delta){pt(-tc,df,delta)}
power<-1-prob1(delta)+prob2(delta);
plot(beta1,power,type='l', ylim = c(0,1))
abline(h = 0.05, col = "red") 
   
