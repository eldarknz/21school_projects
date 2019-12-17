import argparse
import time
import os

def main():
    ap = argparse.ArgumentParser(allow_abbrev=False)

    ap.add_argument('--input_file', type=str, required=True, help='input exmaple file')

    args = vars(ap.parse_args())
    start_time = time.time()

    input_file = args['input_file']

    figures = []

    try:
        if input_file is not None and os.path.isfile(input_file):
            # read line by line from a file with class names
            with open(input_file, 'r') as rf:
                figure = []
                for line in rf:
                    if len(line.strip()) > 0:
                        if line[-1] == '\n':
                            line = line[:-1]
                        figure.append(line)
                    else:
                        if bool(figure):
                            figures.append(figure)
                        figure = []
        for figure in figures:
            for line in figure:
                print(line)
            print('-----------')

    except Exception as ex:
        print('Exception ---->', ex, sep=' ')

    print("--- {} seconds ---".format(time.time() - start_time))


if __name__ == '__main__':
    main()
