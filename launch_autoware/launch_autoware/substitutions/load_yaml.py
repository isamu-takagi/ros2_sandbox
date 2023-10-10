from typing import Sequence
from typing import Text
from launch.frontend.expose import expose_substitution
from launch.substitution import Substitution
from launch.some_substitutions_type import SomeSubstitutionsType
from launch.launch_context import LaunchContext
from launch.utilities import perform_substitutions
from launch.utilities import normalize_to_list_of_substitutions

@expose_substitution("load-yaml")
class LoadYaml(Substitution):

    def __init__(self, path: SomeSubstitutionsType):
        super().__init__()
        self.__path = normalize_to_list_of_substitutions(path)

    @classmethod
    def parse(cls, data: Sequence[SomeSubstitutionsType]):
        if len(data) != 1 and len(data) != 2:
            raise TypeError("load-yaml substitution expects 1 or 2 arguments")
        return cls, {"path": data[0]}

    def perform(self, context: LaunchContext) -> Text:
        path = perform_substitutions(context, self.__path)
        return path + " BBBBB"
