CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
...CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
....CsvReader::readCSV - Successful open
CsvReader::stringsToOBE(oneArg) Bad price 4.6361e-310 or amount 6.95277e-310
bad float at row number 3530
Number of successuly read lines 3530
...orders[0].price 0.0218731
F.CsvReader::readCSV - Successful open
bad float at row number 4
Number of successuly read lines 3
F.CsvReader::readCSV - Successful open
bad float at row number 4
Number of successuly read lines 3
..CsvReader::readCSV - Successful open
Number of successuly read lines 99
test_matchOrders(): size of sales  1
price  0.0218909
amount  7.44565
F.before
BTC 10.000000

after
outgoingCurrency BTC
incomingCurrency ETH
BTC 9.000000
ETH 1.000000

.2020/06/01 11:57:30.328127



!!!FAILURES!!!
Test Results:
Run:  16   Failures: 3   Errors: 0


1) test: test_insertOrder (F) line: 83 ./OrderBook_test.cpp
assertion failed
- Expression: orders.size() == initialSize + 1


2) test: test_comparePriceAsc (F) line: 94 ./OrderBook_test.cpp
assertion failed
- Expression: result == true


3) test: test_matchOrders (F) line: 115 ./OrderBook_test.cpp
assertion failed
- Expression: result[0].price == 10