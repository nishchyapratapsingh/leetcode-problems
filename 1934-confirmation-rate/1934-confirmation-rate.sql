# Write your MySQL query statement below
SELECT s.user_id,
    IFNULL(ROUND(
        (
        SELECT COUNT(*)
        FROM Confirmations t
        WHERE s.user_id = t.user_id
            AND action = 'confirmed'
        ) / (
            SELECT COUNT(*)
            FROM Confirmations t
            WHERE s.user_id = t.user_id
        ),
    2), 0) AS confirmation_rate

FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id;