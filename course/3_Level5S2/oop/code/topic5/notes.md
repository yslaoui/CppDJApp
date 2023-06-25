
* Create a car class with a speed data member and an accelerate method. The data member is private Implement the constructor. Use initializer list to Inialize the fata member at zero. mplement accelerate function. Increase speed by 0.5. 
* In main create a car object. Note that you need not password any argument because the argument initializes at 0.  Them call the function accelerate on the car 
* Now question. What is the state of the  car at this point ? Answer: The state of the car is represented by its data member speed. That state of the car is that its speed value is 0.5. 
* Now create an instance car2. Call the accelerate method on it twice. What is its state ? Its speed is 1.0
* So, each instance of the class has its own state and its own memory of what ots data member variable is set to. Each object is wrapping up a set of variables and can work with yhise over time 


Static functions like the csv reader, are stateless. They do not need to remember the state of the object. They do not need to access the state of t
Create a a static method called which is faster that takes two arguments carA and carB and returns true of carA is faster and 0 otherwise 
So you do not need to extend a static function from the state variable 
Oftentimes static functions are used as utility functions. You use them when you do not need to interact with the object. 
So a key idea in objects oriented programming is that the class has a state of the State and each object has methods that can change the states over time. When a method doesn't have to change the state then it is better to Define it as static which which means that it doesn't change the state over time
So a good minimal is to think of static functions as static helper functions


