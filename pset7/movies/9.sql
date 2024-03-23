SELECT name FROM people
JOIN stars ON people.id = person_id
JOIN movies ON movie_id = movies.id
WHERE year = 2004 GROUP BY people.id
ORDER BY birth
