# Memory Game Challenge
You have been tasked with creating a Memory Game. The game tests the users memory, by showing a sequence of lights toggling on and off and then letting the user enter the correct order using buttons. Down below you will find a video demo and the *requirements specification*.

Before we start the challenge, we need to make sure that you have set up the project correctly!

## Requirements Specification
For this project, you have already been supplied with the drivers for the buttons and the leds. As you can see in main, this is the logic used for checking input and controlling the leds.

You can check the following files to see what public functions you are able to use:
* [led_driver.hpp](./include/led_driver.hpp)
* [button_driver.hpp](./include/button_driver.hpp)

The game can basically be divided into 4 parts:

* **Game Logic** - responsible for handling the underlying game logic and keeping track on your games current state.
* **Game GUI** - responsible for the led animation used to give feedback to the user.
* **Game Input** - responsible for how we receieve input from the user.
* **Game System** - the high-level implementation of our underlying classes.

### 1. Game Logic
The following logic should be applied to the game:
* Player only have 3 tries each game.
* The game only has 20 levels.
* Each level adds 2 new sequences to the game.
* Keep track of the current state.

### 2. Game GUI
The following operations should have animations:
* When turning on the device
* Showing available main menu options
* New game
* Wrong entry and game lost
* Correct entry and game won
* Highlighting the pushed LED during game

### 3. Game Input
The following three functions should be implemented:
* `wait_for_input()` - waits indefinitetly on user input
* `wait_for_input_ms(ms)` - waits for a specified time on user input or times out
* `flush()` - resets the button states.

### 4. Game System
The following functionality should be implemented:
* 


## Setting up the project

### 1. Create a project on GitHub
Navigate to your repositories and create a new, empty public repository called `memory_game`.

### 2. Invite your groupmembers
Invite your group members by navigating to your new repository `memory_game`. Then:
1. Go to Settings
2. Open Collaborators
3. Add your group members

### 3. Download the GitHub template
Download this repository (the same one you are reading in right now): https://github.com/lafftale1999/memory_game_template

Extract the project.

### 4. Connecting it to GitHub
Open Git Bash and navigate to the root of the project you downloaded in [step 3](#3-download-the-github-template). The path should be something like the following: `C:\Users\prett\Desktop\dev\memory_game>`

Run the following commands:

1. Initialize Git to track your repository
    ```sh
    git init
    ```

2. Connect the local repository to your GitHub repository
    ```sh
    git remote add origin <link_to_git_hub_repo>
    ```

3. Push your initial commit
    ```sh
    git add .
    ```
    ```sh
    git commit -m "initial commit"
    ```
    ```sh
    git push origin main
    ```

### 5. Inform your mentor
When you have succesfully created the project, please let your mentor look at it to avoid problems further down the line!

## 