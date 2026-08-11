# Write your MySQL query statement below
SELECT s.id, 
    CASE 
        WHEN s.id % 2 = 0 THEN u.student
        ELSE IFNULL (t.student, s.student)
    END AS student
FROM Seat s
LEFT JOIN Seat t
ON s.id + 1 = t.id
LEFT JOIN Seat u
ON s.id = u.id + 1;

