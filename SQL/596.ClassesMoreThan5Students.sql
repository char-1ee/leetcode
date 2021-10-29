SELECT class AS 'Class'
FROM Courses
GROUP BY  class
HAVING (count(distinct student) >= 5);