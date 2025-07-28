#include <iostream>
using namespace std;

constexpr int N = 3;
int w, k;

bool FreeCorner(const int Tab[][N]) {
    if (Tab[N-1][N-1] == 0) {
        w = N - 1;
        k = N - 1;
        return true;
    }
    if (Tab[0][0] == 0) {
        w = 0;
        k = 0;
        return true;
    }
    if (Tab[0][N-1] == 0) {
        w = 0;
        k = N - 1;
        return true;
    }
    if (Tab[N-1][0] == 0) {
        w = N - 1;
        k = 0;
        return true;
    }
    return false;
}

bool PlayerTookSlotNextToCornerTakenByComputer(const int Tab[][N]) {
    if (Tab[0][1] == 1) {
        w = N - 1;
        k = 0;
        return true;
    }
    if (Tab[1][0] == 1) {
        w = 0;
        k = N - 1;
        return true;
    }
    return false;
}

bool PlayerTookCornerInTheSameLine(const int Tab[][N]) {
    if (Tab[0][N -1 ] == 1) {
        w = N - 1;
        k = 0;
        return true;
    }
    if (Tab[N - 1][0] == 1) {
        w = 0;
        k = N - 1;
        return true;
    }
    return false;
}

bool PlayerTookMiddleAwayFromComputer(const int Tab[][N]) {
    if (Tab[1][2] == 1) {
        w = 0;
        k = 2;
        return true;
    }
    if (Tab[2][1] == 1) {
        w = 2;
        k = 0;
        return true;
    }
    return false;
}

bool PlayerTookMiddle(const int Tab[][N]) {
    if (Tab[1][1] == 1) {
        return true;
    }
    return false;
}

bool PlayerTookLastCorner(const int Tab[][N]) {
    if (Tab[2][2] == 1 && Tab[0][1] == 0) { // the second condition checks if the position to counter taking the last corner by player is free
        w = 0;
        k = 1;
        return true;
    }
    return false;
}

bool WinnableInOneMove(const int Tab[][N]) {
    short int HowManyO = 0;
    short int HowManyX = 0;

    for (int i = 0; i < N; i++) {
        HowManyO = 0;
        HowManyX = 0;
        for (int j = 0; j < N; j++) {
            if (Tab[i][j] == 1) {
                HowManyX++;
            }
            if (Tab[i][j] == 2) {
                HowManyO++;
            }
        }
        if (HowManyO == 2 && HowManyX == 0) {
            for (int n = 0; n < N; n++) {
                if (Tab[i][n] == 0) {
                    k = n;
                    w = i;
                }
            }
            return true;
        }
    }

    for (int i = 0; i < N; i++) {
        HowManyO = 0;
        HowManyX = 0;
        for (int j = 0; j < N; j++) {
            if (Tab[j][i] == 1) {
                HowManyX++;
            }
            if (Tab[j][i] == 2) {
                HowManyO++;
            }
        }
        if (HowManyO == 2 && HowManyX == 0) {
            for (int n = 0; n < N; n++) {
                if (Tab[n][i] == 0) {
                    k = i;
                    w = n;
                }
            }
            return true;
        }
    }
    HowManyO = 0;
    HowManyX = 0;
    for (int i = 0; i < N; i++) {
        if (Tab[i][i] == 2) {
            HowManyO++;
        }
        if (Tab[i][i] == 1) {
            HowManyX++;
        }
    }
    if (HowManyO == 2 && HowManyX == 0) {
        for (int n = 0; n < N; n++) {
            if (Tab[n][n] == 0) {
                w = n;
                k = n;
            }
        }
        return true;
    }

    HowManyO = 0;
    HowManyX = 0;
    int j = N - 1;
    for (int i = 0; i < N; i++) {
        if (Tab[i][j] == 2) {
            HowManyO++;
        }
        if (Tab[i][j] == 1) {
            HowManyX++;
        }
        j--;
    }
    if (HowManyO == 2 && HowManyX == 0) {
        j = N - 1;
        for (int i = 0; i < N; i++) {
            if (Tab[i][j] == 0) {
                w = i;
                k = j;
            }
            j--;
        }
        return true;
    }
    return false;
}

