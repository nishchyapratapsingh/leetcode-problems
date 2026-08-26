# Write your MySQL query statement below
SELECT DATE_FORMAT(t.trans_date, '%Y-%m') AS month,
    t.country,
    COUNT(*) AS trans_count,
    COUNT(CASE WHEN t.state = 'approved' THEN 1 END)
    AS approved_count,
    IFNULL(SUM(t.amount), 0)
    AS trans_total_amount,
    IFNULL(SUM(CASE WHEN t.state = 'approved' THEN t.amount END), 0)
    AS approved_total_amount
FROM Transactions t
GROUP BY month, t.country;