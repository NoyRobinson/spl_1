#include "Simulation.h"
using namespace std;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    // TODO: implement this method
}

bool Simulation::shouldTerminate() const
{
    vector<vector<int>> coalitionParties = getPartiesByCoalitions(); // checking for 61 coalition or more
    for(vector<int> singleCoalition: coalitionParties){
        int coalitionSum = 0;
        for(int singleParty: singleCoalition){
            coalitionSum = coalitionSum + mGraph.getMandates(singleParty);
        }
        if(coalitionSum >= 61){
            return true;
        }
    }
    if (mGraph.getNumVertices() == mAgents.size()){ // check if all parties are in coalition
        return true;
    }
    return false;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}
