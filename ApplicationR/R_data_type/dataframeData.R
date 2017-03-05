#### Data Frame ####

# create data vectors
c1 <- 1:10
c2 <- rep(c("Red", "Blue", 'Green', "Yellow", 'Purple'), 2)
c3 <- abs(rnorm(10)) # abs for absolute, rnorm for random number
c4 <- rep("Shade", 10) # rep for replicate "Shade" ten times
c5 <- rep(c(0,1), 5)

# combine above vectors as data frame
ColorData <- data.frame(ID = c1,
                        Name = c2,
                        Weight = c3,
                        Type = c4,
                        Class = c5,
                        Role = rep(c("root", 'user')),
                        Token = (c1*rnorm(1))) # Token will be calculated column

# how data frame looks like
ColorData

View(ColorData)