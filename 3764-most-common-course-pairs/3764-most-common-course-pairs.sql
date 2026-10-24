# Write your MySQL query statement below
with ref as (
    select user_id
    from course_completions
    group by user_id
    having count(course_id) >= 5
        and avg(course_rating) >= 4
)

select a.course_name as first_course,
    c.course_name as second_course,
    count(*) as transition_count
from course_completions a
join ref b
    on a.user_id = b.user_id
join course_completions c
    on a.completion_date < c.completion_date
    and b.user_id = c.user_id
WHERE NOT EXISTS (
    SELECT 1
    FROM course_completions x
    WHERE x.user_id = a.user_id
      AND x.completion_date > a.completion_date
      AND x.completion_date < c.completion_date
)
group by first_course, second_course
order by transition_count desc, first_course, second_course;
