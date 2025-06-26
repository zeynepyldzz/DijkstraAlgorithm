#include <limits.h>
#include <iostream>
#include <stdio.h>
#define V 9    // Grafikteki köþe sayýsý
using namespace std;
// Minimum mesafe deðerine sahip tepe noktasýný bulmak için bir yardýmcý iþlev
// en kýsa yol aðacýna henüz dahil olmayan köþe noktalarý kümesi
int minDistance(int dist[], bool sptSet[])
{
	// Minimum deðeri baþlat
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
// Oluþturulan mesafe dizisini yazdýrmak için bir yardýmcý iþlev
int printSolution(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Dijkstra'nýn tek kaynaklý en kýsa yol algoritmasýný uygulayan iþlev
// bitiþik matris gösterimi kullanýlarak temsil edilen bir grafik için
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // Çýkýþ dizisi. dist[i] en kýsa olaný tutar
// src'den i'ye olan mesafe

	bool sptSet[V]; // sptSet[i], i köþesi en kýsaya dahil edilmiþse doðru olur
// yol aðacý veya src'den i'ye olan en kýsa mesafe sonlandýrýlýr


	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

// Kaynak tepe noktasýnýn kendisinden uzaklýðý her zaman 0'dýr
	dist[src] = 0;

	// Tüm köþeler için en kýsa yolu bul
	for (int count = 0; count < V - 1; count++) {
		// olmayan köþeler kümesinden minimum uzaklýk tepe noktasýný seçin
// henüz iþlendi. u, ilk yinelemede her zaman src'ye eþittir.
		int u = minDistance(dist, sptSet);
// Tüm mesafeleri INFINITE olarak ve stpSet[]'i false olarak baþlat
		// Seçilen tepe noktasýný iþlendi olarak iþaretle
		sptSet[u] = true;

		// Seçilen tepe noktasýnýn bitiþik köþelerinin dist deðerini güncelleyin.
		for (int v = 0; v < V; v++)

		// dist[v]'yi yalnýzca sptSet'te deðilse güncelleyin, buradan bir kenar varsa
// u'dan v'ye ve src'den v'den u'ya giden yolun toplam aðýrlýðý
// dist[v]'in geçerli deðerinden daha küçük
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// oluþturulan mesafe dizisini yazdýr
	printSolution(dist, V);
}

// yukarýdaki iþlevi test etmek için sürücü programý
int main()
{
		string satir1; string satir2; string satir3;string satir4;string satir5;string satir6;string satir7;
		string sutun1;string sutun2;string sutun3;string sutun4;string sutun5;string sutun6;string sutun7;
	    satir1=sutun1="Ev";
	    satir2=sutun2="Beykoz Universitesi";
	    satir3=sutun3="Atasehir";
	    satir4=sutun4="Kadikoy";
	    satir5=sutun5="Uskudar";
	    satir6=sutun6="Tepeustu";
	    satir7=sutun7="Mecidiyekoy";

	
	int graph[V][V] = { { 0 , 57, 54, 13, 76, 87, 13,23,25},
						{ 25, 0, 55, 35, 20, 20, 30 },
						{ 15, 55, 0, 20, 35,20, 53 },
						{ 30, 35,20, 0, 15, 35, 33 },
						{ 24,20, 35, 15, 0, 29, 18 },
						{ 5, 20, 20, 35, 29, 0, 47 },
						{ 42,30, 53, 33, 18, 47, 0 }
						 };
    
	dijkstra(graph, 0);


	return 0;
}

