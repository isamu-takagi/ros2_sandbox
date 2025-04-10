from typing import Any, Sequence

from launch.frontend.expose import expose_substitution
from launch.launch_context import LaunchContext
from launch.some_substitutions_type import SomeSubstitutionsType
from launch.substitution import Substitution
from launch.utilities import normalize_to_list_of_substitutions, perform_substitutions

from ..utilities.struct_access import struct_get_field


@expose_substitution("struct-get")
class StructGet(Substitution):

    def __init__(self, field: SomeSubstitutionsType):
        super().__init__()
        self.__field = normalize_to_list_of_substitutions(field)

    @classmethod
    def parse(cls, data: Sequence[SomeSubstitutionsType]):
        if len(data) != 1 and len(data) != 2:
            raise TypeError("struct-get substitution expects 1 arguments")
        return cls, {"field": data[0]}

    def perform(self, context: LaunchContext) -> Any:
        field = perform_substitutions(context, self.__field)
        return struct_get_field(context.launch_configurations, field)
