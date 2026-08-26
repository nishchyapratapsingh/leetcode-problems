# Write your MySQL query statement below
SELECT x.visited_on,
    SUM(x.amount) OVER (
        ORDER BY x.visited_on
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) AS amount,
    ROUND(AVG(x.amount) OVER (
        ORDER BY x.visited_on
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ), 2) AS average_amount
FROM
(
    SELECT
    visited_on,
    SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
) x
LIMIT 1000000 OFFSET 6;