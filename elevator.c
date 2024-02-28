#include <stdio.h>
#include <unistd.h> // for sleep function

// Enum to represent the current state of the elevator
enum ElevatorState {
    IDLE,
    UP,
    DOWN
};

// Function to move the elevator up
void moveUp(int destinationFloor) {
    for (int currentFloor = 0; currentFloor < destinationFloor; ++currentFloor) {
        printf("Elevator at floor %d.\n", currentFloor);

        // Check for emergency interrupt
        char response;
        printf("If emergency, press 'S' to stop. Continue with 'G': ");
        scanf(" %c", &response);

        if (response == 'S') {
            printf("Emergency stop. Elevator paused.\n");
            printf("Press 'G' to resume.\n");
            
            // Wait for 'G' to resume
            while (1) {
                scanf(" %c", &response);
                if (response == 'G') {
                    break;
                }
            }

            printf("Resuming elevator.\n");
        }

        sleep(1); // 1-second delay between floors
    }
    printf("Elevator arrived at floor %d.\n", destinationFloor);

    // Open and close the elevator door
    printf("Press 'C' to open the door: ");
    scanf(" %c", &response);
    if (response == 'C') {
        printf("Elevator door opening.\n");
        sleep(3); // 3-second delay for the door to stay open
        printf("Elevator door closing.\n");
    }

    // Add code to control the elevator motor and update state
}

// Function to move the elevator down
void moveDown(int destinationFloor) {
    for (int currentFloor = 0; currentFloor > destinationFloor; --currentFloor) {
        printf("Elevator at floor %d.\n", currentFloor);

        // Check for emergency interrupt
        char response;
        printf("If emergency, press 'S' to stop. Continue with 'G': ");
        scanf(" %c", &response);

        if (response == 'S') {
            printf("Emergency stop. Elevator paused.\n");
            printf("Press 'G' to resume.\n");
            
            // Wait for 'G' to resume
            while (1) {
                scanf(" %c", &response);
                if (response == 'G') {
                    break;
                }
            }

            printf("Resuming elevator.\n");
        }

        sleep(1); // 1-second delay between floors
    }
    printf("Elevator arrived at floor %d.\n", destinationFloor);

    // Open and close the elevator door
    printf("Press 'C' to open the door: ");
    scanf(" %c", &response);
    if (response == 'C') {
        printf("Elevator door opening.\n");
        sleep(3); // 3-second delay for the door to stay open
        printf("Elevator door closing.\n");
    }

    // Add code to control the elevator motor and update state
}

int main() {
    enum ElevatorState currentState = IDLE;
    int destinationFloor;

    while (1) {
        // Display the menu
        printf("\nElevator Control Menu:\n");
        printf("1. Move Up\n");
        printf("2. Move Down\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the desired floor (between basement and level 50): ");
                scanf("%d", &destinationFloor);

                // Validate the input floor range
                if (destinationFloor < -1 || destinationFloor > 50) {
                    printf("Invalid floor selection. Please choose a floor between basement and level 50.\n");
                    continue; // Skip to the next iteration of the loop
                }

                // Request to move the elevator up
                if (currentState == IDLE) {
                    moveUp(destinationFloor);
                    currentState = UP;
                }
                break;

            case 2:
                printf("Enter the desired floor (between basement and level 50): ");
                scanf("%d", &destinationFloor);

                // Validate the input floor range
                if (destinationFloor < -1 || destinationFloor > 50) {
                    printf("Invalid floor selection. Please choose a floor between basement and level 50.\n");
                    continue; // Skip to the next iteration of the loop
                }

                // Request to move the elevator down
                if (currentState == IDLE) {
                    moveDown(destinationFloor);
                    currentState = DOWN;
                }
                break;

            case 0:
                printf("Exiting elevator control program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
