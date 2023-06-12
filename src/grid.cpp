#include <array>
#include <concepts>
#include <cstdint>
#include <vector>

#include "random.hpp"
#include "grid.hpp"

namespace tfa {
    template <std::integral auto size>
    std::uint64_t& grid<size>::at(std::size_t x_pos, std::size_t y_pos) {
        return this -> _grid.at(x_pos).at(y_pos);
    }

    template <std::integral auto size>
    std::uint64_t& grid<size>::at(const cordinate& cordinate) {
        return this -> at(cordinate.x_pos, cordinate.y_pos);
    }

    template <std::integral auto size>
    bool grid<size>::populate() {
        const std::vector<cordinate> empty_cordinates = this -> empty_cordinates();

        if (empty_cordinates.empty()) {
            return false;
        }

        const cordinate chosen_cordinate = empty_cordinates.at(randrange<std::size_t>(0, empty_cordinates.size() - 1));
        const bool is_four = randrange<std::size_t>(0, 9) == 0;

        return this -> populate(chosen_cordinate, is_four);
    }
}
