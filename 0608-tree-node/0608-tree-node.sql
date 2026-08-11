# Write your MySQL query statement below
SELECT c.id, 
    CASE 
        WHEN c.p_id IS NULL THEN 'Root'
        WHEN p.id iS NOT NULL THEN 'Inner'
        ELSE 'Leaf'
    END 
    AS type
FROM Tree c
LEFT JOIN Tree p 
ON c.id = p.p_id
GROUP BY id;