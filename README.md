
> Antananarivo Shortest Path (Moore-Dijkstra)
> A C-based application that calculates optimal routes between 30 key locations in Antananarivo using the Moore-Dijkstra algorithm. The program models the urban road network as an undirected weighted graph and provides the full step-by-step route along with the total estimated distance in kilometers.
> 

# Antananarivo Shortest Path (Moore-Dijkstra Algorithm)

This project is a C implementation of the Moore-Dijkstra algorithm designed to calculate the shortest path (PCC) between key locations and districts across Antananarivo, Madagascar.

---

## Features

- Integrated Graph: Pre-loaded with 30 locations and their primary connecting roads (weighted edges representing distance in km).
- Route Optimization: Determines the shortest path between a user-selected starting point (Source) and destination (Target).
- Step-by-Step Itinerary: Displays the complete node-by-node sequence along with the total distance.
- Early Stopping Optimization: Halts graph traversal as soon as the target node is extracted from the unvisited set.

---

## Included Locations

The 30 mapped nodes include key areas such as:
- City Center & Commercial: Analakely, Antaninarenina, Ambohijatovo, Isotry, Behoririka, Tsaralalana, Andravoahangy.
- Administrative & Educational: Anosy, Mahamasina, Ampefiloha, Ankatso, Ambohipo.
- Outer Districts & Major Corridors: Ankorondrano, Ivandry, Andraharo, Tanjombato, Ambohimanarina, Ivato (Airport), Itaosy, among others.

---

## Building and Running

### Prerequisites
A standard C compiler (GCC or Clang).

### 1. Compilation
Compile the program using the following terminal command:

```bash
gcc -std=c99 -Wall main.c -o pcc_antananarivo

2. Execution
./pcc_antananarivo

3. Example Output
=== Shortest Path (Moore-Dijkstra) - Antananarivo ===

Available locations in Antananarivo:
   0 - Analakely           1 - Antaninarenina    
   2 - Ambohijatovo        3 - Isotry            
  ...
  20 - Ankatso            28 - Ivato            

Enter the starting point number (A) : 0
Enter the destination number (B)    : 28

================================================
Shortest Path : Analakely -> Ivato
Total distance: 8.1 km
Itinerary     : Analakely -> Tsaralalana -> Anosy -> Ampefiloha -> Antanimena -> Faravohitra -> Ambohimanarina -> Ivato
================================================

Data Modeling
 * Graph Type: Undirected graph where roads are bidirectional (G = (V, E)).
 * Representation: Distance matrix where matrix entries represent road length in kilometers.
 * Space Complexity: \mathcal{O}(V^2) where V = 30.
Disclaimer
> The distances defined in the code are estimations intended for algorithmic demonstration. Real-world applications can replace these static weights with exact GPS measurements or dynamic traffic time data.
>

