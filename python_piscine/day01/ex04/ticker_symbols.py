from sys import argv

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

    if len(argv) == 2:
        if argv[1] in stocks:
            for key, value in companies.items():
                if value == argv[1]:
                    print('{} {}'.format(key, stocks[argv[1]]))
        else:
            print("Unknown ticker")

if __name__ == '__main__':
    main()
