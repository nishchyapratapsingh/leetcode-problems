# Write your MySQL query statement below
SELECT x.person_name
FROM
(
    SELECT person_name, 
        SUM(weight) OVER (ORDER BY turn) as cur_total
    FROM Queue
) x
WHERE x.cur_total <= 1000
ORDER BY x.cur_total DESC
LIMIT 1;