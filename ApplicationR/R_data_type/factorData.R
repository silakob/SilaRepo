#### Factor ####

# create dummy vector (I generate 100 data records in 5 classes with the following probability accordingly)
Tee.size <- sample(x = c("XXL", "XL", "S", "M", "L"), 
                  size = 100, 
                  replace = TRUE, 
                  prob = c(0.15, 0.25, 0.3, 0.2, 0.2))

# see how levels looks like
levels(Tee.size)

# NULL, right? we should define levels for it
Tee.size <- factor(Tee.size, levels = c("S", "M", "L", "XL", "XXL"))

# let's check it again
levels(Tee.size)