#### Array ####

# create data vector
data1 <-  c(187,321,431,211)
data2 <- c(100,587,498,967,3567,4030,3888,3021,8765,9999,7867,8799)
data3 <- seq(4560, 7650, length.out = 16) # seq for generate sequence of number
data4 <- ceiling(seq(14640, 25600, length.out = 16)) #ceiling for roundup number

myarray <- array(c(data1,data2, data3, data4), 
                 dim = c(4,4,3),
                 dimnames = list(c("Q1", "Q2", "Q3", "Q4"),
                                 c("Sale1", "Sale2", "Sale3", "Sale4"),
                                 c(2015, 2016, 2017)))

# how array looks like                        
myarray