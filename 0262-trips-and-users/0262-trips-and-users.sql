# Write your MySQL query statement below
with ref as (
    select t.*
    from Trips t
    join Users b
        on t.client_id = b.users_id
        and b.banned = 'No'
    join Users c
        on t.driver_id = c.users_id
        and c.banned = 'No'
    where t.request_at between "2013-10-01" and "2013-10-03"
)

select request_at as Day,
    ROUND(COUNT(CASE WHEN status != 'completed' THEN 1 END) / COUNT(*), 2) as `Cancellation Rate`
from ref
group by Day;