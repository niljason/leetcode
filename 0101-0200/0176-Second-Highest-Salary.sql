# Write your MySQL query statement below
SELECT max(salary) as SecondHighestSalary
FROM Employee
WHERE Employee.salary < (
    SELECT max(SALARY) FROM Employee
);
