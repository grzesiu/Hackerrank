select h.hacker_id, h.name, count(c.hacker_id) as m 
from hackers h inner join challenges c 
on h.hacker_id = c.hacker_id
group by h.hacker_id, h.name
having count(c.hacker_id) in 
(
    select n from 
    (
        select hacker_id, count(hacker_id) as n 
        from challenges group by hacker_id
    )
    group by n having 
        count(n) = 1 or
        n = (select max(count(hacker_id)) from challenges group by hacker_id)
)
order by m desc, h.hacker_id asc;
