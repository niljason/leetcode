CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      ifnull(
        (SELECT DISTINCT salary FROM Employee
        ORDER BY salary desc
        limit 1
        OFFSET N),
      null)
  );
END
