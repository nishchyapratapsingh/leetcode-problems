# Write your MySQL query statement below
SELECT e.employee_id
FROM Employees e
WHERE e.salary < 30000
    AND e.manager_id IS NOT NULL
    AND (
        SELECT COUNT(*) FROM Employees 
        WHERE e.manager_id = employee_id
    ) = 0
ORDER BY employee_id;
