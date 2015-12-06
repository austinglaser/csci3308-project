import sqlite3 as lite

con = lite.connect('db.sqlite3')
cur = con.cursor()

cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('20', '2015-12-07 16:40:00');")
cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('14', '2015-12-08 16:40:00');")
cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('21', '2015-12-09 16:40:00');")
cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('22', '2015-12-10 16:40:00');")
cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('83', '2015-12-11 16:40:00');")
cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('25', '2015-12-12 16:40:00');")
cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('17', '2015-12-13 16:40:00');")
cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('112', '2015-12-14 16:40:00');")
cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('18', '2015-12-15 16:40:00');")
cur.execute("insert into figure_usage('device_usage', 'time_stamp') values('25', '2015-12-16 16:40:00');")

con.commit()
con.close()
