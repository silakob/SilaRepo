setwd('E:\\Recommended_Engine')
### Connect Database
library(DBI)
library(RMariaDB)
library(recosystem)
con <- dbConnect(MariaDB(), host='localhost', user='root', password='', dbname='movielens')
queryString <- ''
queryString <- paste0('SELECT ',
                      'scr_usr_id,scr_mov_id,scr_rating ',
                      'FROM scores')


result <- dbSendQuery(con,queryString)
rated <- dbFetch(result)
#print(rated)
dbClearResult(result)
dbDisconnect(con)
View(rated)


### Load Data From Database
train_data <- data_memory(rated$scr_usr_id,
                          rated$scr_mov_id,
                          rated$scr_rating,
                          index1 = TRUE) ### set index start from 1

View(train_data)
recommender <- Reco()
param <- recommender$tune(train_data,
                          opts = list(dim = c(20,30,40),
                          niter = 10))
#param


recommender$train(train_data,
                  opts = c(param$min,
                           niter = 10,
                           verbose = FALSE))

out <- recommender$output(out_memory(),
                          out_memory())

View(out$P)