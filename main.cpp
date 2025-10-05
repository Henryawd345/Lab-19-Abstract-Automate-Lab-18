#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node{
    float rating;
    string comment;
    Node *next;
};

class Movie{
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

    void loadReview(ifstream &in, int howMany){
        string line;
        int counter = 0;

        while(counter < howMany && getline(in,line)){
            if (line.empty()) continue;
            addReview(randomRating(),line);
            counter++;
        }
    }

    void print() {
        cout<< "Movie: " << movieTitle << "\n";

        Node* curr = head;
        float sum = 0.0;
        int count = 0;
        int i = 1;

    while (curr)
        {
            cout<<"  > Review #" << i++ <<"  Rating:  " << curr->rating <<"  Comment:  " <<curr->comment <<"\n";
            sum += curr->rating;
            count++;
            curr = curr->next;
        }
        if (count) cout << "  > Average: " << (sum / count) << "\n";
    }

    void clear() {
        while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
        }
    }
};

int main(){

    ifstream fin("Movies.txt");
    if (!fin) {
        cerr << "Error: could not open comments.txt\n";
        return 1;
    }

    vector<Movie> movies(4);
    movies[0].setTitle("Inception");
    movies[1].setTitle("Interstellar");
    movies[2].setTitle("Spirited Away");
    movies[3].setTitle("The Dark Knight");

    int reviewPerMovie = 3;
    for (auto &m : movies) {
        m.loadReview(fin, reviewPerMovie);
    }
    
    cout << "=== Movie Reviews ===\n\n";
    for (auto &m : movies) {
        m.print();
    }

    return 0;
}