bool LosableInOneMove(const int Tab[][N]) {
    short int HowManyO = 0;
    short int HowManyX = 0;

    for (int i = 0; i < N; i++) {
        HowManyO = 0;
        HowManyX = 0;
        for (int j = 0; j < N; j++) {
            if (Tab[i][j] == 1) {
                HowManyX++;
            }
            if (Tab[i][j] == 2) {
                HowManyO++;
            }
        }
        if (HowManyO == 0 && HowManyX == 2) {
            for (int n = 0; n < N; n++) {
                if (Tab[i][n] == 0) {
                    k = n;
                    w = i;
                }
            }
            return true;
        }
    }

    for (int i = 0; i < N; i++) {
        HowManyO = 0;
        HowManyX = 0;
        for (int j = 0; j < N; j++) {
            if (Tab[j][i] == 1) {
                HowManyX++;
            }
            if (Tab[j][i] == 2) {
                HowManyO++;
            }
        }
        if (HowManyO == 0 && HowManyX == 2) {
            for (int n = 0; n < N; n++) {
                if (Tab[n][i] == 0) {
                    k = i;
                    w = n;
                }
            }
            return true;
        }
    }

    HowManyO = 0;
    HowManyX = 0;
    for (int i = 0; i < N; i++) {
        if (Tab[i][i] == 2) {
            HowManyO++;
        }
        if (Tab[i][i] == 1) {
            HowManyX++;
        }
    }
    if (HowManyO == 0 && HowManyX == 2) {
        for (int n = 0; n < N; n++) {
            if (Tab[n][n] == 0) {
                w = n;
                k = n;
            }
        }
        return true;
    }

    HowManyO = 0;
    HowManyX = 0;
    int j = N - 1;
    for (int i = 0; i < N; i++) {
        if (Tab[i][j] == 2) {
            HowManyO++;
        }
        if (Tab[i][j] == 1) {
            HowManyX++;
        }
        j--;
    }
    if (HowManyO == 0 && HowManyX == 2) {
        j = N - 1;
        for (int i = 0; i < N; i++) {
            if (Tab[i][j] == 0) {
                w = i;
                k = j;
            }
            j--;
        }
        return true;
    }
    return false;
}

bool CornerTakenByPlayer(const int Tab[][N]) {
    if (Tab[0][0] == 1) {
        return true;
    }
    if (Tab[0][N-1] == 1) {
        return true;
    }
    if (Tab[N-1][0] == 1) {
        return true;
    }
    if (Tab[N-1][N-1] == 1) {
        return true;
    }
    return false;
}

bool ComputerWon(const int Tab[][N]) {
    short int HowManyO = 0;
    short int HowManyX = 0;

    for (int i = 0; i < N; i++) {
        HowManyO = 0;
        HowManyX = 0;
        for (int j = 0; j < N; j++) {
            if (Tab[i][j] == 1) {
                HowManyX++;
            }
            if (Tab[i][j] == 2) {
                HowManyO++;
            }
        }
        if (HowManyO == 3 && HowManyX == 0) {
            return true;
        }
    }

    for (int i = 0; i < N; i++) {
        HowManyO = 0;
        HowManyX = 0;
        for (int j = 0; j < N; j++) {
            if (Tab[j][i] == 1) {
                HowManyX++;
            }
            if (Tab[j][i] == 2) {
                HowManyO++;
            }
        }
        if (HowManyO == 3 && HowManyX == 0) {
            return true;
        }
    }
    HowManyO = 0;
    HowManyX = 0;
    for (int i = 0; i < N; i++) {
        if (Tab[i][i] == 2) {
            HowManyO++;
        }
        if (Tab[i][i] == 1) {
            HowManyX++;
        }
    }
    if (HowManyO == 3 && HowManyX == 0) {
        return true;
    }

    HowManyO = 0;
    HowManyX = 0;
    int j = N - 1;
    for (int i = 0; i < N; i++) {
        if (Tab[i][j] == 2) {
            HowManyO++;
        }
        if (Tab[i][j] == 1) {
            HowManyX++;
        }
        j--;
    }
    if (HowManyO == 3 && HowManyX == 0) {
        return true;
    }
    return false;
}

