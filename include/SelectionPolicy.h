#pragma once

class SelectionPolicy { 
public:
    virtual int select() const;
};

class MandatesSelectionPolicy: public SelectionPolicy{ 
public:
    int select() const;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
public:
    int select() const;
};

