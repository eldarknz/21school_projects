import os

def main():

    filename     = os.path.basename('d01_ds.csv')
    new_filename = os.path.splitext(filename)[0]
    new_file_ext = 'tsv'

    wf = open('{}.{}'.format(new_filename, new_file_ext), 'w')

    with open(filename) as rf:
        for line in rf:
            wf.write(line.replace(',', '\t'))

    wf.close()

if __name__ == '__main__':
    main()
