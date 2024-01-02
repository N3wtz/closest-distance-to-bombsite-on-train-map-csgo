#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX

using namespace std;

// Fungsi untuk mencari lintasan terdekat menggunakan algoritma Dijkstra
void dijkstra(vector<vector<int>>& graph, int start, int dest) {
    int n = graph.size();

    // Vektor untuk menyimpan jarak terdekat dari start ke semua vertex
    vector<int> distance(n, INF);

    // Vektor untuk menyimpan lintasan terdekat dari start ke setiap vertex
    vector<vector<int>> paths(n);

    // Priority queue untuk memilih vertex dengan jarak terdekat
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0) {
                int weight = graph[u][v];
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));

                    paths[v].clear();
                    paths[v].insert(paths[v].end(), paths[u].begin(), paths[u].end());
                    paths[v].push_back(u);
                }
            }
        }
    }

    // Cetak lintasan terdekat dari start ke dest
    cout << "Closest distance from " << char(start + 'A') << " to bombsite is: ";
    for (int i = 0; i < paths[dest].size(); i++) {
        cout << char(paths[dest][i] + 'A') << " -> ";
    }
    cout << char(dest + 'A') << endl;

    // Cetak jumlah bobot jarak terdekat dari start ke dest
    cout << "Estimated Time Required (in seconds): " << distance[dest] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2},
        {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 2, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 3},
        {0, 0, 0, 0, 0, 0, 7, 6, 5, 0, 0, 2, 2, 0, 0, 0},
        {0, 0, 0, 4, 4, 0, 2, 2, 2, 0, 2, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 4, 3, 3, 0, 0, 0}
    };

    int startVertex, bomVertex;
    char start, bom;
    
    cout << "===================================================================" << endl;
	cout << "      Closest Distance to Bombsite on Train Map CSGO Program" << endl;
    cout << "===================================================================" << endl;
    cout << "Location List:" << endl;
    cout << "Vertex A represents T Spawn (starting place terorist)" << endl;
    cout << "Vertex B represents Big Blue" << endl;
    cout << "Vertex C represents T Long" << endl;
    cout << "Vertex D represents Break Room" << endl;
    cout << "Vertex E represents Ladder" << endl;
    cout << "Vertex F represents Lower Ramp" << endl;
    cout << "Vertex G represents A3 Train" << endl;
    cout << "Vertex H represents A2 Train" << endl;
    cout << "Vertex I represents A1 Train" << endl;
    cout << "Vertex J represents Boilers" << endl;
    cout << "Vertex K represents Connector" << endl;
    cout << "Vertex L represents Pink Train" << endl;
    cout << "Vertex M represents Cloud" << endl;
    cout << "Vertex N represents CT Spawn (starting place anti-terorist)" << endl;
    cout << "Vertex O represents Bombsite A" << endl;
    cout << "Vertex P represents Bombsite B" << endl;


    cout << "Choose Initial Vertex (Use Capital Letters): ";
    cin >> start;
    startVertex = start - 'A';

	cout << "Choose Bombsite "<< endl;
    cout << "Bombsite A Type O "<< endl;
    cout << "Bombsite B Type P"<< endl;
    cout << "Choose Bombsite (Use Capital Letters): ";

    cin >> bom;
    bomVertex = bom - 'O' + 14;

    dijkstra(graph, startVertex, bomVertex);

    return 0;
}
