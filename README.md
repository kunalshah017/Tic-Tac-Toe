<h1> Console-based Tic Tac Toe Game </h1>

<img src="https://i.pinimg.com/originals/d0/60/76/d060769c9561391e5ab09286b03ecc79.jpg" alt="Tic Tac Toe" width="200" height="200" align="right">

This is a console-based implementation of the popular Tic Tac Toe game, written in C++. The game allows two players to play against each other on a 3x3 grid.

## Features

- Interactive gameplay in the console
- Clear and intuitive user interface
- Error handling for invalid moves
- Intelligent computer player (optional)

## Getting Started

### Prerequisites

To compile and run the Tic Tac Toe game, you need to have the following software installed on your system:

- C++ compiler (supporting C++11 or later)
- Make sure the necessary libraries are available (standard library).

### Compilation

To compile the game, run the following command in your terminal or command prompt:
```
g++ -std=c++11 main.cpp -o tictactoe
```

### Running the Game

After successful compilation, you can run the game by executing the compiled binary:

```
./tictactoe
```


Follow the on-screen instructions to play the game. Players can take turns and enter their moves by entering the corresponding position number. The game will display the updated board after each move and determine the winner or a draw when applicable.

## Game Rules

1. The game is played on a 3x3 grid.
2. Two players take turns to mark a vacant cell with their respective symbols (X and O).
3. The objective is to get three of their symbols in a horizontal, vertical, or diagonal row.
4. The game ends when either one player achieves the winning condition or there are no more vacant cells left (a draw).

## Customize the Game

If you want to customize the game further, you can explore the source code files:

- `main.cpp`: Contains the main entry point and user interface logic.

Feel free to modify and enhance the code as per your requirements.

## Acknowledgements

The image used in this README is sourced from [Pinterest](https://i.pinimg.com/originals/d0/60/76/d060769c9561391e5ab09286b03ecc79.jpg). All rights belong to the original creator.

## License

This project is licensed under the [MIT License](LICENSE).

