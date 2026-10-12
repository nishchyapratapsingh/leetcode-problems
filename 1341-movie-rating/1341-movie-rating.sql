# Write your MySQL query statement below
WITH ref1 AS(
    SELECT user_id,
        COUNT(*) AS ratingsbyuser
    FROM MovieRating
    GROUP BY user_id
),
ref2 AS(
    SELECT movie_id, AVG(rating) AS avgrating
    FROM MovieRating
    WHERE MONTH(created_at) = 2
        AND YEAR(created_at) = 2020
    GROUP BY movie_id
)
(
    SELECT u.name AS results
    FROM Users u
    JOIN ref1 r
    ON u.user_id = r.user_id
    ORDER BY r.ratingsbyuser DESC, u.name
    LIMIT 1
)

UNION ALL

(
    SELECT m.title AS results
    FROM Movies m
    JOIN ref2 r
    ON m.movie_id = r.movie_id
    ORDER BY r.avgrating DESC, m.title
    LIMIT 1
);