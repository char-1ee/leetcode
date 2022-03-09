CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare M INT;
  set M=N-1;
  RETURN (
        SELECT DISTINCT salary
        FROM Employee
        ORDER BY salary DESC limit M, 1 
  );
END