// ARENA MAPPING.

/* Logic is:
At first in put the .txt file, that has 4 obstacles positions.
column represents the particle postion of the obstacle and row represents the obstacle presence.
By placing the rover at the centre of the arena matrix then calculate the positions of obstacles in the arena by
using x and y coordinate systems. then implement the 0 for obtacle and 1 for safe.*/


/* For the bonus question , to find the shortest path , lets approach the problem with BFS (breadth first search) one of the 
traversal technique for graphs.Then it is easy to find the shortest path.*/


#include <stdio.h>

#define MAX 50  // Maximum size of the arena grid

int main_arena[MAX][MAX]; // Arena matrix: 1 = free cell, 0 = obstacle
int queue_x[MAX * MAX];   // Queue to store x-coordinates during BFS
int queue_y[MAX * MAX];   // Queue to store y-coordinates during BFS
int front = 0, rear = 0;  // Queue pointers

// Movement directions: North, South, East, West
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Enqueue an (x, y) point into the BFS queue
void enqueue(int x, int y) {
    queue_x[rear] = x;
    queue_y[rear] = y;
    rear++;
}

// Dequeue the front point from the BFS queue
void dequeue(int *x, int *y) {
    *x = queue_x[front];
    *y = queue_y[front];
    front++;
}

// Check if (x, y) is inside the arena grid
int isValid(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

// Function to find the shortest path using BFS from (startX, startY) to (endX, endY)
int findShortestPath(int arena[MAX][MAX], int n, int startX, int startY, int endX, int endY) {
    int visited[MAX][MAX] = {0};  // Keeps track of visited cells
    int dist[MAX][MAX] = {0};     // Stores distance from start to each cell

    enqueue(startX, startY);          // Start BFS from the start point
    visited[startX][startY] = 1;      // Mark the start as visited

    while (front < rear) {            // Continue until queue is empty
        int currX, currY;
        dequeue(&currX, &currY);      // Get current cell

        // If we reach the destination, return distance
        if (currX == endX && currY == endY) {
            return dist[endX][endY];
        }

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int nx = currX + dx[i];
            int ny = currY + dy[i];

            // Check if the next cell is valid and not visited and not an obstacle
            if (isValid(nx, ny, n) && !visited[nx][ny] && arena[nx][ny] == 1) {
                visited[nx][ny] = 1;                                // Mark as visited
                dist[nx][ny] = dist[currX][currY] + 1;              // Update distance
                enqueue(nx, ny);                                    // Add to queue
            }
        }
    }

    return -1;  // If destination not reached
}

int main() {
    FILE *file;
    int N[100], E[100], S[100], W[100];   // Arrays to store obstacle directions
    int numObstacles = 0;
    int maxDistance = 0;                 // Used to calculate arena size

    // Open the obstacle file
    file = fopen("sample.txt", "r");
    if (file == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }

    // Read obstacle data line by line
    while (fscanf(file, "%d %d %d %d", &N[numObstacles], &E[numObstacles], &S[numObstacles], &W[numObstacles]) == 4) {
        // Calculate max size needed based on obstacle offsets
        int vertical = N[numObstacles] + S[numObstacles];
        int horizontal = E[numObstacles] + W[numObstacles];
        if (vertical > maxDistance) maxDistance = vertical;
        if (horizontal > maxDistance) maxDistance = horizontal;
        numObstacles++;  // Count total obstacles
    }

    fclose(file);  // Close the file

    int size = 2 * maxDistance + 1;   // Arena will be square (centered around origin)
    int center = maxDistance;        // Center of the grid represents (0, 0)

    // Initialize the arena with 1s (safe space)
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            main_arena[i][j] = 1;

    // Place obstacles (set cells to 0)
    for (int i = 0; i < numObstacles; i++) {
        // Convert relative directions to absolute positions in the arena
        int row = center  +N[i] - S[i];
        int col = center + E[i] - W[i];

        if (row >= 0 && row < size && col >= 0 && col < size)
            main_arena[row][col] = 0;
    }

    // Print the arena grid
    printf("\n\t= Brick's Arena Map =\t\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", main_arena[i][j]);
        }
        printf("\n");
    }

    // Run BFS to find shortest path from (0,0) to (10,10)
    int steps = findShortestPath(main_arena, size, 0, 0, 10, 10);

    // Show result
    if (steps != -1)
        printf("\n Shortest path from (0,0) to (10,10): %d steps.\n", steps);
    else
        printf("\n No path found from (0,0) to (10,10).\n");

    return 0;
}
