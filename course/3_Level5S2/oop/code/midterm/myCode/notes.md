In the first task, you need to compute candlestick data from the exchange data for a particular
product. Here is an example of the fields needed for candlestick data:
Date       Open High Low Close
2023-05-01  100  120   80   110
2023-05-02  110  130  100   120
2023-05-03  90   100  70     80
2023-05-04  95   110  70   100
2023-05-05  80   120  75  115
Note that you will need to do this separately for asks and bids, and separately for different products.
So the table above might be the candlestick data for ‘asks on ETH/UDST’, for example.
Here is how you can compute each field:
Open = the average price per unit in the previous time frame. So say we want to compute the value
for ETH/USDT asks from the list of items from the order book, which are all asks for ETH/USDT:

Amount  Price   Value (price X amount)
10       1         10
5        2         10
15       3          20
                    6.67 

You can see that the mean price is 6.67.
Close: the average price per unit in this time frame (same as Open, but for the current time frame)
High: highest price seen this time frame
Low: lowest price seen this time frame
You should implement the candlestick data computation using a function which returns the
following data type:
std::vector<Candlestick>
Note that it returns a vector of Candlestick objects. You will need to define your own Candlestick
class that is suitable for representing candlestick data. One Candlestick object represents one
candlestick.

# pseudocode

We need to create two things here 
* A candleStick class whose data members are 
   - Date
   - Open 
   - High 
   - Low 
   - close
   - product
   - orderType (bid or ask)
* A constructor for the candleStick class. What the constructor does is 
   -  It creates an object of class Orderbook. Like this OrderBook orderBook{"20200601.csv"};
   - It initializes the arguments using an initializer list  

steps to compute the high variable
entries = orders.getOrders(candlestick.orderType, candlestick.product, candlestick.timeStamp)
high = OrderBook::getHigherPrice(entries)
low = OrderBook::getLowerPrice(entries)

