#include <array>
#include <concepts>
#include <cstdint>
#include <vector>

#include "random.hpp"
#include "grid.hpp"

namespace tfa {
    template <std::integral auto size>
    bool grid<size>::populate() {
        const std::vector<cordinate> empty_cordinates = this -> empty_cordinates();

        if (empty_cordinates.empty()) {
            return false;
        }

        const cordinate chosen_cordinate = empty_cordinates.at(randrange<std::size_t>(0, empty_cordinates.size() - 1));
        const bool is_four = randrange<std::size_t>(0, 9) == 0;

        this -> at(chosen_cordinate) = is_four ? 4 : 2;
    }
}
