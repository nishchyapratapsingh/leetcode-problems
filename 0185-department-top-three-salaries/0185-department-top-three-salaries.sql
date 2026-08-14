SELECT d.name AS Department,
    x.name AS Employee,
    x.Salary
FROM
(
    SELECT e.name,
        e.departmentId,
        e.salary AS Salary,
        DENSE_RANK() OVER (
            PARTITION BY departmentId
            ORDER BY Salary DESC
        ) as salary_rank
    FROM Employee e
) x
JOIN Department d
ON x.departmentId = d.id
AND x.salary_rank <= 3;