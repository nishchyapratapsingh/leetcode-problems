WITH recent AS (
    SELECT
        employee_id,
        review_date,
        rating,
        ROW_NUMBER() OVER (
            PARTITION BY employee_id
            ORDER BY review_date DESC
        ) AS rn
    FROM performance_reviews
)
SELECT
    a.employee_id, e.name,
    (c.rating - a.rating) AS improvement_score
FROM recent a
JOIN recent b
    ON a.employee_id = b.employee_id
    AND b.rn = 2
JOIN recent c
    ON a.employee_id = c.employee_id
    AND c.rn = 1
JOIN employees e
ON a.employee_id = e.employee_id
WHERE a.rn = 3
  AND a.rating < b.rating
  AND b.rating < c.rating
ORDER BY improvement_score DESC, e.name;