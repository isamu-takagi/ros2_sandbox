from typing import List

from launch import Action
from launch.frontend import Entity, Parser, expose_action
from launch.launch_context import LaunchContext


@expose_action("autoware")
class AutowareTest(Action):

    @classmethod
    def parse(cls, entity: Entity, parser: Parser):
        return cls, {}

    def execute(self, context: LaunchContext):
        print("Autoware")
        context.launch_configurations["autoware"] = {"str": "value", "num": "123"}
