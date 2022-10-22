# Write your MySQL query statement below
select Salesperson.name
from Salesperson
where Salesperson.sales_id not in (select Orders.sales_id
from orders left join Company
on Company.com_id=Orders.com_id
where Company.name="RED");
                                  
                                 