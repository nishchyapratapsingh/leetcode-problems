# Write your MySQL query statement below
SELECT DISTINCT c.customer_id
FROM Customer c
GROUP BY c.customer_id
HAVING
(
    SELECT COUNT(DISTINCT product_key)
    FROM Customer d
    WHERE c.customer_id = d.customer_id
) = (
    SELECT COUNT(*)
    FROM Product
);