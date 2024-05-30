# Truck Fueling Problem Solver using Heaps
This repository contains a C++ program that solves a truck fueling problem using a max heap (priority queue).


## Heaps
A heap is a specialized tree-based data structure that satisfies the heap property. A max heap ensures that the parent node is always greater than or equal to its child nodes, making it useful for efficiently retrieving the maximum element. A min heap, on the other hand, ensures that the parent node is always less than or equal to its child nodes. Heaps are commonly implemented using binary trees.


## Problem Description
Given a truck that needs to travel a distance `L` with an initial amount of fuel `P`, determine if the truck can complete the journey using the available fuel stations. Each fuel station is located at a certain distance from the start and can provide a specific amount of fuel. The goal is to find the minimum number of refueling stops needed to reach the destination. If the journey is not possible, return `-1`.

### Constraints
- `1 <= N <= 10000` (number of fuel stations)
- `1 <= L <= 1000000` (total distance to travel)
- `1 <= P <= 1000000` (initial amount of fuel)
- `1 <= Ai < L` (location of each fuel station)
- `1 <= Bi <= 100` (amount of fuel provided by each station)

### Input
- An integer `N` representing the number of fuel stations.
- An integer `L` representing the total distance to travel.
- An integer `P` representing the initial amount of fuel.
- A list of `N` integers `A` representing the distances of the fuel stations from the start.
- A list of `N` integers `B` representing the amount of fuel each station provides.

### Output
- A single integer representing the minimum number of refueling stops needed to reach the destination. If the journey is not possible, return `-1`.

### Input & Output Sample
#### Input
```
4 25 10
10 14 20 21
10 5 2 4
```

#### Output
```
2
```
Explanation: The truck starts with 10 units of fuel and needs to travel 25 units of distance. By refueling at the stations at distances 10 and 20, it can reach the destination with a minimum of 2 refueling stops.

### Solution Approach
To solve this problem, we can use a max heap to keep track of the fuel available at each station as we pass them. By always refueling with the maximum available fuel at each step, we ensure that the number of stops is minimized.

### Algorithm
1. **Sort** the fuel stations by their distance from the start.
2. **Initialize** a max heap to keep track of the fuel available at the stations.
3. **Traverse** through the distance from the start to the destination:
   - At each fuel station, add the available fuel to the heap.
   - When the fuel runs out, refuel from the heap (if available).
4. **Check** if the truck can reach the destination with the available fuel and refueling stops.


## Author
Yuki Tsuboi