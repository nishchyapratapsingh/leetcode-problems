WITH RECURSIVE ref AS (
    SELECT id AS root, id, visit_date, people
    FROM Stadium
    WHERE people >= 100

    UNION ALL

    SELECT r.root, s.id, s.visit_date, s.people
    FROM Stadium s
    JOIN ref r
        ON s.id = r.id + 1
    WHERE s.people >= 100
),
qualified AS (
    SELECT root
    FROM ref
    GROUP BY root
    HAVING COUNT(*) >= 3
)
SELECT DISTINCT s.id, s.visit_date, s.people
FROM ref r
JOIN qualified q
    ON q.root = r.root
JOIN Stadium s
    ON s.id = r.id
ORDER BY s.visit_date;