#include <array>
#include <concepts>
#include <cstdint>
#include <vector>

#include "cordinate.hpp"

namespace tfa {
    template <std::integral auto size>
    class grid {
        using grid_size_t = std::integral_constant<std::size_t, size>;
        enum Direction { UP, DOWN, LEFT, RIGHT };

        private:
            std::array<std::array<std::uint64_t, size>, size> _grid {};
            std::uint64_t _score {0};
            bool _is_over {false};

        public:
            grid() = default;

            bool populate();
            void make_move(Direction direction);

            std::uint64_t& at(const cordinate& cordinate);

            [[nodiscard]] bool is_over() const;
            [[nodiscard]] std::uint64_t score() const;
            [[nodiscard]] std::array<std::array<std::uint64_t, size>, size> grid_array() const;

            [[nodiscard]] std::vector<cordinate> empty_cordinates() const;
    };
}
