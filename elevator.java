import java.util.Scanner;

// Enum to represent the current state of the elevator
enum ElevatorState {
    IDLE,
    UP,
    DOWN
}

public class ElevatorControl {
    public static void main(String[] args) {
        ElevatorState currentState = ElevatorState.IDLE;
        int destinationFloor;

        Scanner scanner = new Scanner(System.in);

        while (true) {
            // Display the menu
            System.out.println("\nElevator Control Menu:");
            System.out.println("1. Move Up");
            System.out.println("2. Move Down");
            System.out.println("0. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the desired floor (between basement and level 50): ");
                    destinationFloor = scanner.nextInt();

                    // Validate the input floor range
                    if (destinationFloor < -1 || destinationFloor > 50) {
                        System.out.println("Invalid floor selection. Please choose a floor between basement and level 50.");
                        continue; // Skip to the next iteration of the loop
                    }

                    // Request to move the elevator up
                    if (currentState == ElevatorState.IDLE) {
                        moveUp(destinationFloor);
                        currentState = ElevatorState.UP;
                    }
                    break;

                case 2:
                    System.out.print("Enter the desired floor (between basement and level 50): ");
                    destinationFloor = scanner.nextInt();

                    // Validate the input floor range
                    if (destinationFloor < -1 || destinationFloor > 50) {
                        System.out.println("Invalid floor selection. Please choose a floor between basement and level 50.");
                        continue; // Skip to the next iteration of the loop
                    }

                    // Request to move the elevator down
                    if (currentState == ElevatorState.IDLE) {
                        moveDown(destinationFloor);
                        currentState = ElevatorState.DOWN;
                    }
                    break;

                case 0:
                    System.out.println("Exiting elevator control program. Goodbye!");
                    scanner.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        }
    }

    // Function to move the elevator up
    private static void moveUp(int destinationFloor) {
        for (int currentFloor = 0; currentFloor < destinationFloor; ++currentFloor) {
            System.out.println("Elevator at floor " + currentFloor);
            // Add code to control the elevator motor and update state

            // Simulate 1-second delay between floors
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Elevator arrived at floor " + destinationFloor);

        // Open and close the elevator door
        System.out.print("Press 'C' to open the door: ");
        Scanner scanner = new Scanner(System.in);
        char response = scanner.next().charAt(0);
        if (response == 'C') {
            System.out.println("Elevator door opening.");
            // Simulate 3-second delay for the door to stay open
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Elevator door closing.");
        }

        // Add code to control the elevator motor and update state
    }

    // Function to move the elevator down
    private static void moveDown(int destinationFloor) {
        for (int currentFloor = 0; currentFloor > destinationFloor; --currentFloor) {
            System.out.println("Elevator at floor " + currentFloor);
            // Add code to control the elevator motor and update state

            // Simulate 1-second delay between floors
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Elevator arrived at floor " + destinationFloor);

        // Open and close the elevator door
        System.out.print("Press 'C' to open the door: ");
        Scanner scanner = new Scanner(System.in);
        char response = scanner.next().charAt(0);
        if (response == 'C') {
            System.out.println("Elevator door opening.");
            // Simulate 3-second delay for the door to stay open
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Elevator door closing.");
        }

        // Add code to control the elevator motor and update state
    }
}
