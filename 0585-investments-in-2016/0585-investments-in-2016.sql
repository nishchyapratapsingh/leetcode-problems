# Write your MySQL query statement below
SELECT ROUND(SUM(a.tiv_2016), 2) as tiv_2016
FROM Insurance a
WHERE EXISTS (
    SELECT 1
    FROM Insurance b
    WHERE a.tiv_2015 = b.tiv_2015
        AND a.pid <> b.pid
)
    AND NOT EXISTS (
        SELECT 1
        FROM Insurance c
        WHERE a.lat = c.lat
            AND a.lon = c.lon
            AND a.pid <> c.pid
    );