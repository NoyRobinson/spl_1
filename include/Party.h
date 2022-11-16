#pragma once
#include <string>

using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
//rule of 5
    Party(int id, string name, int mandates, JoinPolicy *); 
    ~Party(); //destructor
    Party(const Party& other); //copy constructor 
    Party(Party& other);//move constructor
    Party& operator=(const Party& other); //copy assignment operator
    Party& operator=(Party&& other); //move assignment operator


    //bool operator>(Party&& other); //returns true is this.mandates > other.mandates


    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
};
