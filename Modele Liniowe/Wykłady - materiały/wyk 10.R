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
#=====================================================
#analiza wariancji 

#klasyczny test F
#model pe³ny
m_f<-lm(gpa~hsm+hss+hse, csdata);
#model zredukowany
m_r<-lm(gpa~1, csdata);
anova(m_r,m_f) # najpierw H_0, nastêpnie H_1
summary(m_f);
anova(m_f,m_r)

#=================
#ogólny test F
#model pe³ny
m_f<-lm(gpa~hsm+hss+hse, csdata);
#model zredukowany
m_r<-lm(gpa~hsm, csdata);
anova(m_r,m_f) # tak samo jak klasyczny test f

#=================
#równowa¿noœæ testu F i testu T dla testowania
#istotnoœci \beta_i
m_r1 = lm(gpa~hsm+hss, csdata);
anova(m_r1,m_f) 
summary(m_f);
anova(m_r1,m_f)$F
summary(m_f)$coef[4,3]^2

anova(m_f)
#=============================================
#Analiza wariancji - dodatkowe sumy
#20 healthy female subjects
# Y is body fat
#X1 is triceps skin fold thickness
#X2 is thigh circumference
#X3 is midarm circumference
#==================================================
#d <- read.table("ch07ta01.txt")
names(d) = c("skinfold",
             "thigh", "midarm", "fat");

reg1<-lm(fat~skinfold+thigh+midarm, d);
summary(reg1);
#Indywidualne testy istotnoœci dla ka¿dego parametru
#wskazuj¹ na brak wp³ywu regresorów na poziomie 0.05.
#Jednoczeœnie analiza wariancji wskazuje
#na du¿y, ³¹czny wp³yw regresorów. O co tu chodzi?
#Spójrzmy na oba typy sum kwadratów:
anova(reg1)   #suma typu I
require("car")
Anova(reg1)   #suma typu II
summary(reg1);
#korelacja miêdzy zmiennymi
round(cor(d[,1:3]),2)
reg2<-lm(fat~skinfold, d);
summary(reg2);
anova(reg2,reg1)

#Standaryzacja danych
require(QuantPsyc)
lm.beta(reg1)
reg1
reg1$coefficients[2]*sd(d$skinfold)/sd(d$fat)

#Multikolinearnoœæ
#wp³yw korelacji dwóch zmiennych 
#na mksymaln¹ wartoœæ w³asn¹ macierzy (X'X)^(-1)
require(MASS)
ro = seq(0,0.99,0.01)
lam_max = numeric(length(ro))

for(i in 1: length(ro)){
  S = matrix(ro[i],2,2)+(1-ro[i])*diag(c(1,1))
  X = mvrnorm(100,c(0,0),S)
  lam_max[i] = max(eigen(solve(t(X)%*%X))$values)
}
plot(seq(0,0.99,0.01), lam_max, xlab = "ro", main = "lambda_max((X'X)^(-1)) vs ro")

#Dodatkowa zmienna liniowo zale¿na od innych:
d$st = d$skinfold+d$thigh
m1<-lm(fat~skinfold+thigh, d);
m2<-lm(fat~skinfold+thigh+st, d);
summary(m1)
summary(m2) # lm() "widzi" ¿e 'st' zale¿y liniowo od innych zmiennych
