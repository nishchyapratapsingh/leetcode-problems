# Write your MySQL query statement below
SELECT t.transaction_date, 
    (
        SELECT IFNULL(SUM(amount), 0)
        FROM transactions t1
        WHERE t1.transaction_date = t.transaction_date
            AND t1.amount % 2 = 1
    ) AS odd_sum,
    (
        SELECT IFNULL(SUM(amount), 0)
        FROM transactions t1
        WHERE t1.transaction_date = t.transaction_date
            AND t1.amount % 2 = 0
    ) AS even_sum
FROM transactions t
GROUP BY t.transaction_date
ORDER BY transaction_date;
