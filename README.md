# Closest Distance to Bombsite on Train Map CSGO Program

This program calculates the closest distance from a chosen starting point to one of the bombsites on the Train map in the popular game Counter-Strike: Global Offensive (CSGO). It utilizes the Dijkstra algorithm to find the shortest path.

## How to Use

1. **Compile the Code**: Compile the provided C++ code using a C++ compiler. For example, you can use g++:

    ```
    g++ -o closest_distance_to_bombsite closest_distance_to_bombsite.cpp
    ```

2. **Run the Program**: Execute the compiled program:

    ```
    ./closest_distance_to_bombsite
    ```

3. **Input**: Follow the prompts to input the starting vertex (representing the starting location) and choose which bombsite to target.

4. **Output**: The program will then display the closest path from the chosen starting point to the selected bombsite, along with the estimated time required to reach it.

## Map Details

- **Location List**: The program provides a list of vertices representing various locations on the Train map.
- **Vertex Representation**: Each vertex is represented by a capital letter.
- **Starting Point**: The starting point is represented by vertex A, corresponding to the T Spawn (terrorist starting point).
- **Bombsites**: Bombsite A is represented by vertex O, and Bombsite B is represented by vertex P.

## Sample Input and Output

For example, if the user chooses starting vertex A (T Spawn) and selects Bombsite A, the program might output:

```
===================================================================
      Closest Distance to Bombsite on Train Map CSGO Program
===================================================================
Location List:
Vertex A represents T Spawn (starting place terorist)
Vertex B represents Big Blue
Vertex C represents T Long
...
Choose Initial Vertex (Use Capital Letters): A
Choose Bombsite (Use Capital Letters):
Bombsite A Type O
Bombsite B Type P
Choose Bombsite (Use Capital Letters): O

Closest distance from A to bombsite is: A -> B -> D -> E -> F -> G -> I -> P
Estimated Time Required (in seconds): 14
```

## Notes

- The provided graph represents the distances between various locations on the Train map. Adjustments to the graph can be made to reflect changes in the map layout or distances.
- The program assumes a static map layout and does not consider dynamic factors such as player movements or obstacles.

Sure, here's how you can add sections for requirements, contributions, and licensing to your README:

## Requirements

- **C++ Compiler**: This program is written in C++ and requires a C++ compiler to compile and run.

## Contributions

Contributions to improve the program are welcome. If you'd like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/improvement`).
3. Make your changes.
4. Commit your changes (`git commit -am 'Add new feature/improvement'`).
5. Push to the branch (`git push origin feature/improvement`).
6. Create a new Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
