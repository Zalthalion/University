library(readxl)
dati <- read_excel("*.xlsx") # [Svars|Veids|Pirms|Pec]

# ~METODES PAMATOJUMS~
# 1) Dati ir kvantitativi
# 2) Dispersijas ir homogenas
# 3) Paraugkopu noverojumi ir neatkarigi
# 4) Dati atbilst normalajam sadalijumam

tapply(dati$Svars, dati$Veids, shapiro.test) #Gan meslojuma, gan kontroles grupu datu sadalijums butiski neatskiras no normala sadalijuma, jo iegutas p-vertibas (p-value = 0.0868, p-value = 0.9787) ir lielakas par butiskuma limeni (alfa = 0.05)

var.test(dati$Svars ~ dati$Veids) #salidzina dispersijas ar F testu. Secina, ka ir homogenas dispersijas

t.test(dati$Svars ~ dati$Veids, var.equal = TRUE)

#Pie butiskuma limena 0.05 pastav statistiski butiska atskiriba starp kontroles grupu un meslojuma grupu videjiem augu svariem (p-vertiba ir 3.175e-11, kas ir mazaka par butiskuma limeni 0.05)
#Videjo aritmetisko starpibas 95% ticamibas intervals ir (-22.09345; -12.83055) sis intervals nesatur 0, tatad atskiriba ir butiska
#Meslojuma grupas svars ir lielaks, jo Videjo aritmetisko starpibas intervals ir negativs (un pats videjais aritmetiskais ir lielaks)

# ~METODES PAMATOJUMS~
# 1) Dati ir kvantitativi
# 2) Dati ir atkarigi/saistiti
# 3) Dati neatbilst normalajam sadalijumam

shapiro.test(dati$Pirms)#p-value = 3.097e-13, kas ir daudz mazaka par butiskuma limeni (alfa = 0.05), tatad neatbilst datu normalajam sadalijumam
shapiro.test(dati$Pec)#p-value = 5.026e-14, kas ir daudz mazaka par butiskuma limeni (alfa = 0.05), tatad neatbilst datu normalajam sadalijumam

wilcox.test(dati$Pirms, dati$Pec, paired = TRUE)

#Saimnieciskas darbibas uzsaksana maina putnu skaitu, 
#jo pie butiskuma limena 0.05, pastav statistiski butiska atskiriba starp putnu skaitu pirms un pec saimnieciskas darbibas uzsaksanas 
#(p-vertiba = 0.001266, kas ir mazaka par butiskuma limeni).

t.test(dati$Pirms, dati$Pec, paired = TRUE)

#Pirms saimnieciskas darbibas uzsaksanas putnu skaits ir lielaks neka pec tas
#To secina pec ta, ka videja paru starpiba ir pozitiva vertiba (14.24)
