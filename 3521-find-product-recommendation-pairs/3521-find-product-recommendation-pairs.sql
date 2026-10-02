SELECT
    p1.product_id AS product1_id,
    p2.product_id AS product2_id,
    p3.category AS product1_category,
    p4.category AS product2_category,
    COUNT(DISTINCT p1.user_id) AS customer_count
FROM ProductPurchases p1
JOIN ProductPurchases p2
    ON p1.user_id = p2.user_id
    AND p1.product_id < p2.product_id
JOIN ProductInfo p3
    ON p1.product_id = p3.product_id
JOIN ProductInfo p4
    ON p2.product_id = p4.product_id
GROUP BY
    p1.product_id,
    p2.product_id,
    p3.category,
    p4.category
HAVING customer_count >= 3
ORDER BY
    customer_count DESC,
    product1_id,
    product2_id
;