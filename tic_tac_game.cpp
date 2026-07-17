#include <bits/stdc++.h>
using namespace std;
int row,col;
bool draw=false;

char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';

void display(){//game er body build korlam
    system("cls");
    cout<<"\t   T i c k  C r o s s   G a m e "<<endl;
    cout<<"\t   ____________________________"<<endl<<endl;
    cout<<"\ti.Player1[X]"<<endl<<"\tii.Player2[O]"<<endl<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<arr[0][0]<<"  |  "<<arr[0][1]<<"  |  "<<arr[0][2]<<"  "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<arr[1][0]<<"  |  "<<arr[1][1]<<"  |  "<<arr[1][2]<<"  "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<arr[2][0]<<"  |  "<<arr[2][1]<<"  |  "<<arr[2][2]<<"  "<<endl;
    cout<<"\t\t     |     |     "<<endl;
}

void player_turn(){
    if(turn=='X') //initially turn X er kacei ace, cout kaj krbe tkn
        cout<<endl<<"Player1 [X] turn (press number between 1-9):";

    if(turn=='O')
        cout<<endl<<"Player2 [O] turn (press number between 1-9):";
    
    int choice; //1-9
    cin>>choice;

    switch(choice){//swith case theke 1-9 er modde je number choose kora hobe oi case er row & col nmbr peye jabo
        case 1:
            row=0;col=0;
            break;
        case 2:
            row=0;col=1;
            break;
        case 3:
            row=0;col=2;
            break;
        case 4:
            row=1;col=0;
            break;
        case 5:
            row=1;col=1;
            break;
        case 6:
            row=1;col=2;
            break;
        case 7:
            row=2;col=0;
            break;
        case 8:
            row=2;col=1;
            break;
        case 9:
            row=2;col=2;
            break;
        
        default:
            cout<<"Invalid input";
            break;
    }
    if(turn=='X' && arr[row][col]!='X' && arr[row][col]!='O'){//then row & col number paway space kali takle bosai dite parbo
        arr[row][col]='X';
        turn='O';
    }
    else if(turn=='O' && arr[row][col]!='X' && arr[row][col]!='O'){
        arr[row][col]='O';
        turn='X';
    }
    else{
        cout<<"BOX is already fillen!"<<endl<<"Please try again!!"<<endl;
        player_turn();
    }
    display();
}
bool gameover(){
    for(int i=0;i<3;i++){//row or col borabor game hoyece kina check korbe
        if(arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2] ||arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i])
            return false;// hole false return hobe and while loop theme jabe main fun er. and game ke jitce print hobe
    }
    if(arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2] || arr[0][2]==arr[1][1] && arr[0][2]==arr[2][0]){//2 diagonal borabor game hoyece kina dekbe
        return false;//hole same, loop stop hobe, game ke jitce show hobe
    }
    for(int i=0;i<3;i++){//eta,game na hole bujte hobe je ekn o knu number(ghor) kali ace
        for(int j=0;j<3;j++){
            if(arr[i][j]!='X' && arr[i][j]!='O'){
                return true;//true return hobe,while loop abr colbe
            }
        }
    }
    //upor er 3 case er knu tai jdi na hoy taile ektai option i hobe je game draw hoice
    draw=true;
    return false;//while loop theme jabe, and draw hoyece game print hobe
}

int main(){

    while(gameover()){
    display();
    player_turn();
    gameover();
    }
    if(turn=='X' && draw==false)// 'O' game dile turn sate sat 'X' kace cole jay,tai turn=x hole player 2 er game 
        cout<<endl<<"->Player2 [O] wins!Congratulation!"<<endl<<endl;
    else if(turn=='O' && draw==false)
        cout<<endl<<"->Player1 [X] wins!Congratulation!"<<endl<<endl;
    else
        cout<<endl<<"->Game Draw"<<endl<<endl;
}   