# Write your MySQL query statement below
WITH ref AS (
    SELECT book_id,
        MAX(session_rating) AS max_rating,
        MIN(session_rating) AS min_rating,
        COUNT(CASE WHEN session_rating >= 4 THEN 1 END) AS high_ratings,
        COUNT(CASE WHEN session_rating <= 2 THEN 1 END) AS low_ratings,
        COUNT(*) AS total
    FROM reading_sessions
    GROUP BY book_id
)
SELECT b.*,
    r.max_rating - r.min_rating AS rating_spread,
    ROUND((r.high_ratings + r.low_ratings) / r.total, 2) AS polarization_score
FROM books b
JOIN ref r
ON b.book_id = r.book_id
WHERE r.total >= 5
    AND high_ratings > 0 AND low_ratings > 0
HAVING polarization_score >= 0.6
ORDER BY polarization_score DESC, b.title DESC;