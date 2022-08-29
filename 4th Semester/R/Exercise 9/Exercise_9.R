library(readxl)

dati<-read_excel("*.xlsx") # [gads|vieta|koncentracija]
head(dati)

modelis<-lm(koncentracija ~ gads, data = dati)

par(mfrow = c(2,2))
plot(modelis)

#Iegutaja attela redzams, ka atlikuma vertibas veido dovas izteiktas grupas,
# kas nozime, ka atlikuma vertibas nav izvietojusas nejausi

is.factor(dati$vieta)
dati$vieta<-as.factor(dati$vieta)

#Ieliekot reizinajuma zimi starp "vieta"(faktors) un "gads", tiek noteikts vai pie vienadas x vertibas y vertibas butiski atskiras
#ka ari parbauda vai taisnem slipumi atskiras vai ne
ancova<-lm(koncentracija ~ vieta * gads, data = dati)

summary(ancova)
#Modelis ir statistiski butisks, jo p vertiba ir <2.2e-16 (mazaks par 0.05)
#Un izskaidro 92.7% no datu variacijas

#Koncentracijas izmaina laika ir butiska. Vietai A katru gadu izmainas piesarnojuma koncentracija par -5.2262,
#bet vietai B par -2.5291 (-5.2262+2.6971)

#Piesarnojuma koncentracijas pieauguma temps starp vietu A un vietu B butiski atskiras, jo
#vietai A un vietai B p vertibas(< 2e-16 un 7.5e-08) ir mazakas par 0.05

#Nepastav statistiski butiska atskiriba starp sakuma piesarnojuma koncentraciju vieta A un vieta B viena gada.
#Jo vietai A, p vertiba ir 2e-16 (mazaks par 0.05), bet vietai B, p vertiba ir 0.489 (lielaks par 0.05)
#Tatad sakotneja koncentracija katra vieta nav butiski atskiriga (vieta A sakuma koncentracija ir 202.6076, bet vieta B 199.0438 (202.6076-3.5683))

#Piesarnojuma koncentracija vieta A: 202.6076 + -5.2262 * gads
#Piesarnojuma koncentracija vieta B: 199.0438 + -2.5291 * gads

library(ggplot2)

#Grafiks, kas parada koncentracijas izmainu laika
#Punktu krasa un trenda linijas krasa ir atkariga no color = vieta
ggplot(dati, aes(gads, koncentracija, color = vieta)) + geom_point() + geom_smooth(method = "lm")






