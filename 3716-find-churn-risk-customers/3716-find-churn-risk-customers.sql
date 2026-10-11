WITH ref AS (
    SELECT
        user_id,
        MIN(event_date) AS first_date,
        MAX(monthly_amount) AS max_historical_amount,
        COUNT(CASE WHEN event_type = 'downgrade' THEN 1 END) AS dngrdcnt
    FROM subscription_events
    GROUP BY user_id
),
ranked AS (
    SELECT *,
        ROW_NUMBER() OVER (
            PARTITION BY user_id
            ORDER BY event_date DESC, event_id DESC
        ) AS rn
    FROM subscription_events
)
SELECT
    s.user_id,
    s.plan_name AS current_plan,
    s.monthly_amount AS current_monthly_amount,
    r.max_historical_amount,
    DATEDIFF(s.event_date, r.first_date) AS days_as_subscriber
FROM ranked s
JOIN ref r
    ON s.user_id = r.user_id
WHERE s.rn = 1
    AND s.event_type != 'cancel'
    AND r.dngrdcnt > 0
    AND s.monthly_amount < 0.5 * r.max_historical_amount
    AND DATEDIFF(s.event_date, r.first_date) >= 60
ORDER BY days_as_subscriber DESC, s.user_id ASC;