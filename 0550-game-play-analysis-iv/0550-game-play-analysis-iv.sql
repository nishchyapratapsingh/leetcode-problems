# Write your MySQL query statement below
WITH date_ref AS (
    SELECT player_id,
        MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
), ref AS (
    SELECT d.player_id
    FROM date_ref d
    JOIN Activity a
    ON a.player_id = d.player_id
        AND a.event_date = d.first_date + INTERVAL 1 DAY
)

SELECT ROUND(
    (SELECT COUNT(*) FROM ref) /
    (SELECT COUNT(*) FROM date_ref),
    2
) AS fraction;

