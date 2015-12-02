## @package plot
# Interface to pyplot for rendering Outletify data

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

##
# @param timestamps Timestamp values to be plotted
# @param usage Usage values to be plotted
#
# Creates an image 'Usage_Plot.png' with a plot of all the timestamp and usage
# values supplied.
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

