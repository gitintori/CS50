SELECT AVG(r.rating) AS average_rating
FROM ratings r
JOIN movies m ON r.movie_id = m.id
WHERE m.year = 2012;
