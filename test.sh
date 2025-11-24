./test | ./checker_os
./test --bench --simple | ./checker_os
./test 42 | ./checker_os 42
A="10 20 30 40 45 46 47 48 49 500"; ./test $A | ./checker_os $A
./test 10 20 30 10
./test