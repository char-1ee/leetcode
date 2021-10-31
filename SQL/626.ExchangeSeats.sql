-- 1. Union
/* get all the even numbered rows as odd numbered rows */
select s1.id - 1 as id, student 
from seat s1
where mod(s1.id, 2) = 0 

Union

/* get all the odd numbered rows (except the last row) as even numbered rows */
select s2.id + 1 as id, student
from seat s2
where mod(s2.id, 2) = 1 and s2.id != (select count(*) from seat)

union 

/* get the last row if odd and don't change the id value */
select s3.id as id, student
from seat s3
where mod(s3.id, 2) = 1 and s3.id = (select count(*) from seat)

order by id asc;

-- 2. Bit manipulation (id+1)^1-1 and COALESCE()

/* COALESCE() reutrns first non-null valeu in argument list */
select s1.id, COALESCE(s2.student, s1.student) as student 
from seat s1 left join seat s2
on (s1.id + 1) ^ 1 - 1 = s2.id
order by s1.id asc;

-- 3. CASE flow control

select 
(
    case when mod(id, 2) = 1 and id != counts then id + 1 
    when mod(id, 2) = 1 and id = counts then id
    else id -1 
    end                                             /* dont forgot end a case clause */
) as id, student

from seat, (select count(*) as counts from seat)    /* join a constant */
order by is asc;