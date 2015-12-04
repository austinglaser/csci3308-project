## @package views
#
# Contains the functions required for building the pages defined in urls, reading and exporting the database

from django.shortcuts import render
from django.template import RequestContext, loader
from django.http import HttpResponse
from django.http import Http404
from django.db import connections
from django.db.models import Count
from django.http import JsonResponse
from django.core import serializers
import djqscsv

from .models import Usage

##
# @param name Name of the page 
# @param request An HTTP request
# @param template The index.html template defined in the templates folder 
# @return An HTTP Response that renders the webpage
#
# Creates default template page
def page(request, name, template):
	usage_list = Usage.objects
	template = loader.get_template('%s/%s' % (template, name))
	context = RequestContext(request, {
		'usage_list': usage_list,
		})
	return HttpResponse(template.render(context))

##
# @param name The default index.html page
# @param request An HTTP request
# @return The index.html page
#
# Returns the index.html page when visiting /figure
def page_figure(request, name="index.html"):
	return page(request, name, "figure")

##
# @param name The name of an html file
# @param request An HTTP request
# @return The graph.html page
#
# Returns graph.html when visiting /graph
def page_graph(request, name="graph.html"):
	return page(request, name, "graph")

##
# @param request An HTTP request
# @return A JSON reponse with the raw data from the database
#
# Returns data in raw JSON format
def usage_data(request):
	data = Usage.objects.all() \
		.values('time_stamp', 'device_usage')
	return JsonResponse(list(data), safe=False)
##
# @param request An HTTP request
# @return A csv file containging the database data
#
# Exports data as csv to be used by the plot.ly javascript library
def get_csv(request):
	qs = Usage.objects.all()
	return djqscsv.render_to_csv_response(qs)

##
# @param request An HTTP request
# @param usage_id An id corresponding the Usage class of the models.py file
#
# Displays an error page when trying to visit an invalid url
def detail(request, usage_id):
	try:
		usage = Usage.objects.get(pk=usage_id)
	except Usage.DoesNotExist:
		raise Http404("Entry does not exist")
	return render(request, 'figure/detail.html', {'usage': usage})
