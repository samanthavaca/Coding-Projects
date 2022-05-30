SELECT DISTINCT name FROM people
JOIN stars on people.id = stars.person_id
JOIN movies on stars.movie_id = movies.id
WHERE name != "Kevin Bacon"
AND movies.id IN (
    SELECT stars.movie_id FROM stars
    JOIN people on stars.person_id = people.id
    WHERE name = "Kevin Bacon" AND birth = 1958
)