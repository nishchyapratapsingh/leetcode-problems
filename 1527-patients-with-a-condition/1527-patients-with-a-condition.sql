# Write your MySQL query statement below
SELECT * FROM Patients
WHERE conditions REGEXP '(^| )DIAB1[A-Za-z0-9]*( |$)';