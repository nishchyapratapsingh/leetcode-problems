# Write your MySQL query statement below
WITH ref AS (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) >= 5
)
SELECT e.name
FROM Employee e
JOIN ref r
ON e.id = r.managerId;