# Write your MySQL query statement below
select tree.id,
case 
    when tree.id = (select tree.id from tree where tree.p_id is NULL)
        then 'Root'
    when tree.id in (select tree.p_id from tree)
        then 'Inner'
    else 'Leaf'
    end as Type
from tree
order by tree.id;
