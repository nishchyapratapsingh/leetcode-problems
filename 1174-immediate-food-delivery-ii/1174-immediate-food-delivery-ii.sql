# Write your MySQL query statement below
WITH ref AS (
    SELECT *,
        ROW_NUMBER() OVER(
            PARTITION BY customer_id
            ORDER BY order_date
        ) as rnk
    FROM Delivery
)
SELECT ROUND(
            100.00 *
            COUNT(CASE WHEN rnk = 1 AND order_date = customer_pref_delivery_date THEN 1 END) /
            COUNT(DISTINCT customer_id)
        , 2)
    AS immediate_percentage
FROM ref; 