#include <iostream>  
#include <string>     

using namespace std;

void print(string str) {
    cout << str << endl;
}

class FlashCard {
private:
    string question;
    string answer;

public:
    FlashCard() { }  

    void setQuestion() {
        cout << "Add a question: ";
        getline(cin, question);
    }

    void setAnswer() {
        cout << "Add the answer: ";
        getline(cin, answer);
    }

    string getQuestion()  { return question; }
    string getAnswer()  { return answer; }
};


int main() {
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