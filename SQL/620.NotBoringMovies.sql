SELECT * FROM Cinema
WHERE description <> 'boring'
        AND mod(id, 2) = 1
ORDER BY  rating DESC ;
