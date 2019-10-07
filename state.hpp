#pragma once

#include <variant>
#include <optional>

namespace st {
    template<typename ... States>
    struct state {
        using internal_type = std::variant<States...>;
        using return_type = std::optional<internal_type>;
    };

    constexpr static auto no_state = std::nullopt;

    template<typename State>
    using ret = typename State::return_type;
}