# ��������� ������ �� �����
dat<-read.table(file="input.txt", dec=",")
d<-dat[,1]
d

# c������ ��������
mean(d)

# ���������
disp<-var(d)
disp

# ������� �������������� ���������� (1 ������)
sd(d)

# ������� �������������� ���������� (2 ������)
sqrt(disp)

# ������ �������� � ��� ����, � ������ � �� ����� ������� � ������������ ���� ��������� ����
which.max(table(d))

# �������
median(d)

# ����������� ����������

  # ����������
#install.packages("fBasics")
library(fBasics)
asim_lib<-skewness(d)
asim_lib
  # �� �������
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

# ����������� ��������

  # ����������
kurtosis(d)
  # �� �������
dispersion<-var(d)
dispersion
coeff_ex<-(sum((allval-mean_d)^4*a)/(n*mean_sqr^4))-3
coeff_ex

# ��������� ������� ������� 6/48=0,125
v<-sort(d)
v
szv<-length(v) 
szv
s<-sum(v[7:42])
s
a<-(1/(szv-2*6))*s
a

# ����������� ��������
koeff_var<-100*sqrt(var(d))/mean(d)
koeff_var

# ������������� �������� ����������
otn_lin<-sum(abs(v[1:48]-mean(d)))*100/(48*mean(d))
otn_lin
