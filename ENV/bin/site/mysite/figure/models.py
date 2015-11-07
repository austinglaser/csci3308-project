from django.db import models

# Create your models here.
class Usage(models.Model):
	device_usage = models.IntegerField(default=0)
	time_stamp = models.DateTimeField('time recorded')

class Choice(models.Model):
	question = models.ForeignKey(Usage)


