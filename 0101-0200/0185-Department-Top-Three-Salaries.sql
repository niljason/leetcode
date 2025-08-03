# Write your MySQL query statement below
SELECT
    d.name as Department,
    e.name as Employee,
    e.salary as Salary
FROM (
    SELECT e.id, e.name, e.salary, e.departmentId,
    DENSE_RANK() OVER (
        PARTITION BY e.departmentId ORDER BY e.salary DESC) as salary_rank
        FROM Employee e
    ) e
JOIN Department d on e.departmentId = d.id
WHERE e.salary_rank <=3;
