-- Write your query below
SELECT name FROM customers where id not IN (SELECT customer_id FROM orders);