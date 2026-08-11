# Write your MySQL query statement below
SELECT s.id,
    IFNULL (t.student, s.student)
    AS student
FROM Seat s
LEFT JOIN Seat t
ON t.id = CASE
              WHEN s.id % 2 = 0 THEN s.id - 1
              ELSE s.id + 1
          END; 

