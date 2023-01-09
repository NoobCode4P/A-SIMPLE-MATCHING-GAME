# HCMUS Programming Techniques Project - THE MATCHING GAME 

## **GAME DESCRIPTIONS**

## ***1. Introduction***

Matching Games, as the name implies, are games that require players to match a pair of similar objects. These objects can be cards, pictures, figures, etc. One of the typical game is **Pikachu Matching Game**, where players are required to match a pair of cells containing the same Pokemnon figure with some particular patterns. A valid match will cause those 2 cells disappear. The game ends when all matching pair are found.

But, in this project, we have made a more simplified version
by remaking the game with characters instead of Pokemon figures.

## ***2. Detailed descriptions***

**1. Game starting**: Initialize a board with the given size while  satisfying the following conditions:
- The total number of cells must be even.
- The number of disticnt characters is specified in advance.
- For each character, determine an even number to define the number of occurrences for that character.

**2. Game control**

Unlike the original one, this project is made without allowing the player to use mouse-click. Instead, players are allowed to use these keys:
- **W**, **A**, **S**, **D** and/or &uarr;, &larr;, &darr;, &rarr; on your keyboard to move *up*, *left*, *down*, *right* respectively.
- **ENTER** to lock your selected cell
- And other keys you will find out in the game.

**3. Matching pair conditions**
- Characters in 2 cells must be identical.
- When the cells disappear, their positions are replaced with blank spaces.
- The matching pattern must be one of the below motifs:
    - I Matching
    - L Matching
    - U Matching
    - Z Matching

![ValidMatches](https://user-images.githubusercontent.com/102032176/211365804-cf2898f1-b9b3-4dea-98a6-8eb9bd30b851.png)

**4. Game finishing**: check these conditions
- Are there any cells left?
- Are there any valid pairs left?

## ***3. Advanced features***
Players will experience the game with some extra features like:
- *Color and sound effects*
- *Visual effects*
- *Background*
- *Leaderboard*: The top N players that finished their games with the shortest time will register their information to the Leaderboard
- *Move suggestion*: player is shown a valid match when pressing **HELP** key

**************************************

## **IDE**
- Microsoft Visual Studio

## **CONTRIBUTORS**
Me and [trkha16](https://github.com/trkha16)

