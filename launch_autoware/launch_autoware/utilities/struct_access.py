from launch.substitutions.substitution_failure import SubstitutionFailure


def struct_get_field(data, field):
    for part in field.split("."):
        data = data[part]
        # if path not in context.launch_configurations:
        #    raise SubstitutionFailure("launch configuration '{}' does not exist".format(path))
    return data


def struct_set_field(data, parts):
    for part in parts:
        if part not in data:
            data[part] = {}
        data = data[part]
    return data
