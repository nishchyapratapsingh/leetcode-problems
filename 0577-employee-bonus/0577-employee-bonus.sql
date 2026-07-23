# Write your MySQL query statement below
SELECT name, bonus
FROM Employee
LEFT JOIN Bonus ON Employee.empId = Bonus.empId
HAVING bonus < 1000 OR bonus IS NULL;