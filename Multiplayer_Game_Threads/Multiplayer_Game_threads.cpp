#include <iostream>
#include <pthread.h>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <alsa/asoundlib.h>
using namespace std;
// Axis of the players
int player_1_axis[] = {0, 0, 1};
int player_2_axis[] = {0, 1, 2};
int player_3_axis[]=  {0, 2, 3};
// Score of the players
int player_1_score=0;
int player_2_score=0;
int player_3_score=0;


//
int n=0;
// Number of the Players
int numPlayers=0;
// Name of the Players
string player_names[3];

// String Colors
const std::string RED = "\033[0;31m";
const std::string GREEN = "\033[0;32m";
const std::string YELLOW = "\033[0;33m";
const std::string BLUE = "\033[0;34m";
const std::string MAGENTA = "\033[0;35m";
const std::string CYAN = "\033[0;36m";
const std::string RESET = "\033[0m";


// BackGround Color
const std::string BG_RED = "\033[41m";
const std::string BG_GREEN = "\033[42m";
const std::string BG_YELLOW = "\033[43m";
const std::string BG_BLUE = "\033[44m";
const std::string BG_MAGENTA = "\033[45m";
const std::string BG_CYAN = "\033[46m";
const std::string BG_WHITE = "\033[47m";
//const std::string RESET = "\033[0m";




