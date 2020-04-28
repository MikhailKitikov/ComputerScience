# читаем данные

dat <- read.table("data.txt", dec=",")
dat


# строим диаграмму рассеивани€

plot(dat, type="p", main=" оррел€ционное поле", xlab="X", ylab="Y")

x <- dat[,1]
x
y <- dat[,2]
y


# создаем таблицу распределени€ факторных признаков

sr <- mean(x)
sigma <- sd(x)
rows <- paste("(", sr - (1:3) * sigma, ", ", sr + (1:3) * sigma, ")", sep = "")
rows

t <- rep(0, 3*4)
dim(t) <- c(3,4)
t <- as.data.frame(t)
t

sz <- length(x)
sz

t[,1]<-paste("(", sr - (1:3) * sigma, ", ", sr + (1:3) * sigma, ")", sep = "")

cnt1 <- 0
for(i in 1:sz) 
  if(x[i] > sr - sigma && x[i] < sr + sigma) 
    cnt1<-cnt1+1
t[1,2]<-cnt1
t[1,3]<-cnt1*100/sz

cnt2 <- 0
for(i in 1:sz) 
  if(x[i] > sr - 2 * sigma && x[i] < sr + 2 * sigma) 
    cnt2<-cnt2+1
t[2,2]<-cnt2
t[2,3]<-cnt2*100/sz

cnt3 <- 0
for(i in 1:sz) 
  if(x[i] > sr - 3 * sigma && x[i] < sr + 3 * sigma) 
    cnt3<-cnt3+1
t[3,2]<-cnt3
t[3,3]<-cnt3*100/sz

t[1,4]<-68.3
t[2,4]<-95.4
t[3,4]<-99.7
  
t


# исключаем аномальные признаки

bools <- (x >= sr - 3 * sigma & x <= sr + 3 * sigma)
x <- x[which(bools)]
dat[,1] <- x
dat[,1]
y <- y[which(bools)]
dat[,2] <- y
dat[,2]


# группируем по признаку-фактору

sz <- length(x)

n <- 1 + floor(log2(sz))
n

h <- (max(x) - min(x)) / n
h

tab <- rep(0, n * 4)
dim(tab) <- c(n, 4)
tab <- as.data.frame(tab)
tab

tempx <- min(x)

gr <- x

for(i in 1:n) {
  
  if (i != n) tab[i, 1] <- paste("[", tempx, "; ", tempx + h, ")")
  else tab[i, 1] <- paste("[", tempx, "; ", tempx + h, "]")
  cnty <- 0
  
  for(j in 1:sz) {
    if (dat[j, 1] >= tempx & (dat[j, 1] < tempx + h | (i == n & dat[j, 1] == max(x)))) {
      tab[i, 2] <- tab[i, 2] + 1
      tab[i, 3] <- tab[i, 3] + dat[j, 2]
      cnty <- cnty + 1
    }
  }
  if (cnty != 0) tab[i, 4] <- tab[i, 3] / cnty
  tempx <- tempx + h
}

tab


# коэффициент коррел€ции

coef_cor <- cor(dat[,1], dat[,2])
coef_cor

t_cor <- abs(coef_cor) * sqrt((sz - 2) / (1 - coef_cor ^ 2))
t_cor

alpha <- 0.01
alpha
t_tabl <- 2.5
t_tabl

if (t_cor > t_tabl) znach = TRUE else znach = FALSE
znach


# уравнение регрессии

lm(y ~ x)

abline(lm(y~x))

sd(x)
sd(y)

b <- coef_cor * sd(y) / sd(x)
b
a <- mean(y) - b * mean(x)
a
