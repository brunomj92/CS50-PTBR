--nomes das músicas de Post Malone
SELECT songs.name FROM songs
JOIN artists ON artists.id = artist_id
WHERE artists.name = 'Post Malone'
