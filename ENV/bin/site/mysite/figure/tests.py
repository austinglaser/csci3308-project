from django.test import TestCase
from figure.models import Usage
   
class UsageTestCase(TestCase):
	def setUp(self):
		self.entry = Usage.objects.create(device_usage=10, time_stamp='2015-11-11 20:20')

	def test_entry(self):
		self.assertEqual(self.entry.device_usage, 10)
		self.assertEqual(self.entry.time_stamp, '2015-11-11 20:20')