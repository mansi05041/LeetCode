# Write your MySQL query statement below
select Users.user_id as buyer_id, Users.join_date,
sum(if(year(Orders.order_date)='2019',1,0)) as orders_in_2019
from Users left join Orders
on Users.user_id=Orders.buyer_id
group by Users.user_id;