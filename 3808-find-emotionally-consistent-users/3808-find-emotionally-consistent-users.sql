# Write your MySQL query statement below
SELECT x.user_id, x.reaction AS dominant_reaction,
    ROUND(MAX(x.cnt) / SUM(x.cnt), 2) AS reaction_ratio
FROM
(
    SELECT user_id, 
    reaction,
    COUNT(*) as cnt
    FROM reactions
    GROUP BY user_id, reaction
    ORDER BY cnt DESC
) x
LEFT JOIN
(
    SELECT
    user_id,
    COUNT(DISTINCT content_id) AS content_count
    FROM reactions
    GROUP BY user_id
) y
ON x.user_id = y.user_id
GROUP BY x.user_id
HAVING reaction_ratio >= 0.6
    AND MAX(y.content_count) >= 5
ORDER BY reaction_ratio DESC, x.user_id;
