
#### Methods
- [x] value([int])
- [x] if(bool)
- [x] then(function)
- [x] else(function) 
- [ ] switch(bool)
- [ ] case(function)
- [ ] default(function)
- [x] map(function)
- [ ] flatMap(function)
- [ ] project


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

