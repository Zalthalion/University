# Needed libraries
library(readxl)
library(ggplot2)
library(cowplot)
library(Hmisc)
library(ggpmisc)

# Reads data from specified file [tips|mitrums|diametrs]
dati <- read_excel("*.xlsx")

# Graph that contains forest type on x axis and diameter on y axis
# The figure shows the average confidence interval - divided by groups
plot.ticamibas <- ggplot(dati, aes(tips, diametrs, shape = mitrums)) +
  stat_summary(fun.data = "mean_cl_normal",
               position = position_dodge(width = 0.25))

plot.ticamibas

# This graph shows dispersion data between Sepal.Length un Sepal.Width
# Picture is divided into three parts based on species
plot.izkliede <- ggplot(iris, aes(Petal.Length, Petal.Width)) + geom_point() +
  facet_grid(Species ~ ., space = "free")

plot.izkliede

# Both previously created graphs are united into a single photo
# They are place one above other and labeled A and B
plot_grid(plot.izkliede, plot.ticamibas, labels = c("A", "B"), nrow = 2)