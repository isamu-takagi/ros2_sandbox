from setuptools import find_packages, setup

package_name = "template_package_python"

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
    maintainer="Takagi Isamu",
    maintainer_email="isamu.takagi@tier4.jp",
    description="This is a template package for Python",
    license="Apache License 2.0",
    tests_require=["pytest"],
)
