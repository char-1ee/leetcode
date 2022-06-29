-- Method 1
select 
    b.name AS 'Department',
    a.name AS 'Employee',
    a.salary as 'Salary'
from 
    Employee as a join Department as b on a.departmentId = b.id
where 
    (a.departmentId, a.salary) in (
        select 
            departmentId, max(salary)
        from 
            Employee
        group by 
            departmentId
    );

-- Method 2
select
    b.name as Department,
    a.name as Employee,
    a.salary as Salary
from
    Employee as a,
    Department as b
where
    a.departmentId = b.id
    and (a.departmentId, a.salary) in (
        select
            departmentId,
            max(salary)
        from
            Employee
        group by
            departmentId
    )