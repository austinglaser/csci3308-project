# Outletify Pyplot from SQL
# Jon Wehrend

import matplotlib
matplotlib.use('Agg')
import sqlite3
from matplotlib import pyplot
from matplotlib import dates as mdates
import datetime

# These should find the date info assuming we're using UTC
months = mdates.MonthLocator()
days = mdates.DayLocator()
hours = mdates.HourLocator()
date_format = mdates.DateFormatter("%a %d %b %Y") # Will output as Day of week, day, month

def make_plot(timestamps, usage):
    dates = []
    for ts in timestamps:
        dates.append(datetime.datetime.fromtimestamp(ts))

    fig = pyplot.figure()
    plot = fig.add_subplot(111)

    plot.plot_date(dates, usage, xdate=True) # Set x-axis to dates
    plot.set_title("Usage Statistics")
    plot.xaxis.set_major_locator(days)
    plot.xaxis.set_major_formatter(date_format)
    plot.set_xlabel("Date")
    plot.set_ylabel("Usage")
    fig.autofmt_xdate()

    pyplot.savefig("Usage_Plot.png")
    pyplot.close(fig)
    #pyplot.show() # This may be unnecessary depending on how the server will output the graph

