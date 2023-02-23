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

