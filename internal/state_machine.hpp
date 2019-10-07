#pragma once

#include "detail.hpp"

namespace st {
    template<typename State, typename ... Matchers>
    class state_machine {
    public:
        explicit state_machine(detail::overloaded<Matchers...> matcher)
                : m_matchers(std::move(matcher)) {}

        void update() {
            typename State::return_type state = match(m_state, m_matchers);

            if (state) {
                m_state = *state;
            }
        }

    private:
        typename State::internal_type m_state;
        detail::overloaded<Matchers...> m_matchers;
    };
}