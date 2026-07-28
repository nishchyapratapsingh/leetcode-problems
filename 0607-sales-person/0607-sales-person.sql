# Write your MySQL query statement below
SELECT sp.name
FROM SalesPerson sp
LEFT JOIN Orders o
ON sp.sales_id = o.sales_id
LEFT JOIN Company c
ON o.com_id = c.com_id

GROUP BY sp.sales_id, sp.name
HAVING IFNULL(SUM(c.name = 'RED'), 0) = 0;