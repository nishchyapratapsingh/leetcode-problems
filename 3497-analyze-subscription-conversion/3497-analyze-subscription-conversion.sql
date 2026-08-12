# Write your MySQL query statement below
SELECT u.user_id, 
    (
        SELECT ROUND(AVG(activity_duration), 2)
        FROM UserActivity w
        WHERE u.user_id = w.user_id
            AND activity_type = 'free_trial'
    ) AS trial_avg_duration,
    (
        SELECT ROUND(AVG(activity_duration), 2)
        FROM UserActivity w
        WHERE u.user_id = w.user_id
            AND activity_type = 'paid'
    ) 
    AS paid_avg_duration
FROM UserActivity u
WHERE EXISTS (
    SELECT 1
    FROM UserActivity v
    WHERE u.user_id = v.user_id
    AND v.activity_type = 'paid'
) AND EXISTS (
    SELECT 1
    FROM UserActivity v
    WHERE u.user_id = v.user_id
    AND v.activity_type = 'free_trial'
)
GROUP BY user_id
ORDER BY user_id;