library(readxl)
dati2 <- read_excel("*.xlsx")
head(dati2)
library(ggplot2)
ggplot(dati2, aes(koki, diametrs)) +
  geom_point(aes(colour = Tips, shape = Tips)) + 
  labs(x="Koku skaits",y="Diametrs (cm)", title="Koku skaita un diametra saistîba", Color="meþa tips") + 
  theme(plot.title = element_text(colour = "grey24"), plot.background = element_rect(fill = "grey74"))
                                                
                                                