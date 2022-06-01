#include "Graph.h"
#include "Packet.h"
#include "Router.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int main() 
{
  int node_number = 50;
  Graph G(node_number);
  G.make_connections();
  srand(time(NULL));
  int src;
  int dest;
  int packets = 500;
  
  cout << "number of packets sent: " << packets << endl;

  Packet packet = Packet("header");
  
  src = rand() % 50;
  dest = rand() % 50;
  packet.setDestination(dest);
  packet.setSource(src);
  cout << "random src: " << src << " random dest: " << dest << endl;
  bool packet_sent = G.packet_path(packet, src, dest, packets);
  cout << G.getRouter(dest).getPacketTotal() << endl;
  
  return 0;
}
