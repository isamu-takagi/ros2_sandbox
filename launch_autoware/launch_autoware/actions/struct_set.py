from typing import List

from launch import Action
from launch.frontend import Entity, Parser, expose_action
from launch.launch_context import LaunchContext
from launch.some_substitutions_type import SomeSubstitutionsType
from launch.utilities import normalize_to_list_of_substitutions, perform_substitutions

from ..utilities.struct_access import struct_set_field


@expose_action("struct-set")
class StructSet(Action):

    def __init__(self, field: SomeSubstitutionsType, value: SomeSubstitutionsType) -> None:
        super().__init__()
        self.__field = normalize_to_list_of_substitutions(field)
        self.__value = normalize_to_list_of_substitutions(value)

    @classmethod
    def parse(cls, entity: Entity, parser: Parser):
        field = parser.parse_substitution(entity.get_attr("field"))
        value = parser.parse_substitution(entity.get_attr("value"))
        kwargs = super().parse(entity, parser)[1]
        kwargs["field"] = field
        kwargs["value"] = value
        return cls, kwargs

    def execute(self, context: LaunchContext):
        field = perform_substitutions(context, self.__field)
        value = perform_substitutions(context, self.__value)
        struct_set_field(context.launch_configurations, field, value)
