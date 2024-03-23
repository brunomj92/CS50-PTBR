SELECT title FROM movies
JOIN stars ON movie_id = movies.id
JOIN people ON people.id = person_id
WHERE name = 'Johnny Depp'
AND title IN (SELECT title FROM movies
JOIN stars ON movie_id = movies.id
JOIN people ON people.id = person_id
WHERE name = 'Helena Bonham Carter')
