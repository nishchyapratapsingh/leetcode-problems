# Write your MySQL query statement below
SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(*) = (
    SELECT MAX(cnt)
    FROM (
            SELECT COUNT(*) as cnt
            FROM Orders
            GROUP BY customer_number
    ) t
);