from django.test import TestCase
from figure.models import Usage

# Create your tests here.
class FigureTest(TestCase):

	def test_str(self):

		entry = Usage(device_usage=0, time_stamp='2015-10-30 15:06')

		self.assertEquals(
			str(entry),
			,
			)

		