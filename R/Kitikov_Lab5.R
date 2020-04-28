# читаем данные

dat <- read.table("data.txt", dec=",")
dat

# строим диаграмму рассеивани€

plot(dat, type="p", main="коррел€ционное поле", xlab="X", ylab="Y")

# нормализаци€

avg_x <- mean(dat[,1])
av_dev_x <- sd(dat[,1])
dat[,1] <- (dat[,1] - avg_x) / av_dev_x
var(dat[,1])

avg_y <- mean(dat[,2])
av_dev_y <- sd(dat[,2])
dat[,2] <- (dat[,2] - avg_y) / av_dev_y
var(dat[,2])


# разбиваем на 2 кластера

cl <- kmeans(dat, 2)
table(cl$cluster)

# центры кластеров

cl$centers

# график классовой принадлежности с цветом

plot(dat, col = ifelse(cl$cluster == 1, "blue", "green"))

legend("topleft", legend = c("1", "2"), fill = c("blue", "green"))

# график классовой принадлежности с формой

plot(dat, pch = ifelse(cl$cluster == 1, 1, 2))

legend("topleft", legend = c("1", "2"), pch = c(1, 2))


# разбиваем на 3 кластера

cl <- kmeans(dat, 3)
table(cl$cluster)

# центры кластеров

cl$centers

# график классовой принадлежности с цветом

plot(dat, col = ifelse(cl$cluster == 1, "blue", ifelse(cl$cluster == 2, "green", "red")))

legend("topleft", legend = c("1", "2", "3"), fill = c("blue", "green", "red"))

# график классовой принадлежности с формой

plot(dat, pch = ifelse(cl$cluster == 1, 1, ifelse(cl$cluster == 2, 2, 3)))

legend("topleft", legend = c("1", "2", "3"), pch = c(1, 2, 3))
