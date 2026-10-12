# Write your MySQL query statement below
WITH ref AS (
    SELECT product_id,
        MIN(year) AS early_year
    FROM Sales
    GROUP BY product_id 
)
SELECT s.product_id, 
    s.year AS first_year,
    s.quantity, 
    s.price
FROM Sales s
JOIN ref r
ON r.product_id = s.product_id
WHERE s.year = r.early_year;