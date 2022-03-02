#=================================================================
#Dane w zbiorze "CH01TA01.txt" dotycz¹ produkcji elementów do lodówek w fabryce.
#Kolumna "size" opisuje liczbê wyprodukowanych elementów,
#kolumna "hours" opisuje czas poœwiêcony na wprodukowanie elemetów.
#=================================================================
time<-read.table('CH01TA01.txt', col.names=c("size", "hours"));
#colnames(time) = c("size", "hours")
#W naturalny sposób relacja powinna byæ w przybli¿eniu liniowa.
plot(hours~size, time)
reg1<-lm(hours~size, time);
#Chcemy wiedzieæ ile godzin musimy œrednio poœwiêciæ aby uzyskaæ "x" elemetów.
new <- data.frame(size = c(65,100));

#Funkcja "predict()"
# predykcja dla nowych danych i estymator dla œredniej E(Y_h)
predict(reg1, new)
# estymator + przedzia³ ufnoœci dla œredniej E(Y_h)
predict(reg1, new, interval='confidence') 
# estymator + standard errors dla œredniej E(Y_h)
predict(reg1, new,se.fit=TRUE)

# predykcja + przedzia³ predykcyjny dla Y_h
predict(reg1, new, interval='prediction') 

#=======================================================================
#UWAGA
# bez wzglêdu na typ przedzia³u "interval"
# funkcja predict() zawsze zwraca standard errors dla œredniej E(Y_h)
predict(reg1, new,se.fit=TRUE, interval='confidence')
predict(reg1, new,se.fit=TRUE, interval='prediction')
#=======================================================================


# Pasmo ufnoœci dla prostej regresji
v<-predict(reg1,se.fit=TRUE);
s<-v$se.fit;
m<-v$fit;
alpha<-0.1;
n<-dim(time)[1];
w<-sqrt(2*qf(1-alpha,2,n-2));
up<-m+w*s;
down<-m-w*s;
size1<-sort(time$size);
hours1<-sort(time$hours);
m1<-sort(m);
up1<-sort(up);
down1<-sort(down);
plot(time$size,time$hours);
points(size1,m1,type='l');
points(size1,up1,type='l',col='red')
points(size1,down1,type='l',col='red')
# Prawdziawa prosta regresji "f(x) = beta_0+beta_1x$
# znajduje siê pomiêdzy czerwonymi krzywymi z prawdopodobieñstwem 0.9
#========================================================================



#========================================================================
#Przedzia³ ufnoœci dla œredniej E(Y_h) vs. przedzia³ predykcyjny dla Y_h 
v1<-predict(reg1, interval='prediction')
v1down<-sort(v1[,2]);
v1up<-sort(v1[,3]);
v2<-predict(reg1,interval='confidence')
v2down<-sort(v2[,2]);
v2up<-sort(v2[,3]);

plot(size1,m1,type='l', ylim = c(35,600));
points(time$size,time$hours);
points(size1,v1up,type='l',col='red');
points(size1,v1down,type='l',col='red');
points(size1,v2up,type='l',col='green');
points(size1,v2down,type='l',col='green');
# Uwagi:
#1. Przedzia³y predykcyjne (czerwony) s¹ szersze od przedzia³ów ufnoœci(zielony).
#2. Du¿o punktów le¿y poza obszarem ograniczonym zielonymi prostymi
#   (przedzia³y ufnoœci dla œredniej E(Y_h)).
#3. Wszystkie punkty le¿¹ wewn¹trz obszaru ograniczonego czerwonymi prostymi.
#4. Powy¿sze zachowanie jest zgodne z teori¹. Czerwone proste ³¹cz¹ 
#   odpowienio górne i dolne krañce (nierównoczesnych) 95% przedzia³ów predykcyjnych,
#   dlatego oczekujemy ¿e oko³o 5% obserwacji bêdzie le¿a³o poza obszarem
#   ograniczonym czerwonymi prostymi. W naszym przypadku mamy n=25 obserwacji,
#   w zwi¹zku z tym oczekujemy ¿e oko³o 1 obserwacja bêdzie le¿a³a poza pasmem 
#   wyznaczonym przez czerwone linie. Z wykresu widzimy, ¿e bliska tej sytuacji
#   jest obserwacja uzyskana dla "size" = 30 o najwy¿szej wartoœci "time".

