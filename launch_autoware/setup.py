from warnings import simplefilter

from pkg_resources import PkgResourcesDeprecationWarning
from setuptools import SetuptoolsDeprecationWarning
from setuptools import find_packages
from setuptools import setup

simplefilter("ignore", category=SetuptoolsDeprecationWarning)
simplefilter("ignore", category=PkgResourcesDeprecationWarning)

package_name = "launch_autoware"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(),
    data_files=[
        ("share/ament_index/resource_index/packages", [f"resource/{package_name}"]),
        (f"share/{package_name}", ["package.xml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="Takagi, Isamu",
    maintainer_email="isamu.takagi@tier4.jp",
    description="The launch tool extension for Autoware",
    license="Apache License 2.0",
    tests_require=["pytest"],
    entry_points={
        "launch.frontend.launch_extension": ["launch_autoware = launch_autoware"],
    }
)
