#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

enum class OrderBookType
{
    bid,
    ask
};

/**
 * to_string converts order type to printable string
 */
std::string to_string(OrderBookType type)
{
    switch (type)
    {
    case OrderBookType::bid:
        return "bid";
    case OrderBookType::ask:
        return "ask";
    default:
        return "unknown";
    }
}

class OrderBookEntry
{
public:
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType type;

    /**
     *OrderBookEntry contstructor take 5 arguments
     */
    OrderBookEntry(double _price, double _amount,
                   std::string _timestamp, std::string _product,
                   OrderBookType _type);
    /**
     *Print all OrderBookEntry parameters. 
     */
    void printOrderBookEntry() const;
};

OrderBookEntry::OrderBookEntry(double _price, double _amount,
                               std::string _timestamp, std::string _product,
                               OrderBookType _type)
    : price(_price), amount(_amount), timestamp(_timestamp),
      product(_product), type(_type)
{
}

void OrderBookEntry::printOrderBookEntry() const
{
    std::cout << "Price : " <<std::setw(10)<<std::left<<price << " Amount : "<<std::setw(9) << amount << " Timestamp : " << timestamp
              << " Product : " << product << " OrderBookType : " << to_string(type) << std::endl;
}

/**
 * computeAverage function return average of all OrderBookEntry prices
 * present in vector
 */
double computeAveragePrice(std::vector<OrderBookEntry> &entries)
{
    size_t size = entries.size();
    if (size > 0){
        double sum = 0;
        for (const OrderBookEntry &entry : entries)
        {
            sum += entry.price;
        }
        return sum / size;
    }else{
        return 0;
    }
}
/**
 * computeLowPrice retun low price from all OrderBookEntry prices
 * present in vector
 */
double computeLowPrice(std::vector<OrderBookEntry> &entries){

    double lowPrice = INT64_MAX;
    for (const OrderBookEntry &entry : entries){
        if (entry.price < lowPrice)
            lowPrice = entry.price;
    }
    return lowPrice;
}

/**
 * computeHighPrice retun high price from all OrderBookEntry prices
 * present in vector
 */
double computeHighPrice(std::vector<OrderBookEntry> &entries){
    double highPrice = 0;
    for (const OrderBookEntry &entry : entries){
        if (entry.price > highPrice)
            highPrice = entry.price;
    }
    return highPrice;
}

/**
 * computePriceSperad retun differece between highest bid price and lowest ask price 
 * of all OrderBookEntry prices present in vector
 */
double computePriceSpread(std::vector<OrderBookEntry> &entries){
    std::vector<OrderBookEntry> bidVector;
    std::vector<OrderBookEntry> askVector;
    
    for (const OrderBookEntry &entry : entries){
        if(entry.type == OrderBookType::ask){
            askVector.push_back(entry);
        }else{
            bidVector.push_back(entry);
        }
    }

    return computeHighPrice(bidVector) - computeLowPrice(askVector);
}

int main()
{

    std::vector<OrderBookEntry> orderBookEntryVector;
//Create objects for bid order entry type
    OrderBookEntry bid1{0.02187308, 7.44564869, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid};
    OrderBookEntry bid2{0.02187307, 3.467434, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid};
    OrderBookEntry bid3{0.02187305, 6.85567013, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid};
    OrderBookEntry bid4{0.021873, 1.345345, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid};
    OrderBookEntry bid5{0.03187163, 0.03325, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid};
//Create objects for ask order entry type
    OrderBookEntry ask1{0.02189093, 9.80492203, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask};
    OrderBookEntry ask2{0.02189094, 10.91645003, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask};
    OrderBookEntry ask3{0.02189096, 6.85752424, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask};
    OrderBookEntry ask4{0.02189398, 9.14003499, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask};
    OrderBookEntry ask5{0.02189399, 9.14068583, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::ask};
//add all order entries to orderBookEntryVector
    orderBookEntryVector.push_back(bid1);
    orderBookEntryVector.push_back(bid2);
    orderBookEntryVector.push_back(bid3);
    orderBookEntryVector.push_back(bid4);
    orderBookEntryVector.push_back(bid5);

    orderBookEntryVector.push_back(ask1);
    orderBookEntryVector.push_back(ask2);
    orderBookEntryVector.push_back(ask3);
    orderBookEntryVector.push_back(ask4);
    orderBookEntryVector.push_back(ask5);
    //Print all OrderBookEntries from the orderbook entry vector
    for (const OrderBookEntry &entry : orderBookEntryVector){
        entry.printOrderBookEntry();
    }

    std::cout << "Low Price            : " << computeLowPrice(orderBookEntryVector) << std::endl;
    std::cout << "Hight Price          : " << computeHighPrice(orderBookEntryVector) << std::endl;
    std::cout << "Compute Average      : " << computeAveragePrice(orderBookEntryVector) << std::endl;
    std::cout << "Compute Price Spread : " << computePriceSpread(orderBookEntryVector)<<std::endl;

    return 0;
}