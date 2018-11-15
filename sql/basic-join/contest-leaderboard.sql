select h.hacker_id, h.name, sum(s.ms) as fs 
from hackers h inner join
(select hacker_id, max(score) as ms from submissions group by challenge_id, hacker_id) s
on h.hacker_id = s.hacker_id
group by h.hacker_id, h.name
having sum(s.ms) > 0
order by fs desc, h.hacker_id asc;
