#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int hp, hpPlayer, hpOpp, attackPlayer, attackOpp, wizardHeal, warriorDef, action, round, roundGame, themePlayer, themeOpp, firstPlayer, actionPlayer[50], actionOpp[50];
char summaryDesc[2][50];

void summaryMatch() {
    printf("Player's Turns: \n");
    for(round = 1; round <= roundGame; round++) {
        printf("Round %d: %d\n", round, actionPlayer[round]);
    }
    Sleep(4000);
    system("cls");
    printf("Opponent's Turns: \n");
    for(round = 1; round <= roundGame; round++) {
        printf("Round %d: %d\n", round, actionOpp[round]);
    }
    Sleep(4000);
    getchar();
    getchar();
}

int specialRobotPlayer() {
    attackPlayer = rand() % (15 - 4 + 1 ) + 4;
    hpOpp -= attackPlayer;
    printf("Player attacks opponent with a laser cannon for %d HP.\n", attackPlayer);
    printf("------------------\n");
    printf("Player's HP: %d/%d\n", hpPlayer, hp);
    printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
    return hpPlayer, hpOpp, attackPlayer;
}

int specialRobotOpp() {
    attackOpp = rand() % (15 - 4 + 1 ) + 4;
    hpPlayer -= attackOpp;
    printf("Opponent attacks player with a laser cannon for %d HP.\n", attackPlayer);
    printf("------------------\n");
    printf("Player's HP: %d/%d\n", hpPlayer, hp);
    printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
    return hpPlayer, hpOpp, attackOpp;
}

int specialWizardPlayer() {
    wizardHeal = rand() % (10 - 5 + 1 ) + 5;
    hpPlayer += wizardHeal;
    if (hpPlayer > hp) {
        printf("Player is now at maximum health.\n");
        hpPlayer = hp;
        printf("Player's HP: %d/%d\n", hpPlayer, hp);
        printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
        Sleep(500);
    }
    else{
        printf("Player tends to their wounds, healing themselves by %d.\n", wizardHeal);
        printf("Player's HP: %d/%d\n", hpPlayer, hp);
        printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
        Sleep(500);
    }
    return hpPlayer, hpOpp, wizardHeal;
}

int specialWizardOpp() {
    wizardHeal = rand() % (10 - 5 + 1 ) + 5;
    hpOpp += wizardHeal;
    if (hpPlayer > hp) {
        printf("Opponent is now at maximum health.\n");
        hpPlayer = hp;
        printf("Player's HP: %d/%d\n", hpPlayer, hp);
        printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
        Sleep(500);
    }
    else{
        printf("Opponent tends to their wounds, healing themselves by %d.\n", wizardHeal);
        printf("Player's HP: %d/%d\n", hpPlayer, hp);
        printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
        Sleep(500);;
    }
    return hpPlayer, hpOpp, wizardHeal;
}

int specialWarriorPlayer() {
    warriorDef = rand() % (5 - 3 + 1 ) + 3;
    attackOpp -= warriorDef;
    printf("Player defends from opponent with their shield, reducing their DMG by %d.\n", warriorDef);
    printf("------------------\n");
    Sleep(500);
    return warriorDef, attackOpp;
}

int specialWarriorOpp() {
    warriorDef = rand() % (5 - 3 + 1 ) + 3;
    attackPlayer -= warriorDef;
    printf("Opponent defends from player with their shield, reducing their DMG by %d.\n", warriorDef);
    printf("------------------\n");
    Sleep(500);
    return warriorDef, attackOpp;
}

int playerTurn() {
    printf("Your Turn!\n");
    printf("Choose an action you want to take: \n");
    printf("[1] Attack: \n");
    printf("[2] Defend: \n");
    printf("[3] Heal: \n");
    printf("[4] Special: \n");
    scanf("%d", &action);
    Sleep(1000);
    actionPlayer[round] = action;
    switch (action) {
        case 1:
            attackPlayer = rand() % 5;
            hpOpp -= attackPlayer;
            printf("Player attacks opponent for %d HP.\n", attackPlayer);
            printf("------------------\n");
            printf("Player's HP: %d/%d\n", hpPlayer, hp);
            printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
            Sleep(1000);
            break;

        case 2:
            attackOpp -= 3;
            printf("Player defends their position, reducing opponent's attack by 3.\n");
            Sleep(1000);
            break;

        case 3:
            hpPlayer += 2;
            if (hpPlayer > hp) {
                printf("Player is now at maximum health.\n");
                hpPlayer = hp;
                printf("Player's HP: %d/%d\n", hpPlayer, hp);
                printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
                Sleep(1000);
                break;
                }
            else{
                printf("Player tends to their wounds, healing themselves by 2.\n");
                printf("Player's HP: %d/%d\n", hpPlayer, hp);
                printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
                Sleep(1000);
                break;
            }
        case 4:
            if (themePlayer == 1){
                specialRobotPlayer();
            }
            else if (themePlayer == 2) {
                specialWizardPlayer();
            }
            else if (themePlayer == 3) {
                specialWarriorPlayer();
            }
        Sleep(1000);
        }
    return hpPlayer, hpOpp, attackPlayer, attackOpp;
}

