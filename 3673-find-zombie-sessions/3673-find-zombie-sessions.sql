# Write your MySQL query statement below
WITH ref AS (
    SELECT user_id, session_id,
        MIN(CASE WHEN event_type = 'app_open' THEN event_timestamp END) AS begin_time,
        MAX(CASE WHEN event_type = 'app_close' THEN event_timestamp END) AS end_time,
        COUNT(CASE WHEN event_type = 'scroll' THEN 1 END) AS scroll_cnt,
        COUNT(CASE WHEN event_type = 'click' THEN 1 END) AS click_cnt,
        COUNT(CASE WHEN event_type = 'purchase' THEN 1 END) AS purchase_cnt
    FROM app_events
    GROUP BY session_id
)

SELECT session_id, user_id,
    TIMESTAMPDIFF(MINUTE, begin_time, end_time) AS session_duration_minutes,
    scroll_cnt AS scroll_count
FROM ref
WHERE purchase_cnt = 0
    AND scroll_cnt >= 5
    AND click_cnt / scroll_cnt < 0.20
HAVING session_duration_minutes > 30
ORDER BY scroll_count DESC, session_id;