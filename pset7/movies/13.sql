SELECT DISTINCT name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.id IN
(SELECT movies.id FROM movies
JOIN people ON people.id = stars.person_id
JOIN stars ON stars.movie_id = movies.id
WHERE name = 'Kevin Bacon'
AND birth = 1958)
AND name != 'Kevin Bacon'