# Write your MySQL query statement below
WITH ref AS (
    SELECT customer_id,
        COUNT(*) as total_orders,
        COUNT(
            CASE WHEN (TIME(order_timestamp) BETWEEN '11:00' AND '14:00') OR (TIME(order_timestamp) BETWEEN '18:00' AND '21:00') 
                THEN 1 END
        ) AS peak_orders,
        ROUND(AVG(order_rating), 2) AS average_rating,
        COUNT(
            CASE WHEN order_rating IS NOT NULL THEN 1 END
        ) AS rated_orders
    FROM restaurant_orders
    GROUP BY customer_id
)

SELECT customer_id, 
    total_orders,
    ROUND(peak_orders/total_orders * 100, 0) AS peak_hour_percentage,
    average_rating
FROM ref
WHERE rated_orders/total_orders >= 0.5
HAVING total_orders >= 3
    AND peak_hour_percentage >= 60
    AND average_rating >= 4.0
ORDER BY average_rating DESC, customer_id DESC;
