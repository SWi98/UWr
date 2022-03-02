#===============================================================================
#Dane dotycz¹ wyników studentów informatyki na jednej z amerykañskich uczelni
#zmienne:
#gpa - odpowiednik œredniej z 3 semestrów nauki
#hsm - odpowiednik œredniej z ocen z matematyki z liceum (high school math)
#hss - odpowiednik œredniej z ocen z przedmitów œcis³ych z liceum (high school science)
#hse - odpowiednik œredniej z ocen z j. angielskiego (high school english)
#satm - ustandaryzowany test dla uczniów szkó³ œrednich w USA z matematyki
#satv - ustandaryzowany test dla uczniów szkó³ œrednich w USA ze zdolnoœci jêzykowych (verbal)
#gen - p³eæ
#===============================================================================
#csdata <- read.table("csdata.txt")
names(csdata) = c("id", "gpa", "hsm",
                  "hss", "hse", "satm", "satv",
                  "gen");

pairs(csdata[,2:7])
#AIC
m1 = lm(gpa~hsm, csdata)
m2 = lm(gpa~hsm+hss, csdata)
AIC(m1)
AIC(m1,m2)

#kilka na raz
require("leaps")
b<- regsubsets(gpa~hsm+hss+hse+satm+satv, nbest=3, csdata);
u<-summary(b);
cbind(u$bic,u$cp, u$rsq, u$which)

#================================================
#Y is amount of life insurance
#X1 is average annual income
#X2 is a risk aversion score
#n = 18 managers
#================================================
#d <- read.table("ch10ta01.txt")
names(d) = c("income", "risk", "insurance")

old.par = par()
par(mfrow = c(2,2),mar = c(4, 4, 0.5, 0.5) + 0.1)
#klasyczne wykresy rozrzutu
plot(insurance~income, d)
plot(insurance~risk  , d)

#Partial regression plots
#income
m1 = lm(insurance~risk, d)
m2 = lm(income   ~risk, d)
plot(m1$residuals~m2$residuals, 
     xlab = "income(risk) res.",
     ylab = "insurance(risk) res.")
#risk
m1 = lm(insurance~income, d)
m2 = lm(risk     ~income, d)
plot(m1$residuals~m2$residuals, 
     xlab = "risk(income) res.",
     ylab = "insurance(income) res.")
old.par

#=============================================================
#studentyzacja residuów
reg1 = lm(insurance~income + risk, d)
r  = residuals(reg1)
r1 = rstandard(reg1) # studentyzacja wewnêtrzna
r2 = rstudent(reg1)  # studentyzacja zewnêtrzna
cbind(r, r1, r2)

#=============================================================
#diagonala macierzy H
H_diag = hatvalues(reg1)
H_diag
#które H_ii s¹ daleko od œredniej 3/18?
which(as.vector(H_diag)>2*(3/18))
H_diag[c(6,7)]        # wartoœci du¿ych H_ii
plot(income~risk,d)   # X1 vs X2
points(mean(d$income)~mean(d$risk), col = "blue", pch = 19) #centrum X-ów
points(income~risk,d[c(6,7),], col="red",pch = 19) #po³o¿enie 6 i 7 obserwacji

#=======================================================
#DFFITS, COOKS DISTANCE, DFBETAS, VIF, TOLERANCE
x1<-dffits(reg1);
x2<-cooks.distance(reg1);
x3<-dfbeta(reg1);
res<-cbind(x1,x2,x3);
res
require("HH");
v<-vif(reg1);
v
