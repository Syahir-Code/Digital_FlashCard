#include <iostream>  
#include <string>    
#include <vector>    

using namespace std;

enum Difficulty { HARD = 0, MEDIUM = 1, EASY = 2 };

void print(string str) {
    cout << str << endl;
}

class FlashCard {
private:
    string question;
    string answer;
    Difficulty difficulty;


public:
    FlashCard() { difficulty = MEDIUM; }  

    void setQuestion() {
        cout << "Add a question: ";
        getline(cin, question);
    }

    void setAnswer() {
        cout << "Add the answer: ";
        getline(cin, answer);
    }

    void loadCardDetails(string q, string a, Difficulty d) {
        question = q;
        answer = a;
        difficulty = d;
    }

    string getQuestion()       { return question; }
    string getAnswer()         { return answer; }
    Difficulty getDifficulty() const { return difficulty; }

    void setDifficulty(Difficulty d) { difficulty = d; }

    string getDifficultyLabel() {
        if (difficulty == HARD)   return "Hard";
        if (difficulty == MEDIUM) return "Medium";
        return "Easy";
    }
};

class Deck {
private:
    vector<FlashCard> cards; 

public:
    void addNewCard() {
        FlashCard newCard;
        newCard.setQuestion();
        newCard.setAnswer();
        cards.push_back(newCard);
        print("Card added successfully!");
    }

    vector<FlashCard>& getCards() {
        return cards;
    }

    void clearDeck() {
        cards.clear();
    }

};


int main() {
    Deck myDeck;

    int choice = 0;

    do {
        cout << endl;
        print("---------------------------------");
        print("      FLASHCARD CONSOLE          ");
        print("---------------------------------");
        print("1. Add FlashCard");
        print("2. Remove FlashCard");
        print("3. Review Flashcards");
        print("4. View Progress");
        print("5. Exit");
        cout << endl;

        cout << "Enter your choice (number): ";
        cin >> choice;
        cin.ignore(); 
        cout << endl;

        if (choice == 1) {
            print ("----------");
        }

        else if (choice == 2) {
            print ("----------");
        }

        else if (choice == 3) {
            print ("----------");
        }

        else if (choice == 4) {
            print ("----------");
        }

        else if (choice == 5) {
            print("Goodbye!");
            return 0;
        }

        else {
            print("Invalid choice. Please select 1-5.");
        }
    
    } while (true);

    return 0;
}