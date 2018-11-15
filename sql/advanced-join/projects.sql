SELECT max(Start_date),
       End_date
FROM
  (SELECT Start_date
   FROM Projects
   WHERE Start_date NOT IN
       (SELECT End_date
        FROM Projects))
INNER JOIN
  (SELECT End_date
   FROM Projects
   WHERE End_date NOT IN
       (SELECT Start_date
        FROM Projects)) ON Start_date < End_date
GROUP BY End_date
ORDER BY (End_date - max(Start_date)), End_date;
