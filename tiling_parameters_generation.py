from typing import List, Iterable, Tuple
from settings import size_ranges_tiling, sizes_cubic_search
from settings import tile_directions_general as tile_directions
from settings import local_tile_directions_general as local_tile_directions
from settings import local_tile_directions_rectangular, tile_directions_rectangular


def create_2d_matrix(x1: int, y1: int, x2: int, y2: int) -> List[str]:
    """
    This function generates 2d matrix string that will be used by tiling optimization
    :param x1: coordinate
    :param y1: coordinate
    :param x2: coordinate
    :param y2:coordinate
    :return: output string with matrix
    """
    matrix = ['{} {}'.format(x1, x2), '{} {}'.format(y1, y2)]
    return matrix


def create_3d_matrix(x1: int, y1: int, z1: int, x2: int, y2: int, z2: int, x3: int, y3: int, z3: int) -> List[str]:
    matrix = ['{} {} {}'.format(x1, x2, x3), '{} {} {}'.format(y1, y2, y3), '{} {} {}'.format(z1, z2, z3)]
    return matrix


def generate_3d_matrices(size_ranges: Iterable[int] = size_ranges_tiling) -> List[Tuple[List[str], bool]]:
    matrices = []
    sizes = [2 ** x for x in size_ranges]
    shape = True

    for dim1 in sizes_cubic_search:
        for dim2 in sizes_cubic_search:
            for dim3 in sizes_cubic_search:
                matrices.append((create_3d_matrix(dim1, 0, 0, 0, dim2, 0, 0, 0, dim3), shape))  # rect case

    shape = False
    for dim in sizes:
        matrices.append((create_3d_matrix(dim, 0, 0, 0, dim, 0, dim, -dim, -dim), shape))
        matrices.append((create_3d_matrix(dim, -dim, -dim, 0, dim, 0, 0, 0, dim), shape))
        matrices.append((create_3d_matrix(dim, 0, 0, dim, -dim, -dim, 0, 0, dim), shape))

    return matrices


def generate_2d_matrices(size_ranges: Iterable[int] = size_ranges_tiling) -> List[Tuple[List[str], bool]]:
    """
    This function generates all possible rectangular and diamond matrices according to the given range
    :param size_ranges: range of possible matrix shapes
    :return:  list of strings of all possible rectangular and diamond matrices according to considerable range
    """
    matrices = []
    sizes = [2 ** x for x in size_ranges]
    for dim1 in sizes:
        for dim2 in sizes:
            matrices.append((create_2d_matrix(dim1, 0, 0, dim2), True))  # rectangular
            matrices.append((create_2d_matrix(dim1, dim2, dim1, -dim2), False))  # diamond
    return matrices


def generate_scanning_directions(cubic_space: bool) -> List[List[str]]:
    """
    This function generates all possible combinations of scanning directions
    :return: List of all possible scanning directions
    """
    directions = []

    inter_direction = tile_directions
    intra_direction = local_tile_directions
    if cubic_space:
        inter_direction = tile_directions_rectangular
        intra_direction = local_tile_directions_rectangular

    for tile_dir in inter_direction:
        for loc_dir in intra_direction:
            directions.append(['setproperty TILE_DIRECTION "{}"'.format(tile_dir), 'setproperty LOCAL_TILE_DIRECTION '
                                                                                   '"{}"'.format(loc_dir)])
    return directions


def generate_shapes_directions():
    corresponding = {}
    matrices = generate_2d_matrices() + generate_3d_matrices()

    for idx, matrix in enumerate(matrices):
        shape, direction_specification = matrix
        corresponding[idx] = generate_scanning_directions(direction_specification)

    matrices = [x[0] for x in matrices]
    return corresponding, matrices