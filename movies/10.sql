SELECT DISTINCT name FROM people
JOIN directors on people.id = directors.person_id
JOIN ratings on directors.movie_id = ratings.movie_id
WHERE rating >= "9.0"