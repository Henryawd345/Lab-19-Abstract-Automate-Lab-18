#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node{
    float rating;
    string comment;
    Node *next;
};

class Movie
{
private:
    string movieTitle;
    Node *head = nullptr;

    float randomRating() {
    int x = 10 + (rand() % 40); 
    return x / 10.0f;                  
} 
public:
    string getTitle() {return movieTitle;}
    void setTitle(string t) {movieTitle = t;}

    void addReview(float rating, string comment){
        Node* newNode = new Node;
        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = head;
        head = newNode;
    }

    void loadReview(ifstream in, int howMany){
        string line;
        int counter = 0;

        while(counter < howMany && getline(in,line)){
            if (line.empty()) continue;
            addReview(randomRating(),line);
            counter++;
        }
    }

 
    
};

int main(){

    std::ifstream fin("Movies.txt");
    if (!fin) {
        std::cerr << "Error: could not open comments.txt\n";
        return 1;
    }

    vector<Movie> movies(4);
    movies[0].setTitle("Inception");
    movies[1].setTitle("Interstellar");
    movies[2].setTitle("Spirited Away");
    movies[3].setTitle("The Dark Knight");
    




    return 0;
}
