#ifndef BASICPATHSEARCHES_CPP
#define BASICPATHSEARCHES_CPP

#include "BasicPathSearches.h"

template<class VertexType>
BasicPathSearches<VertexType>::BasicPathSearches()
{
    graph = NULL;
    startVertex = endVertex = 0;
}

template<class VertexType>
BasicPathSearches<VertexType>::BasicPathSearches(GraphType<VertexType> newGraph, VertexType start, VertexType finish)
{
    graph = newGraph;
    startVertex = start;
    endVertex = finish;
}

template<class VertexType>
BasicPathSearches<VertexType>::~BasicPathSearches()
{
    startVertex = endVertex = 0;
    graph = NULL;
}

template<class VertexType>
bool BasicPathSearches<VertexType>::IsEmpty() const
{
    return (startVertex == endVertex);
}

template<class VertexType>
void BasicPathSearches<VertexType>::DepthFirstSearch()
{

    Stack<VertexType> myStack;
    Queue<VertexType> myQueue;

    bool found = false;
    VertexType vertex;
    VertexType item;

    graph.ClearMarks;
    myStack.Push(startVertex);

    do
    {
        myStack.Pop(vertex);
        if(vertex == endVertex)
        {
            cout << vertex;
            found = true;
        }
        else
        {
            if(!graph.IsMarked(vertex))
            {
                graph.MarkVertex(vertex);
                cout << vertex;
                graph.GetToVertices(vertex, myQueue);

                while(!myQueue.IsEmpty())
                {
                    myQueue.Dequeue(item);
                    if(!graph.IsMarked(item))
                        myStack.Push(item);
                }
            }
        }
    }while( !myStack.IsEmpty() && !found);

    if(!found)
        cout << "Path not found. " << endl;
}

template<class VertexType>
void BasicPathSearches<VertexType>::BreadthFirstSearch()
{
    Queue<VertexType> myQueue;
    Queue<VertexType> vertexQ;

    bool found = false;
    VertexType vertex;
    VertexType item;

    graph.ClearMarks;
    myQueue.Enqueue(startVertex);
    do
    {
        myQueue.Dequeue(vertex);
        if(vertex == endVertex)
        {
            cout << vertex;
            found = true;
        }
        else
        {
            if( !graph.IsMarked(vertex))
            {
                graph.MarkVertex(vertex);
                cout << vertex;
                graph.GetToVertices(vertex, vertexQ);

                while(!vertexQ.IsEmpty())
                {
                    vertexQ.Dequeue(item);
                    if( !graph.IsMarked(item))
                        myQueue.Enqueue(item);
                }
            }
        }
    }while( !myQueue.IsEmpty() && !found);

    if(!found)
    cout << "Path not found. " << endl;
}

#endif // BASICPATHSEARCHES_CPP
