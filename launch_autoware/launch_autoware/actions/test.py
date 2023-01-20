from typing import List
from launch import Action
from launch.frontend import expose_action
from launch.frontend import Entity
from launch.frontend import Parser
from launch.launch_context import LaunchContext

@expose_action("autoware")
class AutowareTest(Action):

    @classmethod
    def parse(cls, entity: Entity, parser: Parser):
        return cls, {}

    def execute(self, context: LaunchContext):
        print("Autoware")
