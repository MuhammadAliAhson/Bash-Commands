


https://user-images.githubusercontent.com/105967134/229875931-672dc4f8-2357-4be3-a97b-bb2ad39f6a2d.mp4


Exciting news! I've developed a multiplayer game based on threads where up to three players can play simultaneously.

This means that up to three players can play the game simultaneously, and each player can move independently in real-time. The movement of each player is controlled by a separate thread, which ensures that the movements are updated correctly in the terminal buffer.

In addition to the movement, the game also features rewards, which are represented by the '&' symbol. The rewards are scattered throughout the game and add an exciting element to the gameplay. The background of the terminal also changes during the game, providing a visually immersive experience.

To make the game even more enjoyable, I have included a function that plays music while playing the game. To use this function, you will need to install mpv on Ubuntu using the command "sudo -apt install mpv". Once you have installed mpv, you can enjoy the music while playing the game.

Overall, this game offers a unique and fun gaming experience that is both challenging and enjoyable. I hope you give it a try and have a blast!

#operatingsystems #ubuntu #experience #threads 

This C++ code is a simple game based on threads that run on a terminal. The game consists of a 2D game board with randomly placed hidden tokens that need to be collected by the players to score points. The game has up to three players, each represented by a different character on the board. The players move using the 'w', 'a', 's', 'd', 'i', 'j', 'k', and 'l' keys.

The game starts with a menu function that prompts the user for the number of players and their names. The gameboard function is responsible for handling the movement of each player based on the keys pressed by the player. The gameboard function receives an integer array representing the position of a player and updates the array according to the keys pressed by the player. The function also checks if a player collects a hidden token and increases their score accordingly.

The code uses the pthread library to create threads for each player's movement. The main function of the code initializes the game board and randomly places the tokens on the board. The game continues until all tokens are collected by the players, and the player with the highest score at the end of the game wins.

Additionally, the code uses the ALSA library to play background music during the game.
