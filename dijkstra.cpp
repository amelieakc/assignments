// Assignment 12 Amelie Cameron
// This assignment implements Dijkstra's algorithm to find the shortest path (cheapest cost) from 
// vertex 0 (SFO) to all other vertices (airports: (1)LAX, (2)LAS, (3)PHX, (4)DEN, (5)JFK)

#include <stdbool.h>
#include <cstdio>
#include <deque>
#include <iostream>
#include <climits>
using namespace std;
#ifndef NULL
#define NULL (0)
#endif
#define MAXV 1000
#define MAXINT INT_MAX

struct edgenode 
{
  int y;
  int weight;
  struct edgenode *next;
};

struct graph 
{
  edgenode *edges[MAXV+1];
  int degree[MAXV+1];
  int nvertices;
  int nedges;
  bool directed;
  bool discovered[MAXV+1];
  bool processed[MAXV+1];
  int parent[MAXV+1];
  bool finished;
  int verticesExhausted;
};

void dijkstra(graph *g, int start) 
{
  edgenode *p;
  bool intree[MAXV + 1];
  int distance[MAXV + 1];
  int v;
  int w;
  int weight;
  int dist; // final distance                                                                            

  for(int i = 0; i < g->nvertices; ++i) 
    {
      intree[i] = false;
      distance[i] = MAXINT;
      g->parent[i] = -1;
    }

  v = start;
  distance[start] = 0;
  while(intree[v] == false) 
    {
      intree[v] = true;
      p = g->edges[v];
      while(p != NULL) 
	{
	  w = p->y;
	  weight = p->weight;
	  if(distance[w] > distance[v] + weight) 
	    {
	      distance[w] = distance[v] + weight;
	      g->parent[w] = v;
	    }
	  p = p->next;
	}
      v = 0;
      dist = MAXINT;
      
      for(int i = 0; i < g->nvertices; ++i) 
	{
	  if((intree[i] == false) && (dist > distance[i])) 
	    {
	      v = i;
	      dist = distance[i];
	      cout << "Total Flight Cost from SFO to Airport # " << i << " : $" << dist << endl;
	    }
	}
    }
}

void initialize_graph(graph *g, bool directed) 
{
  int i;
  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for(int i = 0; i <= MAXV; ++i) 
    {
      g->degree[i] = 0;
      g->edges[i] = NULL;
      g->discovered[i] = g->processed[i] = false;
     }
}

void insert_edge(graph *g, int x, int y, int weight, bool directed) {
  edgenode *p;
  p = new edgenode();
  p->weight = weight;
  p->y = y;
  p->next = g->edges[x];
  g->edges[x] = p;
  g->degree[x]++;

  if(directed == false)
    insert_edge(g, y, x, weight, true);
  else
    g->nedges++;
}

void read_graph(graph *g, bool directed) 
{
  int i;
  int m;
  int x, y; //source, dest                                                                               
  float weight;
  initialize_graph(g, directed);
  scanf("%d %d", &(g->nvertices), &m);
  for(i = 0; i < m; ++i) 
    {
      scanf("%d %d %f", &x, &y, &weight);
      insert_edge(g, x, y, weight, directed); 
    }
}

void print_graph(graph *g) 
{
  int i;
  edgenode *p;
  cout << "Flight Graph: " << endl;
  cout << "Current Vertex: Adjacent Vertices" << endl;
  for(i = 0; i < g->nvertices; ++i) 
    {
      printf("%d: ", i);
      p = g->edges[i];
      while (p != NULL)
	{
	  printf("%d ", p->y);
	  p = p->next;
	}
      printf("\n");
    }
}

int main() 
{
  graph *g = new graph();
  initialize_graph(g, false);
  read_graph(g, false);
  print_graph(g);
  cout << '\n';
  dijkstra(g, 0);
  return 0;
}

