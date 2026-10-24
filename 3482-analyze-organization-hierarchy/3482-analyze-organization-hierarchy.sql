# Write your MySQL query statement below
WITH RECURSIVE levels AS (
    SELECT employee_id, employee_name, 1 AS level
    FROM Employees
    WHERE manager_id IS NULL

    UNION ALL

    SELECT e.employee_id, e.employee_name, h.level+1
    FROM Employees e
    JOIN levels h
        ON e.manager_id = h.employee_id
), 
team as (
    select employee_id as root,
        employee_id, employee_name, salary
    FROM employees

    union all

    select t.root, e.employee_id, e.employee_name, e.salary
    from employees e
    join team t
    on t.employee_id = e.manager_id
),
team_stats as (
    select root as employee_id, 
        count(*) - 1 as team_size,
        sum(salary) as budget
    from team
    group by root
)

select t.employee_id, l.employee_name, l.level, t.team_size, t.budget
from levels l
join team_stats t
on t.employee_id = l.employee_id
order by level, budget desc, employee_name;

