import os

from ament_copyright.licenses import read_license_data

TEMPLATE_DIRECTORY = os.path.join(os.path.dirname(__file__), "template")
my_license = read_license_data(TEMPLATE_DIRECTORY, "My License", "", "my_license")
