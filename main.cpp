#include <limits.h>
#include <iostream>
#include <stdio.h>
#define V 9    // Grafikteki k��e say�s�
using namespace std;
// Minimum mesafe de�erine sahip tepe noktas�n� bulmak i�in bir yard�mc� i�lev
// en k�sa yol a�ac�na hen�z dahil olmayan k��e noktalar� k�mesi
int minDistance(int dist[], bool sptSet[])
{
	// Minimum de�eri ba�lat
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
// Olu�turulan mesafe dizisini yazd�rmak i�in bir yard�mc� i�lev
int printSolution(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Dijkstra'n�n tek kaynakl� en k�sa yol algoritmas�n� uygulayan i�lev
// biti�ik matris g�sterimi kullan�larak temsil edilen bir grafik i�in
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // ��k�� dizisi. dist[i] en k�sa olan� tutar
// src'den i'ye olan mesafe

	bool sptSet[V]; // sptSet[i], i k��esi en k�saya dahil edilmi�se do�ru olur
// yol a�ac� veya src'den i'ye olan en k�sa mesafe sonland�r�l�r


	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

// Kaynak tepe noktas�n�n kendisinden uzakl��� her zaman 0'd�r
	dist[src] = 0;

	// T�m k��eler i�in en k�sa yolu bul
	for (int count = 0; count < V - 1; count++) {
		// olmayan k��eler k�mesinden minimum uzakl�k tepe noktas�n� se�in
// hen�z i�lendi. u, ilk yinelemede her zaman src'ye e�ittir.
		int u = minDistance(dist, sptSet);
// T�m mesafeleri INFINITE olarak ve stpSet[]'i false olarak ba�lat
		// Se�ilen tepe noktas�n� i�lendi olarak i�aretle
		sptSet[u] = true;

		// Se�ilen tepe noktas�n�n biti�ik k��elerinin dist de�erini g�ncelleyin.
		for (int v = 0; v < V; v++)

		// dist[v]'yi yaln�zca sptSet'te de�ilse g�ncelleyin, buradan bir kenar varsa
// u'dan v'ye ve src'den v'den u'ya giden yolun toplam a��rl���
// dist[v]'in ge�erli de�erinden daha k���k
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// olu�turulan mesafe dizisini yazd�r
	printSolution(dist, V);
}

// yukar�daki i�levi test etmek i�in s�r�c� program�
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