// A function for the key pressed because we don't want to press enter everytime.
void set_terminal(bool enable) {
    static struct termios oldt, newt;

    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

// Menu Function at the start of ther function

void displayMenu() {
     cout << "\033[2J\033[1;1H"; // Clear the screen

    cout << "\033[48;2;233;196;106m"; // Set background color to golden yellow
    cout << "\033[38;2;26;25;29m"; // Set text color to black
    cout << "---------------------------------------------------" << endl;
    cout << "|                                                 |" << endl;
    cout << "|    WELCOME TO THE OS GAME BASED ON THREADS      |" << endl;
    cout << "|                                                 |" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "\033[0m"; // Reset text color


    cout << "\n\033[46mHow many players are there? (MAX 3 CAN ENTER) \033[46m";
    cin >> numPlayers;
    if(numPlayers >3){
         cout << "\n\033[46mHow many players are there? (MAX 3 CAN ENTER) \033[46m";
         cin >> numPlayers;
    }

    for (int i = 0; i < numPlayers; i++) {
        cout << "\n\033[46mEnter the name of player " << i + 1 << ": \033[46m";
        cin >> player_names[i];
    }

}



// Gameboard function maintain the movement of the players
void* gameboard(void* arg) {
    int* arr = (int*)arg;
    set_terminal(true);
    int value = getchar();

    if (arr[2] == 1) {
        if (value == int('w')) {//Up
            arr[0] = arr[0] - 1;
            if(arr[0] <0){
                arr[0]++;
            }else if(arr[0]>n){
                arr[0]--;
            }
        } else if (value == int('s')) { // Down
            arr[0] = arr[0] + 1;
            if(arr[0] <0){
                arr[0]++;
            }else if(arr[0]>n){
                arr[0]--;
            }


        } else if (value == int('a')) { // left
            arr[1] = arr[1] - 1;
            if(arr[0] <0){
                arr[0]++;
            }else if(arr[0]>n){
                arr[0]--;
            }
        } else if (value == int('d')) {  // right
            arr[1] = arr[1] + 1;
            if(arr[0] <0){
                arr[0]++;
            }else if(arr[0]>n){
                arr[0]--;
            }
        }
    } else if (arr[2] == 2) {
        if (value == int('i')) {// UP
            arr[0] = arr[0] - 1;
        } else if (value == int('k')) {//down
            arr[0] = arr[0] + 1;
        } else if (value == int('j')) {//left
            arr[1] = arr[1] - 1;
        } else if (value == int('l')) {//right
            arr[1] = arr[1] + 1;
        }
    }
    else if(arr[2]==3){
        if (value == int('t')) {//UP
        cout<<value<<endl;
            arr[0] = arr[0] - 1;
        } else if (value == int('g')) { //down
            arr[0] = arr[0] + 1;
            cout<<value<<endl;
        } else if (value == int('f')) {//left
            arr[1] = arr[1] - 1;
            cout<<value<<endl;
        } else if (value == int('h')) {//right
            arr[1] = arr[1] + 1;
            cout<<value<<endl;
        }
        // the arrow value
    }
    return (void*)arr;
}


// For the N number of the array
int number(){
       srand(time(NULL)); // Initialize random seed based on system time
    int num = rand() % 90 + 10; // Generate a random number between 10 and 99
    num *= 5; // Multiply the generated number by 5
    int result = 2535 / num; // Divide 2535 with the generated number
    int mod_result = result % 25; // Get the mod of the result with 25
    if (mod_result < 10) {
        mod_result += 15; // If the mod is less than 10, add 15 to it
    }
    return mod_result;
}




void play_music(const std::string& filepath) {
    // Construct the command to play the music file using mpv
    std::string command = "mpv " + filepath + " &";

    // Execute the command using system()
    int status = system(command.c_str());

    // Check if the command was executed successfully
    if (status != 0) {
        std::cerr << "Error: Failed to play music file " << filepath << std::endl;
    }
}



int main() {

 //play_music("death_note.mp3");


displayMenu();
  std::cout << RED << "To Start the Game for Player 1 ( X ) the keys are " << RESET << std::endl;
  std::cout << RED << "     w for Up" << RESET << std::endl;
  std::cout << RED << "     s for Down " << RESET << std::endl;
  std::cout << RED << "     a for left " << RESET << std::endl;
  std::cout << RED << "     d for right" << RESET << std::endl;
  sleep(4);
  system("clear");
  std::cout << GREEN << "To Start the Game for Player 2 ( O ) the keys are " << RESET << std::endl;
  std::cout << GREEN << "       t for Up" << RESET << std::endl;
  std::cout << GREEN << "       g for Down " << RESET << std::endl;
  std::cout << GREEN << "       f for left " << RESET << std::endl;
  std::cout << GREEN << "       h for right" << RESET << std::endl;
  sleep(4);
  system("clear");
  std::cout << CYAN << "To Start the Game for Player 3 ( # ) the keys are " << RESET << std::endl;
  std::cout << CYAN << "        i for Up" << RESET << std::endl;
  std::cout << CYAN << "        k for Down " << RESET << std::endl;
  std::cout << CYAN << "        j for left " << RESET << std::endl;
  std::cout << CYAN << "        l for right" << RESET << std::endl;
  sleep(4);
  system("clear");

system("echo -en '\\033[46m'");

  // Print a message with the new background color
  cout << "The background color of this terminal has been changed!" << endl;

  // Reset the terminal back to the default background color


    char player_1 = 'X';
    char player_2 = 'O';
    char player_3 = '#';



    pthread_t thr1, thr2, thr3;


     n= number();

    int ** array=new int*[n];
    for(int i=0;i<n;i++){
        array[i]=new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            array[i][j]=0;
        }
    }
    cout<<"The value of the N is "<<n<<endl;

 int count = 0;
    while(count < 10) {
        int i = rand() % n;
        int j = rand() % n;
        if(array[i][j] == 0) {
            array[i][j] = 5;
            count++;
        }
    }

count=0;
bool l_v=true;
    while (l_v) {

        if(numPlayers == 2){
        pthread_create(&thr1, nullptr, gameboard, (void*)player_1_axis);
        pthread_create(&thr2, nullptr, gameboard, (void*)player_2_axis);
        pthread_join(thr1, nullptr);
        pthread_join(thr2, nullptr);
        }
        else if(numPlayers == 3){
        pthread_create(&thr1, nullptr, gameboard, (void*)player_1_axis);
        pthread_create(&thr2, nullptr, gameboard, (void*)player_2_axis);
        pthread_create(&thr3, nullptr, gameboard, (void*)player_3_axis);
        pthread_join(thr1, nullptr);
        pthread_join(thr2, nullptr);
        pthread_join(thr3, nullptr);
        }
        system("clear");


        cout<<"Score of the GAME"<<endl<<endl;

    if(numPlayers==2){
      cout<<player_names[0]<<"  Score is ( "<<player_1<<" ) : "<<player_1_score<<"      "<<player_names[1]<<"  Score is ( "<<player_2<<" ) : "<<player_2_score<<endl<<endl;
      }else if(numPlayers==3){
      cout<<player_names[0]<<"  Score is ( "<<player_1<<" ) : "<<player_1_score<<"      "<<player_names[1]<<"  Score is ( "<<player_2<<" ) : "<<player_2_score<<"      "<<player_names[2]<<"  Score is ( "<<player_3<<" ) : "<<player_3_score<<endl<<endl;
    }
    if(numPlayers==2){
       for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((player_1_axis[0] == i && player_1_axis[1] == j) ) {
                    cout <<"_"<< player_1 << "_ ";
                } else if (player_2_axis[0] == i && player_2_axis[1] == j) {
                    cout <<"_"<< player_2 <<"_ ";
                }else if (array[i][j]==5){

                    cout<<"_&_ ";
                }
             else if (array[player_1_axis[0]][player_1_axis[1]] == 5) {
                     array[player_1_axis[0]][player_1_axis[1]] = 0;
                     count++;
                     player_1_score++;
                     }
             else if (array[player_2_axis[0]][player_2_axis[1]] == 5) {
                     array[player_2_axis[0]][player_2_axis[1]] = 0;
                     count++;
                     player_2_score++;
                     }
                     else if(count == 1){
                         l_v=false;
                         break;
                     }
            else {
                    cout<<"___ ";
                }
            }
         cout<<endl;
        }
}
else if(numPlayers==3){

  for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (player_1_axis[0] == i && player_1_axis[1] == j) {
                    cout <<"_"<< player_1 << "_ ";
                } else if (player_2_axis[0] == i && player_2_axis[1] == j) {
                    cout <<"_"<< player_2 <<"_ ";
                }else if (player_3_axis[0] == i && player_3_axis[1] == j) {
                    cout <<"_"<< player_3 <<"_ ";
                }else if (array[i][j]==5){

                    cout<<"_&_ ";
                }
             else if (array[player_1_axis[0]][player_1_axis[1]] == 5) {
                     array[player_1_axis[0]][player_1_axis[1]] = 0;
                     player_1_score++;
                     count++;
                     }
             else if (array[player_2_axis[0]][player_2_axis[1]] == 5) {
                     array[player_2_axis[0]][player_2_axis[1]] = 0;
                     player_2_score++;
                     count++;
                     }
            else if (array[player_3_axis[0]][player_3_axis[1]] == 5) {
                     array[player_3_axis[0]][player_3_axis[1]] = 0;
                     count++;
                     player_3_score++;
                     }
                     else if(count == 2){
                         l_v=false;
                         break;
                     }
            else {
                    cout<<"___ ";
                }
            }
         cout<<endl;
        }
    }
}

 system("echo -en '\\e[0m'");

 system("clear");
 system("echo -en '\\033[42m'");


