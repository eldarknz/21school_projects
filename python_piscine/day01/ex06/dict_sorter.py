def sorted_values(dictionary):
    sorted_list_values = sorted([int(v) for v in dictionary.keys()], reverse=True)
    for value in sorted_list_values:
        print(dictionary[str(value)])

def main():
    numbers_and_countries = {
        '25': 'Brazil',
        '132': 'Germany',
        '178': 'Spain',
        '162': 'Italy',
        '17': 'Portugal',
        '3': 'Finland',
        '2': 'Hungary',
        '28': 'Canada',
        '610': 'The USA',
        '95': 'The United Kingdom',
        '83': 'China',
        '76': 'Iran',
        '65': 'Turkey',
        '34': 'Belgium',
        '26': 'Switzerland',
        '14': 'Austria',
        '12': 'Israel',
    }
    sorted_values(numbers_and_countries)

if __name__ == '__main__':
    main()
