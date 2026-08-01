# Write your MySQL query statement below
SELECT e.employee_id, 
    e.name, 
    (
        SELECT COUNT(*) 
        FROM Employees
        WHERE reports_to = e.employee_id
    ) 
    AS reports_count,
    (
        SELECT ROUND(AVG(age), 0)
        FROM Employees
        WHERE reports_to = e.employee_id
    ) 
    AS average_age
FROM Employees e
HAVING reports_count > 0
ORDER BY employee_id;
