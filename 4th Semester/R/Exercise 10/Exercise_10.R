data(malaria, package = "ISwR")
head(malaria)

malaria_glm1 <- glm(mal ~ age + ab, data = malaria, family = binomial())
summary(malaria_glm1)

#Pie butiskuma limena 0.05 pastav statistiski butiska ietekme starp antivielu daudzumu un malarijas risku (p vertiba = 0.412)
#savukart starp vecumu un malarijas risku nepastav statistiski butiska ietekme (p vertiba = 0.2542)

malaria_glm2 <- glm(mal ~ ab, data = malaria, family = binomial())
summary(malaria_glm2)

anova(malaria_glm1, malaria_glm2, test = "Chisq")

#Ta ka starp abiem modeliem nepastav statistiski butiska atskiriba (p vertiba ir 0.2485),
#tad var izveleties vienkarsako modeli, kas saja gadijuma ir 2. modelis

#Malarijas iespejamibas vertibu prognoze
predict(malaria_glm2, type = "response")

library(ggplot2)
#Grafisks attelojums, kur uz x ass ir antivielu daudzums
#un uz y ass ir malarijas riska vertibas
ggplot(malaria, aes(ab, mal, color = mal)) + geom_point() + geom_smooth(method = "glm", method.args = list(family = "binomial"))
                                                           
#No grafika var izsecinat, ka palielinoties antivielu skaitam, risks saslimt ar malariju samazinas
