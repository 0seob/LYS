-- 코드를 입력하세요
# SELECT B.TITLE, B.BOARD_ID, R.REPLY_ID, R.WRITER_ID, R.CONTENTS, date_format(R.CREATED_DATE, '%2022-%10-%d') AS CREATED_DATE
# from USED_GOODS_BOARD AS B JOIN USED_GOODS_REPLY AS R
# ON B.BOARD_ID = R.BOARD_ID
# WHERE date_format(B.created_date, '%Y-%m') = '2022-10'
# ORDER BY R.CREATED_DATE ASC, B.TITLE ASC;

# SELECT A.TITLE, A.BOARD_ID, B.REPLY_ID, B.WRITER_ID, B.CONTENTS, date_format(B.CREATED_DATE, '%2022-%10-%d') AS CREATED_DATE
# FROM USED_GOODS_BOARD AS A
# INNER JOIN USED_GOODS_REPLY AS B
# ON A.BOARD_ID = B.BOARD_ID
# WHERE B.CREATED_DATE BETWEEN '2022-10-01' AND '2022-10-31'
# ORDER BY B.CREATED_DATE ASC, A.TITLE ASC;

SELECT b.title, b.board_id, r.reply_id, r.writer_id, r.contents, date_format(r.created_date,'%Y-%m-%d') as created_date
from used_goods_board b
join used_goods_reply r 
    on b.board_id = r.board_id 
where date_format(b.created_date, '%Y-%m') = '2022-10'
order by r.created_date , b.title asc