bool PlayerWon(const int Tab[][N]) {
    short int HowManyO = 0;
    short int HowManyX = 0;

    for (int i = 0; i < N; i++) {
        HowManyO = 0;
        HowManyX = 0;
        for (int j = 0; j < N; j++) {
            if (Tab[i][j] == 1) {
                HowManyX++;
            }
            if (Tab[i][j] == 2) {
                HowManyO++;
            }
        }
        if (HowManyO == 0 && HowManyX == 3) {
            return true;
        }
    }

    for (int i = 0; i < N; i++) {
        HowManyO = 0;
        HowManyX = 0;
        for (int j = 0; j < N; j++) {
            if (Tab[j][i] == 1) {
                HowManyX++;
            }
            if (Tab[j][i] == 2) {
                HowManyO++;
            }
        }
        if (HowManyO == 0 && HowManyX == 3) {
            return true;
        }
    }
    HowManyO = 0;
    HowManyX = 0;
    for (int i = 0; i < N; i++) {
        if (Tab[i][i] == 2) {
            HowManyO++;
        }
        if (Tab[i][i] == 1) {
            HowManyX++;
        }
        if (HowManyO == 0 && HowManyX == 3) {
            return true;
        }
    }

    HowManyO = 0;
    HowManyX = 0;
    int j = N - 1;
    for (int i = 0; i < N; i++) {
        if (Tab[i][j] == 2) {
            HowManyO++;
        }
        if (Tab[i][j] == 1) {
            HowManyX++;
        }
        j--;
    }
    if (HowManyO == 0 && HowManyX == 3) {
        return true;
    }
    return false;
}

