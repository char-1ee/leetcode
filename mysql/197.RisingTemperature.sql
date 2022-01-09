SELECT w1.id AS 'Id'
FROM Weather w1, Weather w2
WHERE w1.temperature > w2.temperature
        AND DATEDIFF(w1.recordDate, w2.recordDate) = 1;