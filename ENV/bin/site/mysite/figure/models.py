## @package models
#
# Defines the class that makes up the relational database used for storing and visualizing the data

from django.db import models

class Usage(models.Model):
	device_usage = models.IntegerField(default=0)
	time_stamp = models.DateTimeField('time recorded')

class Choice(models.Model):
	question = models.ForeignKey(Usage)


