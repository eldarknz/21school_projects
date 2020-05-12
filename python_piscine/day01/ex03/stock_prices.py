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

    ticker = ''

    if len(argv) == 2:
        if argv[1] in companies:
            ticker = companies[argv[1]]
            print(stocks[ticker])
        else:
            print("Unknown company")

if __name__ == '__main__':
    main()
