# чтение данных

dat <- read.table("data.txt", dec=",")
t <- dat[,1]
x <- dat[,2]
t
x

f <- as.data.frame(dat)
f

n <- length(x)
n

# средний уровень динамики

avgLevel <- (sum(x) - (x[1] + x[n]) / 2) / (n-1)
avgLevel

# критерий серий

for(i in 1 : n) {
  if (x[i] < avgLevel) f[i,3] = 0 
  else f[i,3] = 1
}
  
f

# доверительный интервал

lowbound <- (n + 1 - 3 * sqrt(n - 1)) / 2
upperbound <- (n + 1 + 3 * sqrt(n - 1)) /2
lowbound
upperbound

# трехуровневая скользящая средняя

f[1, 4] = (5 * f[1, 2] + 2 * f[2, 2] - f[3, 2]) / 6
f[n, 4] = (5 * f[n, 2] + 2 * f[n - 1, 2] - f[n - 2, 2]) / 6
for (i in 2 : (n - 1)) f[i, 4] = (x[i - 1] + x[i] + x[i+ 1]) / 3
f

# аналитическое выравнивание

f[1, 5] <- -12
for (j in 2 : n) f[j, 5] = f[j - 1, 5] + 1
for (j in 1 : n) f[j, 6] = f[j, 5] * f[j, 5]
for (j in 1 : n) f[j, 7] = f[j, 2] * f[j, 5]
f

a0 <- sum(f[,2]) / n
a1 <- sum(f[,7]) / sum(f[,6])
a0
a1

for (j in 1 : n) 
  f[j, 8] = f[j, 5] * a1 + a0
f

prognoz <- a1 * 13 + a0
prognoz

x <- f[,1]
y <- f[,2]
z <- f[,4]
u <- f[,8]

# вывод данных

# исходные данные
plot(x, y, ylim = range(c(y,z, u)), type="l", col="blue", lwd = 2)
par(new = TRUE)

# трехуровневая скользящая средняя
plot(x, z, ylim=range(c(y,z,u)), axes = FALSE, type="l",  col="red", xlab = "", ylab = "", lwd = 2)
par(new = TRUE)

# метод аналитического выравнивания
plot(x, u, ylim=range(c(y,z,u)), axes = FALSE, type="l",  col="green", xlab = "", ylab = "", lwd = 2)
