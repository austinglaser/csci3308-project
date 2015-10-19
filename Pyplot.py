# Outletify Pyplot from SQL
# Jon Wehrend

import matplotlib
matplotlib.use('Agg')
from matplotlib.dates import date2num
import sqlite3
from matplotlib import pyplot
from matplotlib import dates as mdates

datetimes = []
usage = []
graph = []

# These should find the date info assuming we're using UTC
months = mdates.MonthLocator()
days = mdates.DayLocator()
hours = mdates.HourLocator()
date_format = mdates.DateFormatter("%a %d %b") # Will output as Day of week, day, month

conn = sqlite3.connect("outletify.db")

sql = "SELECT name_of_date_column, name_of_usage_column FROM name_of_table"

conn.row_factory = sqlite3.Row
cur = conn.cursor()

# Need to add exception handling here
cur.execute(sql)
rows = cur.fetchall()
cur.close()

# Populate arrays with data from SQL query
for r in rows:
    datetimes.append(r[0])
    usage.append(r[1])

dates = date2num(datetimes)

fig = pyplot.figure()
plot = fig.add_subplot(111)

plot.plot_date(dates, usage, xdate=True) # Set dates to x-axis
plot.set_title("TITLE")
plot.xaxis.set_major_locator(days)
plot.xaxis.set_major_formatter(date_format)
plot.set_xlabel("X AXIS LABEL")
plot.set_ylabel("Y AXIS LABEL")
fig.autofmt_xdate()

pyplot.savefig("Usage_Plot.png")
pyplot.show() # This may be unnecessary depending on how the server will output the graph





