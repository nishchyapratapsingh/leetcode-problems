# Write your MySQL query statement below
WITH ref AS (
    SELECT driver_id, 
        AVG(CASE WHEN MONTH(trip_date) <= 6 THEN distance_km/fuel_consumed END) AS first_half_avg,
        AVG(CASE WHEN MONTH(trip_date) >= 7 THEN distance_km/fuel_consumed END) AS second_half_avg
    FROM trips
    GROUP BY driver_id
)
SELECT r.driver_id, 
    d.driver_name,
    ROUND(r.first_half_avg, 2) AS first_half_avg,
    ROUND(r.second_half_avg, 2) AS second_half_avg,
    ROUND(r.second_half_avg - r.first_half_avg, 2) AS efficiency_improvement
FROM ref r
JOIN drivers d
ON d.driver_id = r.driver_id
WHERE r.second_half_avg > r.first_half_avg
ORDER BY efficiency_improvement DESC, d.driver_name;