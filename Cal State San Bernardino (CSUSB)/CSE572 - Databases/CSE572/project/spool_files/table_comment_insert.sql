set pagesize 500
set linesize 400
break on table_name
column table_name format a20
column table_type format a10
column comments format a50

select *
from user_tab_comments
where table_name = 'ADVISOR';

select *
from user_col_comments
where table_name = 'ADVISOR';

select *
from user_tab_comments
where table_name = 'COURSE';

select *
from user_col_comments
where table_name = 'COURSE';

select *
from user_tab_comments
where table_name = 'INSPECTION_REPORT';

select *
from user_col_comments
where table_name = 'INSPECTION_REPORT';

select *
from user_tab_comments
where table_name = 'INSTRUCTOR';

select *
from user_col_comments
where table_name = 'INSTRUCTOR';

select *
from user_tab_comments
where table_name = 'STAFF_MEMBER';

select *
from user_col_comments
where table_name = 'STAFF_MEMBER';

select *
from user_tab_comments
where table_name = 'STUDENT_APARTMENT';

select *
from user_col_comments
where table_name = 'STUDENT_APARTMENT';

select *
from user_tab_comments
where table_name = 'STUDENT';

select *
from user_col_comments
where table_name = 'STUDENT';

select *
from user_tab_comments
where table_name = 'TAKES_COURSE';

select *
from user_col_comments
where table_name = 'TAKES_COURSE';

select *
from user_tab_comments
where table_name = 'NOK_RELATIONSHIP';

select *
from user_col_comments
where table_name = 'NOK_RELATIONSHIP';

select *
from user_tab_comments
where table_name = 'RENTED_RESIDENCE';

select *
from user_col_comments
where table_name = 'RENTED_RESIDENCE';

select *
from user_tab_comments
where table_name = 'RENTS';

select *
from user_col_comments
where table_name = 'RENTS';

select *
from user_tab_comments
where table_name = 'RESIDENCE_HALL';

select *
from user_col_comments
where table_name = 'RESIDENCE_HALL';

select *
from user_tab_comments
where table_name = 'ROOM';

select *
from user_col_comments
where table_name = 'ROOM';

select *
from user_tab_comments
where table_name = 'INVOICE';

select *
from user_col_comments
where table_name = 'INVOICE';

select *
from user_tab_comments
where table_name = 'NEXT_OF_KIN';

select *
from user_col_comments
where table_name = 'NEXT_OF_KIN';

select *
from user_tab_comments
where table_name = 'LEASE';

select *
from user_col_comments
where table_name = 'LEASE';

select *
from user_tab_comments
where table_name = 'REMINDER';

select *
from user_col_comments
where table_name = 'REMINDER';

column table_name clear
column table_type clear
column comments clear


