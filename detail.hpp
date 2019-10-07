#pragma once

#include <variant>
#include <utility>

namespace st::detail {
    template<typename ... Ts>
    struct overloaded : Ts... {
        using Ts::operator()...;
    };

    template<typename ... Ts>
    overloaded(Ts...) -> overloaded<Ts...>;

    template<typename Variant, typename ... Matchers>
    constexpr auto match(Variant&& variant, Matchers&&... matchers) {
        return std::visit(overloaded { std::forward<Matchers>(matchers)... }, std::forward<Variant>(variant));
    }
}