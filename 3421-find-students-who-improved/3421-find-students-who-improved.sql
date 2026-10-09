# Write your MySQL query statement below
WITH ref AS (
    SELECT *, 
    ROW_NUMBER() OVER(
        PARTITION BY student_id, subject
        ORDER BY exam_date
    ) AS firstrnk,
    ROW_NUMBER() OVER(
        PARTITION BY student_id, subject
        ORDER BY exam_date DESC
    ) AS lstrnk
    FROM Scores
)
SELECT student_id, subject, 
    SUM(CASE WHEN firstrnk = 1 THEN score ELSE 0 END) AS first_score,
    SUM(CASE WHEN lstrnk = 1 THEN score ELSE 0 END) AS latest_score
FROM ref
GROUP BY student_id, subject
HAVING latest_score > first_score
ORDER BY student_id, subject;
    