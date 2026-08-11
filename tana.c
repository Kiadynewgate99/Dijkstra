#include <stdio.h>
#include <float.h>

#define NB_SOMMETS 30
#define INFINI DBL_MAX

const char *lieux[NB_SOMMETS] = {
    "Analakely",
    "Antaninarenina",
    "Ambohijatovo",
    "Isotry",
    "Behoririka",
    "Tsaralalana",
    "Andravoahangy",
    "Anosy",
    "Mahamasina",
    "Ampefiloha",
    "Antanimena",
    "Faravohitra",
    "Ambatonakanga",
    "67Ha",
    "Anosibe",
    "Ankorondrano",
    "Ivandry",
    "Andraharo",
    "Ankadifotsy",
    "Ambohimanarina",
    "Ankatso",
    "Ambohipo",
    "Alarobia",
    "Ankadindramamy",
    "Itaosy",
    "Tanjombato",
    "Andoharanofotsy",
    "Ambohidratrimo",
    "Ivato",
    "Alasora"
};

typedef struct {
    int a, b;
    double distance;
} Route;

Route routes[] = {
    {0, 1, 0.5}, {0, 2, 0.8}, {0, 3, 1.2}, {0, 4, 1.0}, {0, 5, 0.6}, {0, 9, 1.5},
    {1, 7, 1.5}, {1, 2, 0.7}, {1, 11, 1.0},
    {2, 8, 1.3}, {2, 12, 0.6},
    {3, 6, 1.8}, {3, 13, 1.0}, {3, 14, 2.0},
    {4, 6, 1.4}, {4, 15, 2.5},
    {5, 7, 1.1},
    {7, 8, 1.6}, {7, 9, 1.2},
    {6, 15, 2.0}, {6, 18, 1.5},
    {15, 16, 2.2}, {15, 17, 1.8},
    {16, 17, 1.0}, {16, 20, 2.5},
    {20, 21, 1.2}, {20, 22, 2.0},
    {22, 23, 1.5},
    {13, 8, 1.5}, {13, 7, 1.7}, {13, 14, 1.3},
    {14, 25, 3.5},
    {25, 26, 2.5}, {25, 24, 4.0},
    {24, 27, 5.0},
    {27, 28, 6.0},
    {17, 28, 5.5},
    {18, 19, 2.0},
    {19, 28, 4.0},
    {9, 10, 1.0},
    {10, 11, 1.2},
    {8, 29, 4.5},
    {26, 29, 3.0}
};

int nbRoutes = sizeof(routes) / sizeof(routes[0]);
double graphe[NB_SOMMETS][NB_SOMMETS];

void construireGraphe(void) {
    for (int i = 0; i < NB_SOMMETS; i++) {
        for (int j = 0; j < NB_SOMMETS; j++) {
            graphe[i][j] = 0.0;
        }
    }

    for (int k = 0; k < nbRoutes; k++) {
        int a = routes[k].a;
        int b = routes[k].b;
        graphe[a][b] = routes[k].distance;
        graphe[b][a] = routes[k].distance;
    }
}

int sommetMinimal(double distance[], int marque[]) {
    double min = INFINI;
    int indexMin = -1;

    for (int v = 0; v < NB_SOMMETS; v++) {
        if (!marque[v] && distance[v] < min) {
            min = distance[v];
            indexMin = v;
        }
    }

    return indexMin;
}

void afficherChemin(int predecesseur[], int cible) {
    int chemin[NB_SOMMETS];
    int n = 0;
    int s = cible;

    while (s != -1) {
        chemin[n++] = s;
        s = predecesseur[s];
    }

    for (int k = n - 1; k >= 0; k--) {
        printf("%s", lieux[chemin[k]]);
        if (k != 0) printf(" -> ");
    }
    printf("\n");
}

void dijkstra(int source, int destination) {
    double distance[NB_SOMMETS];
    int marque[NB_SOMMETS];
    int predecesseur[NB_SOMMETS];

    for (int i = 0; i < NB_SOMMETS; i++) {
        distance[i] = INFINI;
        marque[i] = 0;
        predecesseur[i] = -1;
    }
    distance[source] = 0.0;

    for (int count = 0; count < NB_SOMMETS; count++) {
        int u = sommetMinimal(distance, marque);
        
        if (u == -1 || u == destination) break;
        
        marque[u] = 1;

        for (int v = 0; v < NB_SOMMETS; v++) {
            double poids = graphe[u][v];
            if (!marque[v] && poids != 0.0 && distance[u] != INFINI &&
                distance[u] + poids < distance[v]) {
                distance[v] = distance[u] + poids;
                predecesseur[v] = u;
            }
        }
    }

    printf("\n*******************************************************\n");
    if (distance[destination] == INFINI) {
        printf("Aucun chemin trouve entre %s et %s.\n", lieux[source], lieux[destination]);
    } else {
        printf("PCC : %s -> %s\n", lieux[source], lieux[destination]);
        printf("Distance totale : %.1f km\n", distance[destination]);
        printf("Itineraire      : ");
        afficherChemin(predecesseur, destination);
    }
    printf("*********************************************************\n");
}

void afficherMenu(void) {
    printf("\nLieux disponibles a Antananarivo :\n");
    for (int i = 0; i < NB_SOMMETS; i++) {
        printf("  %2d - %-18s", i, lieux[i]);
        if (i % 2 == 1) printf("\n");
    }
    if (NB_SOMMETS % 2 != 0) printf("\n");
}

int main(void) {
    construireGraphe();

    int source, destination;

    printf("=== Plus court chemin (Moore-Dijkstra) - Antananarivo ===\n");
    afficherMenu();

    printf("\nEntrez le numero du point A (depart)  : ");
    if (scanf("%d", &source) != 1) return 1;

    printf("Entrez le numero du point B (arrivee) : ");
    if (scanf("%d", &destination) != 1) return 1;

    if (source < 0 || source >= NB_SOMMETS || destination < 0 || destination >= NB_SOMMETS) {
        printf("Otrany tsisy anzany nioma zany rzanj a\n");
        return 1;
    }

    dijkstra(source, destination);
    return 0;
}