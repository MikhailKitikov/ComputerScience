# Считываем данные из файла
dat<-read.table(file="input.txt", dec=",")
d<-dat[,1]
d

# cреднее значение
mean(d)

# дисперсия
disp<-var(d)
disp

# среднее квадратическое отклонение (1 способ)
sd(d)

# среднее квадратическое отклонение (2 способ)
sqrt(disp)

# Первое значение – это мода, а второе – на какой позиции в вариационном ряду находится мода
which.max(table(d))

# Медиана
median(d)

# Коэффициент асимметрии

  # библиотека
#install.packages("fBasics")
library(fBasics)
asim_lib<-skewness(d)
asim_lib
  # по формуле
a<-table(d)
a
allval<-sort(unique(d))
allval
mean_d<-mean(d)
mean_d
n<-length(d)
n
mean_sqr<-sd(d)
mean_sqr
asim_formula<-sum((allval-mean_d)^3*a)/(n*mean_sqr^3)
asim_formula

# Коэффициент эксцесса

  # библиотека
kurtosis(d)
  # по формуле
dispersion<-var(d)
dispersion
coeff_ex<-(sum((allval-mean_d)^4*a)/(n*mean_sqr^4))-3
coeff_ex

# усеченное среднее порядка 6/48=0,125
v<-sort(d)
v
szv<-length(v) 
szv
s<-sum(v[7:42])
s
a<-(1/(szv-2*6))*s
a

# коэффициент вариации
koeff_var<-100*sqrt(var(d))/mean(d)
koeff_var

# относительное линейное отклонение
otn_lin<-sum(abs(v[1:48]-mean(d)))*100/(48*mean(d))
otn_lin
