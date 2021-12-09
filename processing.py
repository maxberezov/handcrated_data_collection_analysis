import numpy as np
import pandas as pd

features_path = '/home/maksim/PycharmProjects/unrolling/Features/test_features'
features = pd.read_csv(features_path)
features.set_index('label', inplace=True)
features_yuki = features.iloc[:, 3:]
features_liu = features.iloc[:, 0:3]
result_yuki = features_yuki.dropna()
X = result_yuki
z = 1


def get_central_point(grid):
    central = [0, 0, 0, 0, 0, 0]
    for arr in grid:
        central += arr
    central = list(central)
    central = [x / len(grid) for x in central]
    return central


def get_distance(p1, p2):
    distance = 0
    for d in range(len(p1)):
        distance += abs(p1[d] - p2[d])
    return distance


def rank_all_points(grid, p):
    distances = [0] * len(grid)
    for idx, arr in enumerate(grid):
        distances[idx] = get_distance(arr, p)
    return list(grid[np.argmin(distances)])


def iterative_ranking(grid, pool):
    distances = [[] for _ in range(len(grid))]
    for idx, arr in enumerate(grid):
        for p in pool:
            distances[idx].append(get_distance(arr, p))

    distances = [min(x) for x in distances]

    return list(grid[np.argmax(distances)])


def gds(grid, limit):
    labeled = []
    first_point = rank_all_points(grid, get_central_point(grid))
    labeled.append(first_point)
    grid.remove(first_point)

    while len(labeled) != limit:
        new_point = iterative_ranking(grid, labeled)
        labeled.append(new_point)
        grid.remove(new_point)

    return labeled


def gds_y(grid, limit):
    labeled = []
    first_point = rank_all_points(grid, get_central_point(grid))
    labeled.append(first_point)
    grid.remove(first_point)

    while len(labeled) != limit:
        new_point = iterative_ranking(grid, labeled)
        labeled.append(new_point)
        grid.remove(new_point)

    return labeled


def label_matching(pool, X):
    indexes = []

    arr = X.values.tolist()
    for p in pool:
        for idx, a in enumerate(arr):
            if p == a:
                if idx not in indexes:
                    indexes.append(idx)
    return indexes
