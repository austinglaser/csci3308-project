from django.shortcuts import render, render_to_response
from django.template import RequestContext, loader
from django.http import HttpResponse
from .models import Usage
from django.http import Http404
from chartit import DataPool, Chart

def index(request):
	usage_list = Usage.objects
	template = loader.get_template('figure/index.html')
	context = RequestContext(request, {
		'usage_list': usage_list,

		})
	return HttpResponse(template.render(context))

def chart_view(request):
	usagedata = \
		DataPool(
			series=
			[{'options': {
				'source': Usage.objects.all()},
				'terms': [
					'device_usage',
					'time_stamp']}
			])

	cht = Chart(
			datasource = usagedata,
			series_options = 
				[{'options': {
					'type': 'line',
					'stacking': False },
					'terms': {
						'time_stamp' : [
						'device_usage' ]
					}}],
			chart_options = 
				{'title': {
					'text': 'Usage Data' },
				'xAxis': {
					'title': {
						'text': 'Date'}}})

	return render_to_response({'usagechart': cht})

def detail(request, usage_id):
	try:
		usage = Usage.objects.get(pk=usage_id)
	except Usage.DoesNotExist:
		raise Http404("Entry does not exist")
	return render(request, 'figure/detail.html', {'usage': usage})