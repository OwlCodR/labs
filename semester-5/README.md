# :books: Laboratory Work 1
---
## **Task**
> The task is to implement the mathematical expression API. Executing code like the one in the example below results in the construction of an expression that can then be executed. The execution must be started by the .Eval() method.

Basic task: the parallelism of calculations is achieved through the multi-threaded implementation of individual operations (such as map, flatMap and the special case of reduce/fold, when the argument function is an associative operation).

Extended task:
1. Parallelization of calculations at the level of processing the expression tree (for example, through the implementation of the task manager)
2. Execution of expressions in asynchronous mode

#### Methods
- [x] value
- [x] if-then-else
- [x] then
- [x] switch-case-default
- [x] every
- [x] project
- [x] map
- [x] joinValues
- [x] all
- [ ] any
- [ ] fold
- [ ] flatMap
- [ ] zip
- [ ] unzip

#### How to use
```c++
Expression e = Expression
    .value([1, 2])
    .map(x => [](int value) { return value * 2 })
    .if([]() {return value > 2})
    .then([]() {return value + 1})
    .else([]() {return value - 1})
    .every(
        [](value1, value2){
            return value1 + value2;
        },
        [](value1, value2){
            return value1 - value2;
        },
    )
    .then([](sum, diff) {return sum + diff})
```

