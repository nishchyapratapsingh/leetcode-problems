# Write your MySQL query statement below
SELECT DISTINCT l.num AS ConsecutiveNums
FROM Logs l
JOIN Logs m
ON l.num = m.num
    AND l.id + 1 = m.id
JOIN Logs n
ON m.num = n.num
    AND m.id + 1 = n.id;