# Write your MySQL query statement below
WITH ref AS (
    SELECT employee_id, 
        SUM(duration_hours) AS meeting_hours
    FROM meetings
    GROUP BY employee_id, YEARWEEK(meeting_date, 1)
)
SELECT e.*,
    COUNT(CASE WHEN r.meeting_hours > 20 THEN 1 END) AS meeting_heavy_weeks
FROM employees e
JOIN ref r
ON r.employee_id = e.employee_id
GROUP BY e.employee_id
HAVING meeting_heavy_weeks >= 2
ORDER BY meeting_heavy_weeks DESC,
    e.employee_name;