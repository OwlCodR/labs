# :books: Laboratory Work 1
---
## :page_facing_up: Task
> The initial for this task is the implementation of the Sequence<T> class, obtained as part of the course for the 2nd semester. You need to write a C ++ program to compare different sorting algorithms. Write a short technical task. Execute implementation. Write tests for it.

## :heavy_check_mark: **TODO**
- **Sorting algorithms**
    - [x] Quick sort `10 points`
    - [ ] Merge sort `7 points`
    - [ ] Simple insertion method `5 points`
- **Structure**
    - [x] Make `Sorter` class with static sorting functions `Sorter.some_sort(Sequence<T>* s, function<bool (T, T)> cmp)`
    - [ ] Make random generation of elements of `Sequence` as a constructor
    - [ ] Make function that will compare two alogorithms by time
    - [ ] Make function to check sorting time
    - [ ] Make console UI
- **Tests cases**
    - [ ] Big sizes of sequences | *more than 10.000 elements*
    - [ ] Not sorted
    - [ ] Already sorted
    - [ ] Already sorted in the opposite direction
    - [ ] Empty and one-element sequence
    - [ ] Max complexity of algorithms
- **Libraries to learn**
    - Utilities library
        - [x] `<functional>` | *since C++11*
    - Error handling
        - [ ] `<stdexcept>`
    - Tests
        - [ ] `<cassert>`
    - Numerics library
        - [ ] `<random>` | *since C++11*
- **Frameworks to learn**
    - Tests
        - [ ] [`Catch2`](https://github.com/catchorg/Catch2) | *since C++11* 
