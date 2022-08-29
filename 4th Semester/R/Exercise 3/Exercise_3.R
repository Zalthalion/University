library(readxl)
dati <- read_excel("*.xlsx")
library(ggplot2)
ggplot(dati, aes(Veids, Svars)) + geom_boxplot()#ðo grupu svars atðíiras - kontroles grupas svara vçrtîbas ir daudz mazâkas. Vçl var pateikt to, ka mçslojuma grupas vçrtîbâm ir liela vçrtîbu amplitûda.
ggplot(dati, aes (Temperatura, Pieaugums)) + geom_point()
#Vislielâkais pieaugums ir pie 15 grâdu temperatûras, jo 15 grâdu temperatûrai grafikâ atbilst vislilelâkâs pieauguma vçrtîbas
ggplot(dati, aes(sample=Pieaugums)) + geom_qq() + geom_qq_line()
#Paraugkopa "pieaugums" atbilst normâlam sadalîjumam, jo lielâkâ daïa vçrtîbu aptuveni atrodas uz un ap lîniju
shapiro.test(dati$Pieaugums)
#Paraugkopa "pieaugums" atbilst normâlam sadalîjumam, jo p-value=0,314, kas ir lielâka par bûtiskuma lîmeòa (alfa=0,05) vçrtîbu
