SELECT title FROM movies
JOIN stars on stars.movie_id = movies.id
JOIN people on stars.person_id = people.id
WHERE name = "Johnny Depp"
AND movies.id IN (
    SELECT stars.movie_id FROM stars
    JOIN people on stars.person_id = people.id
    WHERE name = "Helena Bonham Carter"
)