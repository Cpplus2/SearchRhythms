#ifndef BASICPATHSEARCHES_H
#define BASICPATHSEARCHES_H

#include "Stack.h"
#include "Queue.h"
#include "GraphType.h"

template<class VertexType>
class BasicPathSearches
{
    private:
        GraphType<VertexType> graph;
        VertexType startVertex;
        VertexType endVertex;

    public:
        BasicPathSearches();
        BasicPathSearches(GraphType<VertexType>, VertexType, VertexType);
        ~BasicPathSearches();
        bool IsEmpty() const;
        void DepthFirstSearch();
        void BreadthFirstSearch();
};

#endif // BASICPATHSEARCHES_H