if(numPlayers==2){
   if(player_1_score > player_2_score){
       cout << "-----------------------------------------------------------------------------------" << endl;
       cout << "|                                                                                  |" << endl;
       cout<<"    "<<player_names[0]<<"  Score is ( "<<player_1<<" ) : "<<player_1_score<<"   Wins                                      "<<endl;
       cout << "|                                                                                  |" << endl;
       cout << "-----------------------------------------------------------------------------------" << endl;
   }else{
       cout << "-----------------------------------------------------------------------------------" << endl;
       cout << "|                                                                                  |" << endl;
        cout<<"    "<<player_names[1]<<"  Score is ( "<<player_2<<" ) : "<<player_2_score<<"   Wins                                     "<<endl;
       cout << "|                                                                                  |" << endl;
       cout << "-----------------------------------------------------------------------------------" << endl;
   }

}
else if(numPlayers==3){
if(player_1_score > player_2_score && player_1_score > player_3_score){
       cout << "----------------------------------------------------------------------------------" << endl;
       cout << "|                                                                                 |" << endl;
       cout<<"    "<<player_names[0]<<"  Score is ( "<<player_1<<" ) : "<<player_1_score<<"   Wins                                      "<<endl;
       cout << "|                                                                                 |" << endl;
       cout << "----------------------------------------------------------------------------------" << endl;
   }else if(player_2_score > player_1_score && player_2_score > player_3_score)
   {
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "|                                                                                 |" << endl;
        cout<<"    "<<player_names[1]<<"  Score is ( "<<player_2<<" ) : "<<player_2_score<<"   Wins                                      "<<endl;
        cout << "|                                                                                 |" << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
   }
else {
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "|                                                                                  |" << endl;
    cout<<"    "<<player_names[2]<<"  Score is ( "<<player_3<<" ) : "<<player_3_score<<"   Wins                                      "<<endl;
    cout << "|                                                                                  |" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}


}
 system("echo -en '\\e[0m'");
    return 0;
}

