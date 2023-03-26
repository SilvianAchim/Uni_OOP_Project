#include <iostream>
#include <vector>

class Haina {
    std::string culoare = "gri";
    int pret=100;
public:
    Haina(const std::string &culoare, int pret) : culoare(culoare), pret(pret) {}
    Haina(const Haina& other) : culoare(other.culoare), pret(other.pret) {
        std::cout << "cc haina\n";
    }
    Haina& operator=(const Haina& other) {
        culoare = other.culoare;
        pret = other.pret;
        std::cout << "op= haina\n";
        return *this;
    }
    ~Haina() { std::cout << "destr haina\n"; }

    friend std::ostream &operator<<(std::ostream &os, const Haina &haina) {
        os << "culoare: " << haina.culoare << " pret: " << haina.pret << "\n";
        return os;
    }
};

class Cuier {
//    int nr_haine_max;
//    Haina h{"a", 1};
    std::string material;
    std::vector<Haina> haine;
public:
    Cuier(const std::string &material, const std::vector<Haina> &haine) : material(material), haine(haine) {}
//    Cuier(const std::string &material, const std::vector<Haina> &haine) : material(material), haine(haine) {}
    friend std::ostream &operator<<(std::ostream &os, const Cuier &cuier) {
        os << "material: " << cuier.material << " haine:\n";
        for(const auto& haina : cuier.haine)
            os << "\t" << haina;
        return os;
    }
};


int main() {
    Haina h1{"a", 1};
    Cuier c1{"test", {h1}};
    std::vector<Cuier> vec;
    vec.push_back(c1);
    std::string culoare;
    std::cin >> culoare;
    std::cout << "am citit " << culoare << "\n";
    return 0;
}
