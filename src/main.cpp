#include "network.hpp"

int main() {
    try {
        NetworkManager nm("localhost", 12345);
        nm.start();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

