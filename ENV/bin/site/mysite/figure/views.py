from django.shortcuts import render
from django.template import RequestContext, loader
from django.http import HttpResponse
from .models import Usage
from django.http import Http404

def index(request):
	usage_list = Usage.objects
	template = loader.get_template('figure/index.html')
	context = RequestContext(request, {
		'usage_list': usage_list,

		})
	return HttpResponse(template.render(context))

def detail(request, usage_id):
	try:
		usage = Usage.objects.get(pk=usage_id)
	except Usage.DoesNotExist:
		raise Http404("Entry does not exist")
	return render(request, 'figure/detail.html', {'usage': usage})