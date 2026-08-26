# Write your MySQL query statement below
SELECT a.customer_id
FROM customer_transactions a
GROUP BY a.customer_id
HAVING COUNT(CASE WHEN a.transaction_type = 'purchase' THEN 1 END) >= 3
    AND DATEDIFF(MAX(a.transaction_date), MIN(a.transaction_date)) >= 30
    AND COUNT(CASE WHEN a.transaction_type = 'refund' THEN 1 END)/COUNT(*) < 0.2
ORDER BY a.customer_id;