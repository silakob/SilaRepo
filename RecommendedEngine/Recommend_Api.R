#* @filter cors
function(res){
  res$setHeader("Access-control-Allow-Origin","*")
  plumber::forward()
}
#* @get /recommend
function(usr_id){
  con <- dbConnect(MariaDB(), host='localhost', user='root', password='', dbname='movielens')
  queryString <- ''
  #usr_id <- 1
  queryString <- paste0('SELECT ', usr_id, ' as usr_id, ', 
                        'mov_id FROM movies WHERE CONCAT( ',
                        usr_id, ', ",",mov_id ) NOT IN (',
                        'select concat(scr_usr_id, ",",scr_mov_id) ',
                        'from scores where scr_usr_id= ',
                        usr_id, ')')
  
  #print(queryString)
  result <- dbSendQuery(con,queryString)
  unrated <- dbFetch(result)
  #print(rated)
  dbClearResult(result)
  dbDisconnect(con)
  #View(rated)
  
  
  ### Load Data From Database
  need_data <- data_memory(unrated$usr_id,
                           unrated$mov_id,
                           index1 = TRUE) ### set index start from 1
  
  #need_data
  predict <- recommender$predict(need_data,out_memory())

  #View(predict)


  ###Top 10 most scores
  top_score <- sort(predict,decreasing = TRUE)[1:10]

 
  ###Match top 10 scores with movie_ID
  index <- match(top_score,predict)
  list(slot(need_data,'source')[2][[1]][index],
       top_score)
}
