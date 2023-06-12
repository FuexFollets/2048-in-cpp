#include <array>
#include <concepts>
#include <cstdint>
#include <vector>

#include "cordinate.hpp"
#include "random.hpp"

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

            bool populate() {
                const std::vector<cordinate> empty_cordinates = this -> empty_cordinates();

                if (empty_cordinates.empty()) {
                    return false;
                }

                const cordinate chosen_cordinate = empty_cordinates.at(randrange<std::size_t>(0, empty_cordinates.size() - 1));
                const bool is_four = randrange<std::size_t>(0, 9) == 0;

                return this -> populate(chosen_cordinate, is_four);
            }

            bool populate(const cordinate& cordinate, bool is_four) {
                if (this -> at(cordinate) != 0) {
                    return false;
                }

                this -> at(cordinate) = is_four ? 4 : 2;

                return true;
            }

            void make_move(Direction direction);

            std::uint64_t& at(std::size_t x_pos, std::size_t y_pos) {
                return this -> _grid.at(x_pos).at(y_pos);
            }

            std::uint64_t& at(const cordinate& cordinate) {
                return this -> at(cordinate.x_pos, cordinate.y_pos);
            }

            [[nodiscard]] bool is_over() const;
            [[nodiscard]] std::uint64_t score() const;
            [[nodiscard]] std::array<std::array<std::uint64_t, size>, size> grid_array() const;

            [[nodiscard]] std::vector<cordinate> empty_cordinates() const;
    };
}
