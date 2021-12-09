def create_file_preprocessing(source_files, flags, folder_name='generated'):
    """
    This function creates tpips file with preprocessing based on parameters
    :param source_files: [str, str] - list of paths to source files
    :param flags: [str, str] - list of compilation flags
    :param folder_name: str, folder name after tpips
    :return: list of str, tpips file
    """
    flag_string = generate_flag_string(flags)
    source_string = generate_source_string(source_files, folder_name)

    tpips_file = ["delete {}".format(folder_name)] + flag_string + source_string + [
        "setproperty ABORT_ON_USER_ERROR TRUE",
        "setproperty MEMORY_EFFECTS_ONLY FALSE",
        "apply UNSPLIT",
        "close", "quit"]
    return tpips_file


def create_tpips_unrolling(source_files, flags, factor, label, function, folder_name='generated'):
    """
    This function creates tpips file with unrolling based on parameters

    :param source_files: [str, str] - list of paths to source files
    :param flags: [str, str] - list of compilation flags
    :param label: str, label to apply unrolling
    :param factor: int, unrolling factror
    :param function: str, function to apply tiling
    :param folder_name: str, folder name after tpips
    :return: list of str, tpips file
    """
    flag_string = generate_flag_string(flags)
    source_string = generate_source_string(source_files, folder_name)
    tpips_file = ["delete {}".format(folder_name)] + flag_string + source_string + [
        "setproperty ABORT_ON_USER_ERROR TRUE",
        "setproperty MEMORY_EFFECTS_ONLY FALSE",
        'apply UNROLL[{}]'.format(function), label,
        str(factor), "apply UNSPLIT",
        "close", "quit"]

    return tpips_file


def generate_flag_string(flags):
    """
    This function generates string of compilation flags that will be used by PIPS
    :param flags: list of string, list of compilation flags to apply
    :return: string, compilation string that contains all flags
    """
    flag_string = 'setenv PIPS_CPP_FLAGS '
    if len(flags) == 0:
        flag_string = ''
    else:
        for flag in flags:
            flag_string += ' {}'.format(flag)
    return flag_string


def generate_source_string(source_files, folder_name):
    """
    This function generates source string based on input source files
    :param source_files: [str, str] - list of paths to source files
    :param folder_name: folder_name: str, folder name after pips
    :return: string that contains all folders names in a proper format
    """
    source_string = 'create {} '.format(folder_name)
    for source_file in source_files:
        source_string += source_file + ' '
    return source_string


def create_tpips_tiling(source_files, flags, directions, matrix, label, function, cache, folder_name='tiling'):
    """
    This function creates tpips file with tiling based on parameters

    :param source_files: [str, str] - list of paths to source files
    :param flags: [str, str] - list of compilation flags
    :param label: str, label to apply tiling
    :param function: str, function to apply tiling
    :param cache: str, cache size
    :param directions: list, list of scanning directions
    :param matrix:  list, list of partitioning vectors to apply tiling
    :param folder_name: str, folder name after pips
    :return: list of str, tpips file
    """
    flag_string = generate_flag_string(flags)
    source_string = generate_source_string(source_files, folder_name)
    tpips_file = ["delete {}".format(folder_name)]
    tpips_file += [flag_string, source_string]
    tpips_file += [
        "setproperty ABORT_ON_USER_ERROR TRUE",
        'setproperty PRETTYPRINT_LANGUAGE "C"',
        'setproperty PRETTYPRINT_STATEMENT_NUMBER FALSE',
        'setproperty PRETTYPRINT_INTERNAL_INTRINSICS FALSE',
        'setproperty FOR_TO_DO_LOOP_IN_CONTROLIZER TRUE']

    tpips_file += directions
    tpips_file += ['setproperty PRETTYPRINT_MOVE_ALL_LOOP_BOUNDS_UP FALSE',
                   'setproperty PRETTYPRINT_EXPAND_MIN_MAX_MACROS TRUE',
                   'apply PARALLEL_LOOP_TILING[{}]'.format(function),
                   label]
    tpips_file += matrix
    tpips_file += ['display PRINTED_FILE[{}]'.format(function), 'apply PRIVATIZE_MODULE[{}]'.format(function),
                   'activate PRINT_PARALLELIZEDOMP_CODE', 'apply COARSE_GRAIN_PARALLELIZATION[{}]'.format(function),
                   'display PRINTED_FILE[{}]'.format(function), 'apply CLEAN_LABELS[{}]'.format(function),
                   'apply KEEP_ONLY_ONE_EXTERN_PARALLEL_LOOP[{}]'.format(function), "apply UNSPLIT",
                   "close", "quit"]
    return tpips_file

