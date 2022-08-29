library(readxl)
dati <- read_excel("*.xlsx")
tapply(dati$Svars, dati$Veids,median)
tapply(dati$Svars, dati$Veids,var)
tapply(dati$Svars, dati$Veids,quantile, probs=c(0.05))
#Râdîtâji atðíiras. Mçslojuma grupai dispersijas vçrtîba ir lielâka (741,3), bet kontroles grupai mazâka (214.62). Tas liecina, ka mçslojuma grupas vçrtîbu vidçjâ kvadrâtiskâ novirze no grupas vidçjâ lieluma ir lielâka - tâtad dati ir vairâk novirzîti no vidçjâ lieluma vçrtîbas.
library(Hmisc)
library(ggplot2)       
ggplot(dati, aes(Veids, Svars))+stat_summary(fun.data = "mean_cl_normal")
#secinâjums: Mçslojuma grupas dati ir mazâk precîzi, jo to ticamîbas intervâls ir plaðâks par kontroles grupas ticamîbas intervâlu
smean.cl.normal(dati$Temperatura, conf.int=0,999)
