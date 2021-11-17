# :books: Laboratory Work 1
---
## :page_facing_up: Task
> The initial for this task is the implementation of the Sequence<T> class, obtained as part of the course for the 2nd semester. You need to write a C ++ program to compare different sorting algorithms. Write a short technical task. Execute implementation. Write tests for it.

## :heavy_check_mark: **TODO**
- **Sorting algorithms**
    - [x] Quick sort `10 points`
    - [x] Merge sort `7 points`
    - [x] Simple insertion method `5 points`
- **Structure**
    - [x] Make `Sorter` class with static sorting functions `Sorter.some_sort(Sequence<T>* s, function<bool (T, T)> cmp)`
    - [ ] Make random generation of elements of `Sequence` as a constructor
    - [x] Make function that will compare two algorithms by time
    - [x] Make function to check sorting time
    - [x] Make terminal UI
- **Tests cases**
    - [x] Big sizes of sequences | *more than 10.000 elements*
    - [x] Not sorted
    - [x] Already sorted
    - [x] Already inverse sorted
    - [x] Empty and one-element sequence
    - [ ] Max complexity of algorithms
    - Different sequences
        - [x] ArraySequence
        - [ ] ListSequence
        - [ ] VectorSequence
    - Compare function
        - [ ] Direct sort
        - [ ] Inverse sort
        - [ ] Unique sort
    - Different types of data
        - [x] int
        - [x] double
        - [ ] std::complex
        - [ ] Custom class
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
        - [x] [`Catch2`](https://github.com/catchorg/Catch2) | *since C++11*
        - [x] [`Boost.Test`](https://www.boost.org/)
    - Documentation
        - [x] [`Doxygen`](https://www.doxygen.nl/index.html)
        
- **Programs to learn**
    - [x] [`CMake`](https://cmake.org/)

## Help
> Generate documentation
> ```sh
> $ cd docs
> $ doxygen Doxyfile
> ```
