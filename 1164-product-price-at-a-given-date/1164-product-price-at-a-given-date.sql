# Write your MySQL query statement below
SELECT a.product_id, 
    IFNULL((
        SELECT b.new_price
        FROM Products b
        WHERE b.product_id = a.product_id
            AND b.change_date <= '2019-08-16'
        ORDER BY b.change_date DESC
        LIMIT 1
    ), 10) AS price
FROM Products a
GROUP BY a.product_id;
