SELECT s.Name
FROM Students s
RIGHT JOIN
  (SELECT a.ID
   FROM Packages p
   JOIN
     (SELECT f.ID,
             p.Salary
      FROM Friends f
      JOIN Packages p ON f.Friend_ID = p.ID) a ON p.ID = a.ID
   WHERE p.Salary < a.Salary
   ORDER BY a.Salary) b ON s.ID = b.ID;
