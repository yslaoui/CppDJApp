## The code to Inserting the order into the orderBook 

* In the OrderBook.h create a function insertOrder() that takes as input an OrderBook. It returns void. The 8nout is passed by reference because we will modified the orderBook Entry terms as argument

* Now implement. Push the order arguments into the orders data member of the OrderBook class.  Std::sort needs a third argument which is a custom function that compares two elements of a vector and returns true of the elements are IN the correct order and false otherwise. We need to build that functioning 

* So In the orderBookEntry class, create that function. It must be a static functions because it will not be called in the form orders.finction, it will take two orherBookEntry objects as arguments. It takes as argument two OrdeBookEntry objects e1 and e2 passed as reference and it returns a boolean. The content of the function is just ine line of code since you are comparing timestamp strings. 

* Then pass that function as a third argument to std::sort in OrderBook.cpp . The first argument is orders.begin() and the second is orders.end(). 
Now that you defined the function you must use it. 

* Go back to MerkelMain, in the enterAsk() function, inside the try block, and call the insertOrder function and pass to it the obe object. 

* Now test the insertOrder() function. create a csv file with a sample of three orders and play with it

** Test 1 :Now test that ir works. First check the number of asks aska printed in the console for the first produiroductt in the product map by entering 2. Then press 3 and pass an order with that product. The enter 2 again to print stats. Then see if the number of asks increased by one for that product. That is check if asks seen increased. 
Test 2: Now press 6 to go to the next time frame. Check that you are in the mext time frame. Enter two orders. Check that the number of asks seen increased by 2. This time window has two extra asks in now
Test 3: press 6 continuously until you revert back to the first time frame. Then in ghat time frame print stats an verify that the number of asks seen in still incremented by one


ETH/BTC
49 then 50