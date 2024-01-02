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
    cout << "Lintasan terdekat dari Vertex " << char(start + 'A') << " ke bombsite adalah: ";
    for (int i = 0; i < paths[dest].size(); i++) {
        cout << char(paths[dest][i] + 'A') << " -> ";
    }
    cout << char(dest + 'A') << endl;

    // Cetak jumlah bobot jarak terdekat dari start ke dest
    cout << "Perkiraan Waktu yang Dibutuhkan: " << distance[dest] << endl;
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
	cout << "Program Penentuan Rute Terdekat Menuju Bombsite pada Permainan CSGO" << endl;
    cout << "===================================================================" << endl;
    cout << "Daftar Lokasi:" << endl;
    cout << "Vertex A melambangkan T Spawn (tempat awal teroris)" << endl;
    cout << "Vertex B melambangkan Big Blue" << endl;
    cout << "Vertex C melambangkan T Long" << endl;
    cout << "Vertex D melambangkan Break Room" << endl;
    cout << "Vertex E melambangkan Ladder" << endl;
    cout << "Vertex F melambangkan Lower Ramp" << endl;
    cout << "Vertex G melambangkan A3 Train" << endl;
    cout << "Vertex H melambangkan A2 Train" << endl;
    cout << "Vertex I melambangkan A1 Train" << endl;
    cout << "Vertex J melambangkan Boilers" << endl;
    cout << "Vertex K melambangkan Connector" << endl;
    cout << "Vertex L melambangkan Pink Train" << endl;
    cout << "Vertex M melambangkan Cloud" << endl;
    cout << "Vertex N melambangkan CT Spawn (tempat awal anti-teroris)" << endl;
    cout << "Vertex O melambangkan Bombsite A" << endl;
    cout << "Vertex P melambangkan Bombsite B" << endl;


    cout << "Pilih Vertex Awal (Gunakan Kapital): ";
    cin >> start;
    startVertex = start - 'A';

	cout << "Pemilihan Bombsite "<< endl;
    cout << "Jika Bombsite A Ketik O "<< endl;
    cout << "Jika Bombsite B Ketik P"<< endl;
    cout << "Pilih Bom (Gunakan Kapital): ";

    cin >> bom;
    bomVertex = bom - 'O' + 14;

    dijkstra(graph, startVertex, bomVertex);

    return 0;
}
