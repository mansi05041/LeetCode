# Write your MySQL query statement below
select d.name as Department , e.name as Employee ,  e.salary as Salary
from Employee e
join Department d 
on e.DepartmentId = d.Id
where 3 >(select count(Distinct e1.salary) from Employee e1 where
         e1.salary>e.salary and e1.DepartmentId=e.DepartmentId);
