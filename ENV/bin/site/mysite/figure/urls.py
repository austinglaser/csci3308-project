from django.conf.urls import url

from . import views

urlpatterns = [
	url(r'^(.*\.html)$', views.page_figure, name='index'),
	url(r'^$', views.page_figure, name='index'),
	url(r'^graph', views.page_graph, name='graph'),
	url(r'^api/usage_data', views.usage_data, name='usage_data'),
	url(r'^csv', views.get_csv, name='get_csv'),
	]
