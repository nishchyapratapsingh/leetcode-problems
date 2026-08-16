SELECT y.season, y.category, y.total_quantity, y.total_revenue
FROM
(   
    SELECT x.*, 
        DENSE_RANK() OVER (
            PARTITION BY x.season
            ORDER BY
                x.total_quantity DESC,
                x.total_revenue DESC,
                x.category ASC
        ) AS rnk
    FROM
    ( 
        SELECT CASE
                    WHEN MONTH(s.sale_date) IN (9, 10, 11) THEN 'Fall'
                    WHEN MONTH(s.sale_date) IN (3, 4, 5) THEN 'Spring' 
                    WHEN MONTH(s.sale_date) IN (6, 7, 8) THEN 'Summer' 
                    ELSE 'Winter'
                END AS season,
                p.category, 
                SUM(s.quantity) AS total_quantity,
                SUM(s.quantity * s.price) AS total_revenue
        FROM sales s
        JOIN products p
        ON s.product_id = p.product_id
        GROUP BY season, category
    ) x
) y
WHERE y.rnk = 1;