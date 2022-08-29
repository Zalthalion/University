library(readxl)
library(ggplot2)
library(car)

dati <- read_excel("*.xlsx") # [tips|mitrums|diametrs]

is.factor(dati$tips)
is.factor(dati$mitrums)


dati$tips<-as.factor(dati$tips)
dati$mitrums<-as.factor(dati$mitrums)

leveneTest(y = dati$diametrs, group = dati$tips:dati$mitrums)
#Pie butiskuma limena alfa = 0.05 starp atsevisku gradiacijas klasu dispersijam
#Nepastav statistiski butiska atskiriba jeb dispersijas ir homogenas, jo ieguta p vertiba (0.923) ir lielaka par butiskuma limeni.

modelis <- aov(diametrs ~ tips*mitrums, data = dati)
summary(modelis)
#Pie butiskuma limena alfa = 0.05 koka diametru butiski ietekme meza tips (p vertiba < 2e-16)
# un mitrums (p vertiba = 1.72e-08), bet faktoru kombinacijas ietekme nav butiska (p vertiba = 0.409)

kv.sum <- 3287 + 363 + 33 + 654

3287/kv.sum #mezu tips
363/kv.sum #Mitrums

#Faktora meza tipa ietekmes ipatsvars uz koka diametru ir 75.79%, mitruma ietekmes ipatsvars ir 8.37%


TukeyHSD(modelis, "tips")
#Starp visam gradacijas klasem ir butiska atskiriba(lans-daamaksnis, metrajs-damaksnis, metrajs-lans), jo visas p vertibas < 0.0001 < 0.05
TukeyHSD(modelis, "mitrums")
#Starp visam gradacijas klasem ir butiska atskiriba(sauss-normals, slapjs-normals, slapjs-sauss), jo visas p vertibas < 0.05


#Grafiks, kas parada diametru atskiribas starp mezu 
ggplot(dati, aes(tips, diametrs, fill = mitrums)) + geom_boxplot()
