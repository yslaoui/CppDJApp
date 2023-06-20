Here upon successful sale, we put money in or out of the wallet 

Observe that the matching algorithm is called in the goToNextTimeFrame() method. 
There, ad an if statement: if sale.username is user, do something in comments 
In the wallet class create a method called processSale() that returns void and takes as argument an orderBookEntry object called sale passed by reference.
Note that the wallet class does not know anything about the username. So this function assumes that the sale order was entered by the user. 
In the implementation for that function copy the contents of the canFullfullOrder() function. We will just adapt this code basically
In the if stamens replace the ask orderBookType by asksale and bid by bidsale respectively. 
Now for the if statement ask logic : remember that of you ask BTC/ETH, the outgoing currency is BTC and the incoming currency is ETH. Create these two variables and set their values accordingly using tokenize.  Then set up the incoming amount as the amount on the sale order and the outcoming amount as the product of amount and price in the sale order. Then update the wallet. Increase the incoming currency by the incoming amount and decrease the outcoming currency by the outgoing amount.  
Now for the of statememt bid logic. Copy the same code as tge ask logic above. Just change the indices in the tokenize function. 

Now back to the main App. Inside the if statement that you created in the goToNextTimeFrame(), call the processSale function. Note that it extends the wallet state variable and that it receives the sale OrderBookEntry object produced by the matching algorithm  as argument. 
Now test the app. First press 2 to print some stats. Observe what products you in the orderBook. As below 


Product: ETH/BTC 
Asks seen 49
Max ask: 0.0222704
Min ask: 0.0218909

So you are targeting the ETH/BTC order above and want to make a bid on it. You can because you have BTC in your wallet.  Verify that you have 10 BTC in your wallet First 
press 5
You chose: 5
Wallet has BTC ? 1
BTC 10.000000
USDT 990.000000

Then press 4 and place the following bid : offer to buy ETH on a 1/1 ratio on Bitcoin (which is a crazy price that ensures your order will be fulfilled) : ETH/BTC, 1, 1. The you should see that the wallet ca  fulfill order like this 

ETH/BTC,1,1
order is a bid, currency:  BTC amount 1
Order succesfully fullfilled



