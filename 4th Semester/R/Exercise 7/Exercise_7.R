library(readxl)
dati<-read_excel("*.xlsx") #[vecums|diametrs]
dati


modelis <- lm(diametrs ~ vecums, data = dati)
summary(modelis)

#Katru gadu (vecuma vienibu) koka diametrs palielinas par 0.59992 vienibam

#Gan viss linearas regresijas modelis kopuma (p-value: < 2.2e-16), gan atseviski si modela koeficienti (4.24e-07 un < 2e-16) ir butiski, jo
#p vertibas ir mazakas par butiskuma limeni 0.05

#Koka vecums izskaidro 63.61%, no diametra vertibu variesanas

#Regresijas vienadojums: diametrs = 19.71611 + 0.599992 * vecums

par(mfrow = c(2,2))
plot(modelis)

#Atlikuma vertibas atbilst normalajam sadalijumam, to var redzet Normal Q-Q grafika
#Atlikuma vertibas ir nejausi izkliedetas un nav noverojams trends, to var redzet Residuals vs Fitted grafika
#Datos nav neviens noverojums, kas butiski ietekmetu rezultatu (ietekmigu noverojumu nav), to var redzet Residuals vs Leverage grafika. Neviena atlikuma vertiba nav zem raustitas linijas, jo linija nav redzama.
#Secinu: regresijas analizes rezultats ir interpretejams, jo neviens no pienemumiem nav parkapts

library(ggplot2)

#Grafiks ar regresijas likni
ggplot(dati, aes(vecums, diametrs)) + geom_point() + geom_smooth(method = "lm")
