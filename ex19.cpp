#include <iostream>
using namespace std;

class Score {
    private:
        int homeTeam;
        int opponent;
    public:
        Score() : homeTeam(0), opponent(0) {};
        Score(int ht, int o);
        Score(const Score& s);
        ~Score() {};
        int getHomeTeam() const {return homeTeam;}
        int getOpponent() const {return opponent;}
        void setHomeTeam(int ht) {homeTeam = ht;}
        void setOpponent(int o) {opponent = o;}
        friend ostream& operator <<(ostream& outs, const Score& s);
};

Score::Score(int ht, int o) {
    homeTeam = ht;
    opponent = o;
}

Score::Score(const Score& s) {
    homeTeam = s.homeTeam;
    opponent = s.opponent;
}

ostream& operator <<(ostream& outs, const Score& s) {
    outs << "Home Team: " << s.homeTeam << " - Opponent: " << s.opponent;
    return outs;
}

int main() {
    Score gameArray [10];
    for(int i = 0; i < 10; i ++) {
        int ans;
        cout << "Enter Game #" << i + 1 << ":" << endl
             << "Hometeam: ";
        cin >> ans;
        gameArray[i].setHomeTeam(ans);
        cout << "Opponent: ";
        cin >> ans;
        gameArray[i].setOpponent(ans);
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << "Score #" << i + 1 << ": " << gameArray[i] << endl; 
    }
    return 0;
}