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
                    return st::no_state;
                } else {
                    return OtherState();
                }
            })
            .add_matcher([](OtherState& state) -> st::ret<State> {
                std::cout << "Calculation finished" << std::endl;
                return st::no_state;
            })
            .build();
    
    while (true) {
        stateMachine.update();
    }
}
```