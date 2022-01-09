-- Method 1
DELETE FROM Person
WHERE id NOT IN 
    (SELECT *
    FROM (min(id)
    FROM Person
    GROUP BY  email));

-- Method 2
DELETE p2                   /* delete p2 means delete all columns of p2 in p1-p2-joined table */
FROM Person p1, Person p2
WHERE p1.email = p2.email
        AND p1.id < p2.id;