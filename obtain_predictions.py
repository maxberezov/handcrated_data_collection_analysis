from settings import size_ranges_tiling
from result_processing import get_speedup_matrix


def generate_possible_directions_for_data_sample(data_sample):

    directions = []
    for first_dim in size_ranges_tiling:
        for second_dim in size_ranges_tiling:
            data_sample['First_dim'] = first_dim
            data_sample['Second_dim'] = second_dim
            directions.append(data_sample)
    return directions


def get_predictions(classifier, data):
    predictions = []
    for data_sample in data:
        predictions.append(classifier.predict(data_sample))
    return predictions

