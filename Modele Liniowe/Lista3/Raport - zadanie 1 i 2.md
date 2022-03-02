## Zadanie 1
*a) Use R to find the critical value that you would use for a two-tailed t signicance test with
α = 0.05 and 10 degrees of freedom. Call this value tc.*



```{r}
tc = qt(0.975, 10)
```

Tc wynosi 2.228139.



*b) Use R to find the critical value that you would use for an F significance test with α = 0.05,
one degree of freedom in the numerator and 10 degrees of freedom in the denominator.
Call this value Fc.*



```{r}
Fc = qf(1 - .05, 1, 10)
```



Fc wynosi 4.964603.



*c) Verify that the square of tc is Fc*



```{r}
tc * tc
```

```{r}
[1] 4.964603
```

tc podniesione do kwadratu jest równe Fc. 





## Zadanie 2



Dana tabelka ANOVA:

||df|SS|
|-|-|-|
|Model|1|100|
|Error|20|400|



*a) How many observations do you have in your file ?*

Korzystając ze wzoru dfE = n -2, otrzymujemy n = 22, co oznacza, że posiadamy 22 obserwacje.



*b) Calculate the estimate of σ.*

Skorzystam ze wzoru: $s^2 = SSE/dfE$, gdzie: $s^2$ - estymator $\sigma^2$

Otrzymuję: $ s^2 = 400 / 20\ =>\ s \approx 4,4721 $



*c) Test if β1 is equal to zero. (Give the test statistic with the numbers of degrees of freedom and the conclusion).*

Testujemy $H_0: \beta_1 = 0\ vs\ H_1: \beta_1 \neq 0$
Liczymy statystykę testową F ze stopniami swobody 1 i 20: $ F = MSM/MSE \\ F = \dfrac{SSM/dfM}{SSE/dfE} = \dfrac{100}{400/20} = 5$

Liczymy Fc:

```{r}
Fc = qf(1 - 0.05, 1, 20)
```

Fc wyniosło 4.3512, co jest mniejsze od F, więc możemy odrzucić: $H_0:\beta_1 = 0$

*d) What proportion of the variation of the response variable is explained by your model?*



Skorzystamy ze wzoru na współczynnik determinacji, który mówi, jaka część całkowitej zmienności w wektorze Y stanowi zmienność wyjaśniona przez model: $ R^2 = SSM/SST,\ gdzie:\ SST=SSM+SSE\\ R^2 = 100/500 = 0.2$

Wynika z tego, że 20% zmienności w wektorze Y stanowi zmienność wyjaśniona przez model.  



*e) What is the sample correlation coefficient between your response and explanatory variables?*



Skorzystam z faktu, że obliczony wcześniej współczynnik determinacji jest tożsamy z kwadratem próbkowej korelacji Pearsona pomiędzy zmiennymi zależną i niezależną.  Wynika z tego, że korelacja wynosi: $\pm \sqrt{0.2}$

