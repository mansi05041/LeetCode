# Write your MySQL query statement below
select Users.name as name, sum(Transactions.amount) as balance
from Users left join Transactions
on Users.account = Transactions.account
group by Users.name
having balance>10000;