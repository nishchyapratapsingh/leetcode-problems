# Write your MySQL query statement below
SELECT x.store_id, 
    y.store_name,
    y.location,
    MAX( 
        CASE WHEN x.most_exp = 1 THEN x.product_name END
    ) AS most_exp_product,
    MAX( 
        CASE WHEN x.cheapest = 1 THEN x.product_name END
    ) AS cheapest_product,
    ROUND (
        MAX(
            CASE WHEN x.cheapest = 1 THEN x.quantity END
        ) 
         /
        MAX(
            CASE WHEN x.most_exp = 1 THEN x.quantity END
        )
    , 2) AS imbalance_ratio
FROM
(
    SELECT *,
        ROW_NUMBER() OVER (
            PARTITION BY store_id
            ORDER BY price DESC
        ) AS most_exp,
        ROW_NUMBER() OVER (
            PARTITION BY store_id
            ORDER BY price
        ) AS cheapest
    FROM inventory  
) x
JOIN stores y
ON x.store_id = y.store_id
GROUP BY x.store_id
HAVING imbalance_ratio > 1 AND
    COUNT(DISTINCT x.product_name) >= 3
ORDER BY imbalance_ratio DESC, y.store_name;
    