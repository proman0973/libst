#include <iostream>

#include "../libst.hpp"

struct Disconnected {
    Disconnected() { std::cout << "Disconnected" << std::endl; }
};

struct Connecting {
    Connecting() { std::cout << "Connecting" << std::endl; }
};

struct Connected {
    Connected() { std::cout << "Connected" << std::endl; }
};

int main() {
    using State = st::state<Disconnected, Connecting, Connected>;

    auto stateMachine = st::state_machine_builder<State>()
            .add_matcher([](Disconnected& state) -> st::ret<State> { return Connecting(); })
            .add_matcher([](Connecting& state) -> st::ret<State> { return Connected(); })
            .add_matcher([](Connected& state) -> st::ret<State> { return std::nullopt; })
            .build();

    while (true) {
        stateMachine.update();
    }

    return 0;
}