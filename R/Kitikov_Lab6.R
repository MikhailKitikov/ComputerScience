# 1

# dataset
library(MASS)
x <- c(rnorm(20, 0, 7/3), rnorm(10, 7, 7/3))
y <- c(rnorm(20, 0, 7/3), rnorm(10, 7, 7/3))
xy <- cbind(x, y)
xy

# 2

# clustering
cl <- kmeans(xy, 2)
n <- 30
n.train <- floor(n * 0.7)
n.test <- n - n.train
idx.train <- sample(1:n, n.train)
idx.test <- (1:n)[!(1:n %in% idx.train)]
data.train <- xy[idx.train,] 
data.test <- xy[idx.test,] 
cl.cluster <- cl$cluster
cl.train <- cl.cluster[idx.train]
cl.test <- cl.cluster[idx.test]

# training & classification
model <- qda(data.train, cl.train) 
cl.test_est <- predict(model, data.test)$class

# error of classification
sum(cl.test_est != cl.test) / n.test
iderr <- idx.test[cl.test_est != cl.test]
iderr

# plots
plot(xy, col = ifelse(cl.cluster == 1,"blue","green"))
legend("topleft",legend = c("1","2"), fill = c("blue","green"))
points(xy[iderr,], col = "red", pch = 3) # errors
points(xy[idx.train,], pch = 2) # training set

# 3

# changing 20% of data
id.change <- sample(1:n.train, n.train * 0.2)
for(i in id.change) cl.train[i] = ifelse(cl.train[i] == 1, 2, 1)

# training
model <- qda(data.train, cl.train) 
cl.test_est <- predict(model, data.test)$class

# error
sum(cl.test_est != cl.test) / n.test
iderr <- idx.test[cl.test_est != cl.test]
iderr

# plots
plot(xy, col = ifelse(cl.cluster == 1, "blue", "green"))
legend("topleft", legend = c("1", "2"), fill = c("blue", "green"))
points(xy[iderr,], col = "red") # errors
points(xy[idx.train[id.change],], pch = 3) # changed data

