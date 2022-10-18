# Write your MySQL query statement below
select employee_id
from Employees
where Employees.employee_id not in (select Salaries.employee_id from Salaries)
union
select employee_id
from Salaries
where Salaries.employee_id not in (select Employees.employee_id from Employees)
order by employee_id;