bool Tie(const int Tab[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Tab[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void PrintTab(const int Tab[][N]) {
    cout << " ";
    for (int i = 0; i < N; i++) {
        cout << " " << i;
    }
    cout <<" i" << endl;
    for (int i = 0; i < N; i++) {
        cout << i << " ";
        for (int j = 0; j < N; j++) {
            if (Tab[i][j] == 0) {
                cout << "~ ";
            }
            else if (Tab[i][j] == 1) {
                cout << "X ";
            }
            else {
                cout << "O ";
            }
        }
        cout << endl;
    }
    cout<< "j";
    cout << endl;
}

void InputPlayerMove(int Tab[][N]) {
    int i, j;
    while (true) {
        cout << "Input where you want to put X [i] [j]: ";
        cin >> i;
        cin >> j;
        cout << endl;
        if (i >= N || j >= N) {
            cout << "There is no such position!\n";
        }
        else if (Tab[i][j] != 0) {
            cout << "This position is already taken!\n";
        }
        else {
            Tab[i][j] = 1;
            break;
        }
    }
}

void MakeMove(int Tab[][N]) {
    Tab[w][k] = 2;
}

void TakeFirstSlot(int Tab[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Tab[i][j] == 0) {
                if ((i == 0 && j == 0) || (i == 0 && j == N - 1) || (i == N - 1 && j == N - 1) || (i == N - 1 && j == 0)) {
                    continue;
                }
                Tab[i][j] = 2;
                return;
            }
        }
    }
}

void TakeCenter(int Tab[][N]) {
    Tab[N/2][N/2] = 2;
}

void TakeFirstCorner(int Tab[][N]) {
    Tab[0][0] = 2;
}

void TakeCornerToCounterMiddle(int Tab[][N]) {
    if (Tab[0][N-1] == 0) {
        Tab[0][N-1] = 2;
    }
    if (Tab[N-1][0] == 0) {
        Tab[N-1][0] = 2;
    }
}

void TakeNextCorner(int Tab[][N]) {
    if (Tab[0][0] == 0) {
        Tab[0][0] = 2;
        return;
    }
    if (Tab[0][N-1] == 0) {
        Tab[0][N-1] = 2;
        return;
    }
    if (Tab[N-1][0] == 0) {
        Tab[N-1][0] = 2;
        return;
    }
    if (Tab[N-1][N-1] == 0) {
        Tab[N-1][N-1] = 2;
        return;
    }
}

void ComputerTurn(int Tab[][N], bool PlayerStarts, bool EarlyGame) {
    if (PlayerStarts) {
        if (WinnableInOneMove(Tab)) {
            MakeMove(Tab);
        }
        else if (LosableInOneMove(Tab)) {
            MakeMove(Tab);
        }
        else if (PlayerTookMiddle(Tab)) {
            TakeNextCorner(Tab);
        }
        else if (PlayerTookLastCorner(Tab) && EarlyGame) {
            MakeMove(Tab);
        }
        else {
            TakeFirstSlot(Tab);
        }
    }
    else {
        if (WinnableInOneMove(Tab)) {
            MakeMove(Tab);
        }
        else if (LosableInOneMove(Tab)) {
            MakeMove(Tab);
        }
        else if (PlayerTookSlotNextToCornerTakenByComputer(Tab) && EarlyGame) {
            MakeMove(Tab);
        }
        else if (PlayerTookCornerInTheSameLine(Tab) && EarlyGame) {
            MakeMove(Tab);
        }
        else if (PlayerTookMiddleAwayFromComputer(Tab) && EarlyGame) {
            MakeMove(Tab);
        }
        else if (FreeCorner(Tab)) {
            if (PlayerTookMiddleAwayFromComputer(Tab)) {
                TakeCornerToCounterMiddle(Tab);
            }
            else {
                MakeMove(Tab);
            }
        }
        else {
            TakeFirstSlot(Tab);
        }
    }
}

void Opening(int Tab[][N], bool PlayerStarts) {
    if (PlayerStarts) {
        InputPlayerMove(Tab);
        if (CornerTakenByPlayer(Tab)) {
            TakeCenter(Tab);
        }
        else {
            TakeFirstCorner(Tab);
        }
    }
    else {
        TakeFirstCorner(Tab);
    }
}

void WelcomePlayer(int Tab[][N]) {
    cout << "---{ Tic Tac Toe }---\nPlayer's indicator is X | Computer's indicator is O\n\n";
    PrintTab(Tab);
    cout << "Do you want to go first? \n[1] yes | [0] no: ";
}

void ClearTab(int Tab[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Tab[i][j] = 0;
        }
    }
}

int main() { // 0 free, 1 - X, 2 - O

    int Tab[N][N]{0};
    bool PlayerStarts, EarlyGame = true;

    while (true) {
        WelcomePlayer(Tab);
        cin >> PlayerStarts;
        cout << endl;
        Opening(Tab, PlayerStarts);
        PrintTab(Tab);
        InputPlayerMove(Tab);

        while (true) {
            ComputerTurn(Tab, PlayerStarts, EarlyGame);
            PrintTab(Tab);

            if (PlayerWon(Tab)) {
                cout << "---{ Player's Won! }---\n";
                break;
            }
            if (ComputerWon(Tab)) {
                cout << "---{ Computer's Won! }---\n";
                break;
            }
            if (Tie(Tab)) {
                cout << "---{ Tie! }---\n";
                break;
            }

            InputPlayerMove(Tab);
            EarlyGame = false;
        }
        bool PlayAgain;
        cout << "Do you want to play again? \n[1] yes | [0] no: ";
        cin >> PlayAgain;
        if (!PlayAgain) {
            return 0;
        }
        EarlyGame = true;
        ClearTab(Tab);
    }
}
