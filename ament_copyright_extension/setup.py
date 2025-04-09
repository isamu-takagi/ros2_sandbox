from setuptools import find_packages, setup

package_name = "ament_copyright_extension"

setup(
    name=package_name,
    version="0.0.0",
    packages=find_packages(),
    package_data={"": ["template/*"]},
    data_files=[
        ("share/ament_index/resource_index/packages", [f"resource/{package_name}"]),
        (f"share/{package_name}", ["package.xml"]),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="Takagi Isamu",
    maintainer_email="isamu.takagi@tier4.jp",
    description="Add copyright templates that ament_copyright checks",
    license="Apache License 2.0",
    tests_require=["pytest"],
    entry_points={
        "ament_copyright.license": ["my_license = ament_copyright_extension.licenses:my_license"],
    },
)
