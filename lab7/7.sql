-- energia média das músicas de Drake
SELECT AVG(energy) FROM songs
JOIN artists ON artists.id = artist_id
WHERE artists.name = 'Drake'
