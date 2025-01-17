# libst library
C++17 header only compile time state machine implementation

* Zero dependencies (Only STL includes)
* Compiles fast

## Example usage
```cpp
#include <libst.hpp>
#include <iostream>

struct SomeState {
    int data = 0;
};

struct OtherState {};

using State = st::state<SomeState, OtherState>;

int main(int argc, char** argv) {
    auto stateMachine = st::state_machine_builder<State>()
            .add_matcher([](SomeState& state) -> st::ret<State> {
                if (state.data < 10) {
                    state.data++;
                    std::cout << "Data is " << state.data << std::endl;
                    return st::no_state;
                } else {
                    std::cout << "Calculation finished" << std::endl;
                    return OtherState();
                }
            })
            .add_matcher([](OtherState& state) -> st::ret<State> {
                // Never ending state
                return st::no_state;
            })
            .build();

    while (true) {
        stateMachine.update();
    }
}
```

Output
```
Data is 1
Data is 2
Data is 3
Data is 4
Data is 5
Data is 6
Data is 7
Data is 8
Data is 9
Data is 10
Calculation finished
```