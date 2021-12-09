import os
import datetime
import csv
import json
import glob


def get_timestamp():
    return datetime.datetime.now().timestamp()


def get_content(path):
    with open(path) as f:
        content = f.readlines()
    content = [x.strip() for x in content]
    return content


def rewrite(path, file):
    with open(path, 'w+') as f:
        for item in file:
            f.write("%s\n" % item)


def repeat_function(times, f, *args):
    for i in range(times): f(*args)


def do_for_all_files_in_directory(path, extension, f, *args):
    os.chdir(path)
    files = os.listdir(path)
    for item in files:
        if item.endswith(extension):
            target_path = os.path.join(path, item)
            f(target_path, *args)


def delete(path):
    os.remove(path)


def get_factor(path):
    file = path[path.rfind('/') + 1:]
    factor = file[2:file.index('.') - 2]
    return factor


def deletion(path, extension):
    do_for_all_files_in_directory(path, extension, delete)


def execution(path, extension, function):
    do_for_all_files_in_directory(path, extension, function)


def save_to_cvs(dictionary, target_dir):
    toCSV = dictionary
    keys = toCSV[0].keys()
    with open(target_dir, 'w') as output_file:
        dict_writer = csv.DictWriter(output_file, keys)
        dict_writer.writeheader()
        dict_writer.writerows(toCSV)


def save_list_to_separate_json_files(array, path, names):
    for idx, item in enumerate(array):
        abs_path = os.path.join(path, names[idx])
        with open(abs_path, 'w') as fp:
            json.dump(item, fp)


def files_to_file(directory, extension,target_path):
    files = os.path.join(directory, '*' + extension)
    list_of_files = glob.glob(files)
    list_of_files = ['.' + item[item.rfind('/') - 10:] for item in list_of_files]
    rewrite(target_path, list_of_files)