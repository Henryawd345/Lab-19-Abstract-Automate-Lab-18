#include <iostream>
#include <fstream>
#include <vector>
#include <array>

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

    float randomRatingOneDecimal() {
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



    }

 
    
};

int main(){

    return 0;
}
