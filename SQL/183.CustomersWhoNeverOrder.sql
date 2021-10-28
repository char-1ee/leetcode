-- method 1
SELECT name AS Customers
FROM Customer c
WHERE c.id NOT IN 
    (SELECT customerid FROM Orders);

-- method 2
SELECT name AS Customers
FROM Customer c
LEFT JOIN Orders o
    ON c.id = o.customerId
WHERE o.id is null;