int OppTurn(){
    printf("Opponent's Turn!\n");
    Sleep(1000);
    action = rand() % (100 - 1 + 1) + 1;
    Sleep(1000);
    if (action >= 1 && action <= 40) {
        actionOpp[round] = 1;
        attackOpp = rand() % 5;
        hpPlayer -= attackOpp;
        printf("Opponent attacks player for %d HP.\n", attackOpp);
        printf("------------------\n");
        printf("Player's HP: %d/%d\n", hpPlayer, hp);
        printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
        Sleep(1000);
    }
    else if (action > 71 && action <= 85) {
        actionOpp[round] = 2;
        attackPlayer -= 3;
        printf("Opponent defends their position, reducing player's attack by 3.\n");
        Sleep(1000);
    }
    else if (action > 86 && action <= 100) {
        hpOpp += 2;
        actionOpp[round] = 3;
        if (hpOpp > hp) {
            printf("Opponent is now at maximum health. \n");
            hpOpp = hp;
            printf("------------------\n");
            printf("Player's HP: %d/%d\n", hpPlayer, hp);
            printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
            Sleep(1000);
        }
        else{
            printf("Opponent tends to their wounds, healing themselves by 2. \n");
            printf("------------------\n");
            printf("Player's HP: %d/%d\n", hpPlayer, hp);
            printf("Opponent's HP: %d/%d\n\n", hpOpp, hp);
            Sleep(1000);
        }
    }
    else if (action > 41 && action <= 70) {
        actionOpp[round] = 4;
         if (themeOpp == 1){
            specialRobotOpp();
            }
         else if (themeOpp == 2) {
              specialWizardOpp();
            }
         else if (themeOpp == 3) {
              specialWarriorOpp();
            }
        }
    Sleep(1000);
    return hpPlayer, hpOpp, attackPlayer, attackOpp;
    }

int main() {
    printf("Welcome to The Game! \n");
    printf("-------------------- \n");
    printf("Please enter your theme of choice: \n");
    printf("[1] Robots \n");
    printf("[2] Wizards \n");
    printf("[3] Warriors \n");
    scanf("%d", &themePlayer);
    while (themePlayer < 1 || themePlayer > 3) {
        printf("You entered an invalid hp value. Please try again. \n");
        printf("Enter HP for both players (50-200):");
        scanf("%d", &hp);
    }

    printf("Opponent is choosing his theme...\n");
    themeOpp = rand() % (3 - 1 + 1) + 1;
    while (themeOpp < 1 || themeOpp > 3) {
        printf("You entered an invalid hp value. Please try again. \n");
        printf("Enter HP for both players (50-200):");
        scanf("%d", &hp);
    }
    Sleep(1000);
    system("cls");

    printf("Enter HP for both players (50-200):");
    scanf("%d", &hp);
    while (hp < 50 || hp > 200) {
        printf("You entered an invalid hp value. Please try again. \n");
        printf("Enter HP for both players (50-200:");
        scanf("%d", &hp);
    }
    printf("Both players' HP will be %d\n", hp);
    Sleep(500);
    system("cls");
    hpPlayer = hp;
    hpOpp = hp;

    printf("Enter amount of rounds for the game:");
    scanf("%d", &roundGame);
    while (roundGame < 1 || roundGame > 50) {
        printf("You entered an invalid hp value. Please try again. \n");
        printf("Enter HP for both players (50-200:");
        scanf("%d", &hp);
    }
    printf("Rounds are set! Get ready for the next battle!", hp);
    Sleep(500);
    system("cls");
    firstPlayer = rand() % (2 - 1 + 1) + 1;
    Sleep(500);


    if (firstPlayer == 1) {
        printf("You go first! \n");
        printf("------------------\n");
        Sleep(500);
        system("cls");
        do {
            for (round = 1; round <= roundGame; round++) {
                printf("Round %d\n", round);

                playerTurn();
                if (hpOpp <= 0) {
                    printf("Game Over! Player wins.\n");
                    Sleep(500);
                    summaryMatch();
                    break;
                }

                OppTurn();
                if (hpPlayer <= 0) {
                    printf("Game Over! Opponent wins.\n");
                    Sleep(500);
                    summaryMatch();
                    break;
                }
                system("cls");
            }
        }
        while (hpPlayer > 0 && hpOpp > 0);
    }
    else {
        printf("The opponent goes first! \n");
        printf("------------------\n");
        Sleep(500);
        do {
            for (round = 1; round <= roundGame; round++) {
                printf("Round %d\n", round);
                OppTurn();
                if (hpPlayer <= 0) {
                    printf("Game Over! Opponent wins.\n");
                    summaryMatch();
                    break;
                }

                playerTurn();
                if (hpOpp <= 0) {
                    printf("Game Over! Player wins.\n");
                    summaryMatch();
                    break;
                }
                system("cls");
            }
            if (hpPlayer == hpOpp) {
                printf("Game Over! It is a tie!\n");
                Sleep(500);
                summaryMatch();
                break;
            }
            else if (hpPlayer > hpOpp) {
                printf("Game Over! Player wins.\n");
                Sleep(500);
                summaryMatch();
                break;
            }
            else {
                printf("Game Over! Opponent wins.\n");
                Sleep(500);
                summaryMatch();
                break;
            }
        }
        while (hpPlayer > 0 && hpOpp > 0);
    }
    return 0;
}
