#===============================================================================
#Dane dotycz¹ wyników studentów informatyki na jednej z amerykañskich uczelni
#zmienne:
#gpa - odpowiednik œredniej z 3 semestrów nauki
#hsm - odpowiednik œredniej z ocen z matematyki z liceum (high school math)
#hss - odpowiednik œredniej z ocen z przedmitów œcis³ych z liceum (high school science)
#hse - odpowiednik œredniej z ocen z j. amgielskiego (high school english)
#satm - ustandaryzowany test dla uczniów szkó³ œrednich w USA z matematyki
#satv - ustandaryzowany test dla uczniów szkó³ œrednich w USA ze zdolnoœci jêzykowych (verbal)
#gen - p³eæ
#===============================================================================
#csdata <- read.table("csdata.txt")
names(csdata) = c("id", "gpa", "hsm",
                    "hss", "hse", "satm", "satv",
                    "gen");
reg1<-lm(gpa~hsm+hss+hse, csdata);
summary(reg1);

#przedzia³y ufnoœci dla parametrów w wekt. beta; domyœlnie "level = 0.95"
confint(reg1, level = 0.8)

#przedzia³y ufnoœci dla danych ze zbioru treningowego
predict(reg1, interval='confidence')

#przedzia³y ufnoœci dla nowych wartoœci regresorów
x_new = data.frame(hsm = c(1,2),hss = c(2,1),hse = c(5,1) )
x_new
predict(reg1, newdata = x_new, interval='confidence')

#przedzia³y predykcyjny dla nowych wartoœci regresorów
predict(reg1, newdata = x_new, interval='prediction')
