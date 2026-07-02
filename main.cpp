#include <iostream>  // Default library to run c++ program
#include <string>    // String functionality
#include <vector>    // Vector function (dynamic memory allocation)
#include <algorithm> // Added for std::sort

using namespace std;

// Define difficulty level (for progress report)
enum Difficulty { HARD = 0, MEDIUM = 1, EASY = 2 };

// Custom function (shortcut) to print with newline
void print(string str) {
    cout << str << endl;
}


// Stores information of each flashcard
// Question, answer, difficulty level
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


// Acts as a deck for collection of flashcards
// To store multiple flashcards
// Add and remove flashcard functions obtained from here
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

    void removeCard() {
        if (cards.empty()) {
            print("The deck is empty! Nothing to remove.");
            return;
        }

        cout << "--- Select a Card to Remove ---" << endl;
        for (size_t i = 0; i < cards.size(); i++) {
            cout << i + 1 << ". " << cards[i].getQuestion() << endl;
        }

        int pick = 0;
        cout << "Enter card number to remove: ";
        cin >> pick;
        cin.ignore();

        if (pick < 1 || pick > (int)cards.size()) {
            print("Invalid selection. No card removed.");
            return;
        }

        cards.erase(cards.begin() + pick - 1);
        print("Card removed successfully!");
    }

    void sortByDifficulty() {
        sort(cards.begin(), cards.end(), [](const FlashCard& a, const FlashCard& b) {
            return a.getDifficulty() < b.getDifficulty(); // HARD(0) < MEDIUM(1) < EASY(2)
        });
    }
};


// To review flashcards in the deck
// Prompts question, reveals answer
// Asks and update difficulty level experienced for each card
class StudySession {
private:
    FlashCard *card;  

public:
    StudySession(FlashCard *c) { card = c; }

    void showCard() {
        cout << "Question: " << card->getQuestion() << endl;
        cout << endl;
        cout << "Press ENTER to reveal answer...";
        cin.ignore();
        cout << "Answer: " << card->getAnswer() << endl;
        cout << endl;
    }

    void recordFeedback() {
        int feedback = 0;
        cout << "How difficult was this card?" << endl;
        cout << "1. Hard   (will appear first next time)"  << endl;
        cout << "2. Medium (will appear in the middle)"    << endl;
        cout << "3. Easy   (will appear last next time)"   << endl;
        cout << "Enter choice: ";
        cin >> feedback;
        cin.ignore(); 

        if (feedback == 1) {
            card->setDifficulty(HARD);
            cout << "Marked as Hard. This card will appear first." << endl;
        } else if (feedback == 2) {
            card->setDifficulty(MEDIUM);
            cout << "Marked as Medium. This card will appear in the middle." << endl;
        } else if (feedback == 3) {
            card->setDifficulty(EASY);
            cout << "Marked as Easy. This card will appear last." << endl;
        } else {
            cout << "Invalid input. Difficulty unchanged." << endl;
        }
    }

    void startSession(int current, int total) {
        cout << endl;
        cout << "---------------------------------" << endl;
        cout << "   REVIEW SESSION  [" << current << "/" << total << "]" << endl;
        cout << "---------------------------------" << endl;

        showCard();
        recordFeedback();
    }
};

// Track and displays user progress
class UserProgress {
private:
    FlashCard *card;  

public:
    UserProgress(FlashCard *c) { card = c; }

    void progress() {
        cout << "User Progress:" << endl;
        cout << "Question:   " << card->getQuestion() << endl;
        cout << "Difficulty: " << card->getDifficultyLabel() << endl;
        cout << endl;
    }
};


int main() {
    Deck myDeck;
    char choice;

    do {
        // Display menu for flashcard console interface
        cout << endl;
        print("---------------------------------");
        print("      FLASHCARD CONSOLE          ");
        print("---------------------------------");
        print("1. Add FlashCard");
        print("2. Review Flashcards");
        print("3. Remove FlashCard");
        print("4. View Progress");
        print("5. Exit");
        cout << endl;

        // Read user's menu selection
        cout << "Enter your choice (number): ";
        cin >> choice;
        cin.ignore(); 
        cout << endl;

        // Adds new flashcard to the deck
        if (choice == '1') {
            cout << "--- Creating a Card ---" << endl;
            myDeck.addNewCard();
        }

        // To enter study session / review session
        // Iterates through every existing flashcards
        else if (choice == '2') {
            vector<FlashCard>& cards = myDeck.getCards();
            
            if (cards.empty()) {
                print("The deck is empty! Add some cards first.");

            } else {
                myDeck.sortByDifficulty();
            
                for (size_t i = 0; i < cards.size(); i++) {
                    StudySession session(&cards[i]);
                    session.startSession(i + 1, cards.size());
                }
            }
        }

        // Displays all questions corresponding to each card
        // Lets the user choose one
        // Removes it from the vector
        else if (choice == '3') {
            myDeck.removeCard();
        }

        // To view user progress 
        else if (choice == '4') {
            vector<FlashCard>& cards = myDeck.getCards();
            
            if (cards.empty()) {
                print("The deck is empty! No progress to show.");

            } else {
                for (size_t i = 0; i < cards.size(); i++) {
                    UserProgress track(&cards[i]);
                    track.progress();
                }
   
                cout << "Press ENTER to return to the menu...";
                cin.ignore();
            }
        }

        // Prints a message and exit the console
        else if (choice == '5') {
            print("Thank you!!!");
            return 0;
        }

        // Prints a warning if invalid choice is selected
        else {
            print("Invalid choice. Please select 1-5.");
        }
    
    // Keeps the program running until user chooses to exit
    } while (true);

    return 0;
}