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

-- 2. CASE flow control
select 
(
    case when mod(id, 2) = 1 and id != counts then id + 1 
    when mod(id, 2) = 1 and id = counts then id
    else id -1 
    end                                             /* dont forgot end a case clause */
) as id, student

from seat, (select count(*) as counts from seat)    /* join a constant */
order by is asc;


-- 3. Bit manipulation (id+1)^1-1 and COALESCE()

/* COALESCE() reutrns first non-null valeu in argument list */
select s1.id, COALESCE(s2.student, s1.student) as student 
from seat s1 left join seat s2
on (s1.id + 1) ^ 1 - 1 = s2.id
order by s1.id asc;

/* 
    Explanation about bit manipulation: 
    SELECT id, (id) ^ 1 FROM seat
    it will add 1 to all odd numbers and subtract 1 from all even numbers.
    The result will be: [[1,0],[2,3],[3,2],[4,5],[5,4]]. 
    Likewise, if you run the query:
    SELECT id, (id+1)^1-1 FROM seat
    The result will be:
    [[1,2],[2,1],[3,4],[4,3],[5,6]]; 
    
    3 in binary is "11", so when we add 1 then "100" then xor with one ( 100 xor 001) 
    gives us "101" subtract 1 and there you have "100" -> 4 
    In other words when we xor some number with 1 we change it from odd to even and around. 
    But if we used only xor with 1 we would get index changes like so: 1 <-> 0; 2 <-> 3 etc 
    but we want to change 1 <-> 2; 3<->4 etc. 
    therefore we need that additional +1 and -1 along with the xor 1
*/
