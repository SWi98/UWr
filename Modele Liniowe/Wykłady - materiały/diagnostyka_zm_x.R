#=================================================================
#Dane w zbiorze "CH01TA01.txt" dotycz¹ produkcji elementów do lodówek w fabryce.
#Kolumna "size" opisuje liczbê wyprodukowanych elementów,
#kolumna "hours" opisuje czas poœwiêcony na wprodukowanie elemetów.
#============================================================
time<-read.table('CH01TA01.txt', col.names=c("size", "hours"));
#colnames(time) = c("size", "hours")

#===========================
#w³asnoœci zmiennej zale¿nej
#===========================
#podstawowe charakterystyki
x = time$size
summary(x)
sd(x)
IQR(x)
#rysunki
hist(x)
boxplot(x)
qqnorm(x)
qqline(x)
plot(x)
