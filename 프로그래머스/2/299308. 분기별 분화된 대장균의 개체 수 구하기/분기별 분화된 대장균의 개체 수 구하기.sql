-- 코드를 작성해주세요
select CONCAT(QUARTER(DIFFERENTIATION_DATE),'Q') as QUARTER, count(ID) as ECOLI_COUNT 
from ECOLI_DATA 
group by QUARTER
order by QUARTER