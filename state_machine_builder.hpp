#pragma once

#include "state_machine.hpp"

#include <tuple>

namespace st {
    template<typename State, typename ... Matchers>
    class state_machine_builder {
    public:
        constexpr state_machine_builder() = default;
        constexpr explicit state_machine_builder(std::tuple<Matchers...> matchers) : m_matchers(std::move(matchers)) {}

        template<typename Matcher>
        constexpr auto add_matcher(Matcher&& matcher) {
            return state_machine_builder<State, Matchers..., Matcher>(std::tuple_cat(m_matchers, std::tuple<Matcher>(std::forward<Matcher>(matcher))));
        }

        constexpr auto build() {
            return state_machine<State, Matchers...>(build_matchers(std::make_index_sequence<sizeof...(Matchers)>{}));
        }

    private:
        template<size_t ... Indices>
        constexpr auto build_matchers(std::index_sequence<Indices...>) {
            return detail::overloaded { std::get<Indices>(m_matchers)... };
        }

        std::tuple<Matchers...> m_matchers;
    };
}