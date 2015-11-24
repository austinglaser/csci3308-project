from django.conf.urls import url

from . import views
from .views import graph, usage_data, get_csv

urlpatterns = [
	url(r'^$', views.index, name='index'),
	url(r'^graph', views.graph, name='graph'),
	url(r'^api/usage_data', usage_data, name='usage_data'),
	url(r'^csv', get_csv, name='get_csv'),
	]