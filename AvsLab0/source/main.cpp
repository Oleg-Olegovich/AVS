#include "encoded_string.h"
#include "input_functions.h"
#include "sort.h"

void solve() {
    std::cerr << "Input amount of strings need to be encoded: ";
    uint32_t n;
    std::cin >> n;
    EncodedString** ess = new EncodedString*[n];
    for (uint32_t i = 0; i < n; ++i) {
        ess[i] = create_es();
    }
    try {
        for (uint32_t i = 0; i < n; ++i) {
            read_str(ess[i]->str);
            read_encoding(ess[i]);
            encode(ess[i]);
        }
        std::cerr << '\n';
        sort_array_of_encoded_strings_desc(ess, static_cast<int32_t>(n));
        for (uint32_t i = 0; i < n; ++i) {
            std::cerr << "Key: " << common_func(ess[i]) << ' ';
            print_encoded(ess[i]);
        }
    } catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
    for (uint32_t i = 0; i < n; ++i) {
        clear_es(ess[i]);
        delete ess[i];
    }
    delete[] ess;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
