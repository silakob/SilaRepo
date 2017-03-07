#### List ####

#---------------------------------------------------------------

#### Atomic ####

# create dummy atomic
A <- 2017 #numeric
B <- 'My name is Py' #character
C <- 20L #integer
D <- "Z" #character
E <- TRUE #logic
F <- F #logic
G <- 3.3.2 #double

#---------------------------------------------------------------

#### Vector ####

# create dummy vector
vec_1 <- c(1,3,-5,7,-9)
vec_2 <- 1:100
vec_3 <- c("A", 'B', "C", "D")


# now I will try adding different type of atomic to my vector and see what's happen

vec_4 <- c(1,2,3)

class(vec_4) # check class of vector

vec_4 #see how it looks

# numeric it is!

vec_4 <- c(1,2,3,2.3) # try add 2.3

class(vec_4) # check class again


# but still showing numeric, right? try the following function
is.double(vec_4)
is.integer(vec_4)

# all good? yep. becuase double is one of numeric class

vec_4 <- c(1,2,3,2.3,"potato") # try add character.

#---------------------------------------------------------------

#### Factor ####
# create dummy vector (I generate 100 data records in 5 classes with the following probability accordingly)
Tee.size <- sample(x = c("XXL", "XL", "S", "M", "L"), 
                  size = 100, 
                  replace = TRUE, 
                  prob = c(0.15, 0.25, 0.3, 0.2, 0.2))


# NULL, right? we should define levels for it
Tee.size <- factor(Tee.size, levels = c("S", "M", "L", "XL", "XXL"))

# let's check it again
levels(Tee.size)

#---------------------------------------------------------------

#### Matrix ####

# create matrix 3x3
matrixA <- matrix(c(1,5,2,9,7,7,3,5,7), nrow = 3, ncol = 3)


# create matrix by combining three vectors
v1 <- 1:10
v2 <- 90:81
v3 <- 100:109

matrixB <- cbind(v1,v2,v3)


#---------------------------------------------------------------

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


#---------------------------------------------------------------
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

#----------------------------------------------------------------

# check what we have in our environment (obj/var name)
ls()

# combine objects we have into list
final.list <- list(A, B, C, D,
                   v1, v2, v3,
                   vec_1, vec_2, vec_3,
                   c1, c2, c3, c4, c5,
                   matrixA, matrixB,
                   data1, data2, data3, data4,
                   ColorData)

# how list looks like
final.list