#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string title;
    string director;
    double imdbRating;

public:
    // Constructor with imdbRating as a default argument
    Movie(string t, string d, double rating = 5.0) {
        title = t;
        director = d;
        imdbRating = rating;
    }

    // Function to display movie details
    void display() {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "IMDb Rating: " << imdbRating << endl;
        cout << endl;
    }
};

int main() {
    // Object with all three arguments
    Movie movie1("Inception", "Christopher Nolan", 8.8);

    // Object with only title and director (default rating = 5.0)
    Movie movie2("Interstellar", "Christopher Nolan");

    cout << "Movie 1:" << endl;
    movie1.display();

    cout << "Movie 2:" << endl;
    movie2.display();

    return 0;
}