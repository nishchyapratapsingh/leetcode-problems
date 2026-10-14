# Write your MySQL query statement below
WITH first_pos_date AS (
    SELECT patient_id, 
        MIN(test_date) AS positive_date
    FROM covid_tests
    WHERE result = 'Positive'
    GROUP BY patient_id
),
first_neg_date AS (
    SELECT f.patient_id, 
        f.positive_date,
        MIN(c.test_date) AS negative_date
    FROM first_pos_date f
    JOIN covid_tests c
    ON c.patient_id = f.patient_id
        AND c.result = 'Negative'
        AND c.test_date > f.positive_date
    GROUP BY f.patient_id
)

SELECT p.*,
    DATEDIFF(fn.negative_date, fp.positive_date) AS recovery_time
FROM patients p
JOIN first_pos_date fp
ON p.patient_id = fp.patient_id
JOIN first_neg_date fn
ON fp.patient_id = fn.patient_id
    -- AND fp.positive_date < fn.negative_date
ORDER BY recovery_time, p.patient_name;