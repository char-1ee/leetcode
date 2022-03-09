select
    s.score,
    count(s2.score) as 'rank'
from
    Scores s,
    (
        select
            distinct score
        from
            Scores
    ) s2
where
    s.score <= s2.score
group by
    s.id
order by
    s.score desc