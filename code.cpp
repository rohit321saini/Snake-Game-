#include <bits/stdc++.h>
#include <conio.h>
#include <unistd.h>
using namespace std;

int side,x,y;
int fruitx,fruity,score,flag;
bool isOver;

void randomize();
void frame(int);
void userinp();
void game();

int main(){
    do{
        cout << "Enter the side of your frame!(not less than 20)\n";
        cin >> side;
    }while(side < 20);
    randomize();
    while(!isOver){
        frame(side);
        userinp();
        game();
    }
    return 0;
}

void randomize(){
    x = side/2;
    y = side/2;
    label1: fruitx = rand()%side;
    if (fruitx == 0 || fruitx == side)
        goto label1;
    label2:
    fruity = rand()%side;
    if (fruity == 0 || fruity == side)
        goto label2;

    score = 0;
}
void frame(int s){
    system("cls");
    for(int i=1;i<=s;i++){
        for(int j=1;j<=s;j++){
            if(i == 1 || i == s || j == 1 || j == s)
                cout << "*";
            else{
                if(i == x && j == y){
                    cout << "-";
                }
                else if(i == fruitx && j == fruity){
                    cout << "x";
                }
                else
                    cout << " ";
            }
        }
        cout << "\n";
    }
    cout << "Your score: " << score << endl;
}
void userinp(){
    if(kbhit()){
        switch (getch()){
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        default:
            isOver = true;
        }
    }
}
void game(){
    sleep(0.899);
    switch (flag){
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    }
     if (x < 0 || x > side || y < 0 || y > side){
        x = side/2;
        y = side/2;
     }
     if (x == fruitx && y == fruity) {
        label3: fruitx = rand()%(side);
        if (fruitx == 0)
            goto label3;

        label4: fruity = rand()%(side);
        if (fruity == 0)
            goto label4;

        score++;
    }
}
