-- where clause
SELECT
    e2.name AS Employee
FROM
    Employee e1,
    Employee e2
WHERE
    e1.salary < e2.salary
    AND e1.id = e2.managerId;

-- join clause
SELECT
    e1.name AS Employee
FROM
    employee AS e1
    JOIN Employee AS e2 ON e1.salary > e2.salary
    AND e1.managerId = e2.id