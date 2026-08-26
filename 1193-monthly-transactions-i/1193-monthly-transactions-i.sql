# Write your MySQL query statement below
SELECT DATE_FORMAT(t.trans_date, '%Y-%m') AS month,
    t.country,
    COUNT(*) AS trans_count, 
    (
        SELECT COUNT(*)
        FROM Transactions u
        WHERE DATE_FORMAT(u.trans_date, '%Y-%m') = DATE_FORMAT(t.trans_date, '%Y-%m')
            AND t.country <=> u.country
            AND u.state = 'approved'
    ) AS approved_count,
    (
        SELECT IFNULL(SUM(v.amount), 0)
        FROM Transactions v
        WHERE DATE_FORMAT(v.trans_date, '%Y-%m') = DATE_FORMAT(t.trans_date, '%Y-%m')
            AND t.country <=> v.country
    ) AS trans_total_amount,
    (
        SELECT IFNULL(SUM(w.amount), 0)
        FROM Transactions w
        WHERE DATE_FORMAT(w.trans_date, '%Y-%m') = DATE_FORMAT(t.trans_date, '%Y-%m')
            AND t.country <=> w.country
            AND w.state = 'approved'
    )
    AS approved_total_amount
FROM Transactions t
GROUP BY month, t.country;