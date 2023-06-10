#include "random.hpp"

namespace tfa {
    template <std::integral T>
    T randrange(T min, T max) {
        static std::random_device device;
        static std::mt19937 generator(device());
        std::uniform_int_distribution<T> distribution(min, max);

        return distribution(generator);
    }
}
