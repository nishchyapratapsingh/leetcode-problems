# Write your MySQL query statement below
SELECT l.book_id, l.title, l.author, l.genre, l.publication_year,
    -- (SELECT total_copies FROM library_books WHERE book_id = l.book_id)
    COUNT(*) AS current_borrowers
FROM library_books l
JOIN borrowing_records b
ON l.book_id = b.book_id
WHERE b.return_date IS NULL
GROUP BY l.book_id, l.title
HAVING (SELECT total_copies FROM library_books WHERE book_id = l.book_id) - COUNT(*) = 0
ORDER BY current_borrowers DESC, title;