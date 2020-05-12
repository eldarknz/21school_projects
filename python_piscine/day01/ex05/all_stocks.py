from sys import argv

def check_valid():
    if len(argv) == 2 and isinstance(argv[1],  str):
        list_values = argv[1].split(',')
        for value in list_values:
            if value.isspace():
                return 0
        return list_values
    return 0

def handler(list_values, companies, stocks):
    if list_values:
        for value in list_values:
            value = value.strip()
            value_upper = value.upper()
            value_lower = value.lower()
            companies_name_lower = {k.lower():v for k,v in companies.items()}
            if value_upper in stocks:
                for k, v in companies.items():
                    if v == value_upper:
                        print('{} is a ticker symbol for {}'.format(value, k))
            elif value_lower in companies_name_lower:
                print('{} stock price is {}'.format(value, stocks[companies_name_lower[value_lower]]))
            else:
                print('{} is an unknown company or an unknown ticker symbol'.format(value))

def main():
    companies = {
        "Apple" : "AAPL",
        "Microsoft" : "MSFT",
        "Netflix" : "NFLX",
        "Tesla" : "TSLA",
        "Nokia" : "NOK"
    }
    stocks = {
        "AAPL" : 287.73,
        "MSFT" : 173.79,
        "NFLX" : 416.90,
        "TSLA" : 724.88,
        "NOK" : 3.37
    }

    list_values = check_valid()
    handler(list_values, companies,stocks)

if __name__ == '__main__':
    main()
