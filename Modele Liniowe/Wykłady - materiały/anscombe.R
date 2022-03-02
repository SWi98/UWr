library(datasets)
datasets::anscombe

old.par = par()
par(mfrow=c(2,2))
par(mar=c(0.5, 4.5, 0.5, 0.5))

lm1 <- lm(y1 ~ x1, data = anscombe)
lm2 <- lm(y2 ~ x2, data = anscombe)
lm3 <- lm(y3 ~ x3, data = anscombe)
lm4 <- lm(y4 ~ x4, data = anscombe)

#proste regresji s¹ takie same
lm1
lm2
lm3
lm4

#w³asnoœci modeli s¹ takie same
summary(lm1)
summary(lm2)
summary(lm3)
summary(lm4)

#Wykresy rorzutu z prostymi regresji
plot(y1 ~ x1, data = anscombe, col = "blue", lwd = 3)
lines(predict.lm(lm1)~anscombe$x1)
plot(y2 ~ x2, data = anscombe, col = "blue", lwd = 3)
lines(predict.lm(lm2)~anscombe$x2)
plot(y3 ~ x3, data = anscombe, col = "blue", lwd = 3)
lines(predict.lm(lm3)~anscombe$x3)
plot(y4 ~ x4, data = anscombe, col = "blue", lwd = 3)
lines(predict.lm(lm4)~anscombe$x4)

# residua vs x
plot(lm1$residuals~anscombe$x1, col = "blue", lwd = 3) #brak struktury (oczekiwane zachowanie gdy dane pochodz¹ z modelu teoretycznego)
plot(lm2$residuals~anscombe$x2, col = "blue", lwd = 3) #kwadratowa zale¿noœæ
plot(lm3$residuals~anscombe$x3, col = "blue", lwd = 3) #liniowa zale¿noœæ z jedn¹ obs. odstaj¹c¹
plot(lm4$residuals~anscombe$x4, col = "blue", lwd = 3) # dwie podpopulacje x=8, 19, tylko jedna obs. dla x=19




#residua vs index; w miarê poprawne zachowanie 
plot(lm1$residuals, col = "blue", lwd = 3)
plot(lm2$residuals, col = "blue", lwd = 3)
plot(lm3$residuals, col = "blue", lwd = 3) # jedna obserwacja odstaj¹ca
plot(lm4$residuals, col = "blue", lwd = 3)
