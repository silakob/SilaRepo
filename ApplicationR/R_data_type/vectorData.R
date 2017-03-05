#### Vector ####

# create dummy vector
vec_1 <- c(1,3,-5,7,-9)
vec_2 <- 1:100
vec_3 <- c("A", 'B', "C", "D")

# how vector looks like
vec_1
vec_2
vec_3

# now I will try adding different type of atomic to my vector and see what's happen

vec_4 <- c(1,2,3)

class(vec_4) # check class of vector

vec_4 #see how it looks

# numeric it is!

vec_4 <- c(1,2,3,2.3) # try add 2.3

class(vec_4) # check class again

vec_4 # see how it looks

# but still showing numeric, right? try the following function
is.double(vec_4)
is.integer(vec_4)

# all good? yep. becuase double is one of numeric class

vec_4 <- c(1,2,3,2.3,"potato") # try add character.

# see how it looks like
vec_4