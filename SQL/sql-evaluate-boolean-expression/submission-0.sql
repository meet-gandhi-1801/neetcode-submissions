select 
e.left_operand,
e.operator,
e.right_operand,
case 
    when e.operator = '>' and lv.value > rv.value then 'true'
    when e.operator = '<' and lv.value < rv.value then 'true'
    when e.operator = '=' and lv.value = rv.value then 'true'
    else false 
    end as value
from expressions as e
join variables lv on lv.name = e.left_operand
join variables rv on rv.name = e.right_operand