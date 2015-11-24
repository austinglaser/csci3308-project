from django.shortcuts import render
from django.template import RequestContext, loader
from django.http import HttpResponse
from django.http import Http404
from django.db import connections
from django.db.models import Count
from django.http import JsonResponse
from django.core import serializers

from .models import Usage

def index(request):
	usage_list = Usage.objects
	template = loader.get_template('figure/index.html')
	context = RequestContext(request, {
		'usage_list': usage_list,

		})
	return HttpResponse(template.render(context))

def graph(request):
	return render(request, 'graph/graph.html')

def usage_data(request):
	data = Usage.objects.all() \
		.values('time_stamp', 'device_usage')
	return JsonResponse(list(data), safe=False)

def detail(request, usage_id):
	try:
		usage = Usage.objects.get(pk=usage_id)
	except Usage.DoesNotExist:
		raise Http404("Entry does not exist")
	return render(request, 'figure/detail.html', {'usage': usage})