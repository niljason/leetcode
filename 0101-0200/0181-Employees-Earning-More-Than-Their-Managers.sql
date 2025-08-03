# Write your MySQL query statement below
SELECT e.name AS Employee
FROM Employee e
LEFT JOIN Employee ee
ON e.managerId = ee.id
WHERE e.salary > ee.salary;
