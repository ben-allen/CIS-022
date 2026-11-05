#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

class Height {
public:
    Height(int feet, int inches) {
        this->feet = feet;
        this->inches = inches;
    }
    int getFeet() const {
        return feet;
    }
    int getInches() const {
        return inches;
    }
    void print() const {
        cout << feet << "'" << inches << "\"";
    }

private:
    int feet;
    int inches;
};

int main() {
    Height finn(5, 4);
    finn.print();
    cout << endl;
}
