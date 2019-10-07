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