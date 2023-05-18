#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct band {
    string name;
    string genre;
    int num_members;
    int ranking;


    band(string name_, string genre_, int num_members_, int ranking_) {
        name = name_;
        genre = genre_;
        num_members = num_members_;
        ranking = ranking_;
    }
};

band createBand(string name, string genre, int num_members, int ranking) {
    return band(name, genre, num_members, ranking );
};

int main() {
    band redHot = createBand("Red hot chilli peppers", "rock", 4, 1);
    cout << redHot.name << endl;
    cout << redHot.genre << endl;
    cout << redHot.num_members << endl;
    cout << redHot.ranking << endl;
    return 0;
}
