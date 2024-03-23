SELECT name FROM people
JOIN directors ON people.id = person_id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON ratings.movie_id = movies.id
WHERE rating >= 9.0 GROUP BY people.id
