-- Method 1
SELECT DISTINCT max(salary) AS SecondHighestSalary
FROM Employee
WHERE salary < (SELECT max(salary) FROM Employee);

-- Method 2 
SELECT 
    (SELECT DISTINCT salary FROM Employee 
    ORDER BY  salary DESC limit 1, 1) AS SecondHighestSalary;

-- Method 3
SELECT ifnull(
    (SELECT DISTINCT salary
    FROM employee
    ORDER BY  salary DESC limit 1, 1), null) AS SecondHighestSalary;

-- Method 4
SELECT max(a.Salary) AS SecondHighestSalary
FROM Employee a
JOIN Employee b ON a.Salary < b.Salary;

-- Method 5
select max(salary) AS SecondHighestSalary
from Employee
where salary < (select max(salary) from Employee);