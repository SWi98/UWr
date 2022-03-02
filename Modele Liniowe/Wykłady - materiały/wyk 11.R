#Modele z interakcj¹
#======================================================================
#Y is number of months for an insurance company to adopt an innovation
#X1 is the size of the firm (a continuous variable)
#X2 is the type of firm, the value 0 for a mutual fund and 1 for a stock fund

#d <- read.table("CH08TA02.txt", quote="\"", comment.char="")
names(d) = c("months", "size", "stock")
d0 = d[d$stock==0,]
d1 = d[d$stock==1,]

plot(d0$size, d0$months, ylim = range(d$months),pch = 19,lwd = 2
     , xlab = "size", ylab = "months", col = "red")
lines(d1$size, d1$months, col = "blue",type = "p",pch = 19,lwd = 2)
legend("topright",legend=c("stock = 0", "stock = 1"),
       fill=c("red", "blue"))

#Model z interacj¹ sugeruje, ¿e wp³yw jednej zmiennej obj¹sniaj¹cej
#na Y zale¿y od tego jak¹ wartoœci przyjmuj¹ pozosta³e zmienne obj.
#W naszym przypadku oznacza³oby to ró¿ne tempo spadku (wsp. kierunkowy)
#w zale¿noœci od typu firmy.

# model z interakcj¹:
d$sizestock<-d$size*d$stock #nowa zmienna: iloczyn size i stock
reg1 = lm(months~size+stock+sizestock, d);

#proste regresji dla modelu z interakcj¹
y_hat = predict(reg1)
#stock = 0
y_hat0 = y_hat[d$stock==0]
ind0 = order(d0$size)
lines(d0$size[ind0], y_hat0[ind0], col = "red")
#stock = 1
y_hat1 = y_hat[d$stock==1]
ind1 = order(d1$size)
lines(d1$size[ind1], y_hat1[ind1], col = "blue")

#Pytanie: Czy proste regresji dla obu typów firmy s¹ takie same?
#(rownowa¿nie: Intercepty i Slope-y s¹ sobie równe)
reg2 = lm(months~size, d);
anova(reg2,reg1) #ogólny test F odrzuca H_0

#Pytanie: Czym ró¿ni¹ siê obie funkcje?
summary(reg1) #wyniki wskazuj¹ na brak istotnoœci interakcji

#Pytanie: Czy proste s¹ równoleg³e? (brak interakcji)
reg3 = lm(months~size+stock, d);
anova(reg3,reg1) #ogólny test F przyjmuje H_0; interakcja jest nieistotna

#proste regresji dla modelu bez interakcji
y_hat = predict(reg3)
#stock = 0
y_hat0 = y_hat[d$stock==0]
ind0 = order(d0$size)
lines(d0$size[ind0], y_hat0[ind0], col = "red", lwd = 3, lty = 3 )
#stock = 1
y_hat1 = y_hat[d$stock==1]
ind1 = order(d1$size)
lines(d1$size[ind1], y_hat1[ind1], col = "blue", lwd = 3, lty = 3 )


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

