*This project has been created as part of the 42 curriculum by rumartin and framirez.*
# PUSH_SWAP - @42Malaga <img align="right" src="https://img.shields.io/badge/Lenguaje-C-green?style=for-the-badge&logo=c" alt="Lenguaje C">
## <span style="color: orange"> Description </span>
The push_swap project serves as an initial exploration of the underlying logic behind algorithms. The objective was to write a program capable of sorting data stored in a stack, using an empty auxiliary stack, a limited set of possible instructions, and optimizing the total number of operations required for the sort. The program uses three sorting algorithms of varying complexity and is capable of selecting the most appropriate one based on the degree of disorder in the initial stack. It also counts withe a benchmark mode which displays the following information after sorting:
* The computed disorder.
* The name of the strategy used and its theoretical complexity class.
* The total number of operations.
* The count of each operation type.

## <span style="color: orange">Instructions </span>
The project includes a Makefile that automates the build process. 
### <span style="color: green"> Compilation </span>
To compile the executable, run:
```bash
make
```
This command compiles all source files, builds the custom `ftprintf` library, and generates the `push_swap` executable.
### <span style="color: green"> Cleaning build files </span>
To remove all object files:
```bash
make clean
```
To remove object files an the executable:
```
make fclean
```
To perform a full rebuild:
```Bash
make re
```
### <span style="color: green"> Execution</span>
After compilation, execute the program using:
```Bash
./push_swap <list_of_integers>
```
Example:
```Bash
./push_swap 8 2 5 1 3
```
The program will output the sequence of operations required to sort the numbers according to the program specifications.
## <span style="color: orange"> Algorithms </span>
After studying and evaluating the different approaches to this project, we decided to work with circular doubly linked lists, keeping the following advantages in mind:
* **Efficient rotations (ra, rb, rra, rrb)**: Since the list is circular, rotating the stack forward or backward only requires updating the head pointer, without traversing the entire list.
* **Bidirectional traversal:** Each node stores references to both the next and previous nodes, making it easy to implement forward and reverse operations with constant time complexity O(1).
* **Fast insertions and removals:** Operations such as pa and pb can be performed by updating a few links between nodes, avoiding data movement or costly structural reorganizations.
### <span style="color: green"> Simple algorithm <O(*n*²)></span>
In developing the simple-complexity algorithm, the model chosen for its construction is based on the `simple min extraction method`.

A strategy of successively extracting the minimum value was chosen because it naturally fits the two-stack model implemented using circular doubly linked lists. In each iteration, it is only necessary to locate the minimum element, rotate the stack until it is at the head, and transfer it to the auxiliary stack. Circular lists allow for efficient rotations (ra and rra), since there is no physical beginning or end to the structure and the movement can be performed simply by updating the reference node. Furthermore, because they have double links, it is possible to traverse the stack in both directions and choose the rotation direction that requires the fewest moves to reach the minimum.
### <span style="color: green"> Medium algorithm <O(*n* √*n*)></span>
The algorithm implements a `chunk-based sorting` strategy. After assigning each element an index based on its position in the overall order, the elements are divided into blocks of approximate size √n. Each block is progressively transferred from stack A to stack B through successive rotations, thereby avoiding repeated searches for the global minimum. Subsequently, the original stack is reconstructed by extracting the elements with the highest indices from B.

This strategy is particularly well-suited for circular doubly linked lists, as the rotation operations required to locate elements in each chunk are performed naturally due to the circularity of the structure. Furthermore, the double links allow for direct and reverse rotations to be performed with equal ease, reducing the number of moves needed to place each target element at the head of the stack.
### <span style="color: green"> Complex algorithm <O(*n* log *n*)></span>
The algorithm implements a variant of `quick sort adaptation with stack partitioning`. In each recursive call, an approximate pivot is selected using the median of the elements in the current subset, and the set is divided into two partitions using only swap and rotation operations between stacks A and B. Subsequently, the same procedure is applied recursively to both partitions.

This strategy is particularly well-suited for circular doubly linked lists, as the partitioning process can be performed through successive rotations without the need to swap arbitrary elements. The circularity facilitates traversing the entire structure during partitioning, while the double links allow rotations to be undone efficiently. Furthermore, using a median as the pivot promotes balanced partitions, bringing the algorithm’s behavior close to a time complexity of O(n log n).
### <span style="color: green"> Custom adaptative algorithm</span>
To implement the adaptive algorithm, we use a function that measures the degree of disorder in the initial stack and assigns it a value between 0 and 1, selecting the most optimal strategy from among those described above as follows:
* **Low disorder:** if disorder < 0.2 runs the simple min extraction method (O(n²)).
* **Medium disorder:** if 0.2  ≤ disorder < 0.5 runs the chunk-based sorting strategy (O(n √n)).
* **Complex algorithm:** if disorder ≥ 0.5 runs the quick sort adaptation with stack partitioning method (O(n log n))
## <span style="color: orange"> Contributions </span>
Push Swap was designed as a collaborative project, so dividing up tasks was essential for making efficient progress. Although both team members were involved in reviewing and validating the entire project, each member led the development of the following areas:
| User       | files                                      |
| -------    | ---------------------------                |
| `rumartin` | main.c, bench.c, parser.c, parser_utils.c, errors.c, ft_simple.c, ft_complex.c, ft_complex_utils.c, ft_split.c, ft_split_utils.c, Makefile                                                  |
| `framirez` | swap.c, rotate.c, reverse_rotate.c, push.c, ft_medium.c, algorithms_utils.c, push_swap.h                                                         |

## <span style="color: orange"> Resources </span>
### <span style="color: green"> References</span>
* **Peer-to-Peer Learning:**
Collaborative discussions with fellow students provided valuable insights and enhanced understanding throughout the project.
### <span style="color: green"> AI Usage</span>
AI was used only to deepen our understanding of algorithmic concepts and sorting techniques. The project's architecture, logic, and implementation were designed and coded independently.
