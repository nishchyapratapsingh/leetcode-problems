# Write your MySQL query statement below
WITH ref AS (
    SELECT p.user_id, p.product_id, i.category
    FROM ProductPurchases p
    JOIN ProductInfo i
    ON p.product_id = i.product_id
)

SELECT r1.category AS category1,
    r2.category AS category2,
    COUNT(DISTINCT r1.user_id) AS customer_count
FROM ref r1
JOIN ref r2
ON r1.category < r2.category
    AND r1.user_id = r2.user_id
GROUP BY r1.category, r2.category
HAVING customer_count >= 3
ORDER BY customer_count DESC, category1, category2;