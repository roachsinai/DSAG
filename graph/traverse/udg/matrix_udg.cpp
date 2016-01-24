/**
 * 邻接矩阵表示的无向图(adjacent matrix  undirected graph)
 *
 * @author roachsinai
 * @data 2016.01.23
 */

#include "iomanip"
#include "iostream"
#include "vector"

using namespace std;

#define MAX 100

class MatrixUDG
{
public:
    MatrixUDG();  // create matrix by input data
    MatrixUDG(char vexs[], int vlen, char edges[][2], int elen);  // create matrix by existing data
    ~MatrixUDG();
    void DFS();  // depth-first search
    void BFS();  // breadth-first search
    void Print();  // show the adjacent matrix
private:    
    char ReadChar();  // return the input letter which represent a vertex
    int GetPosition(char ch);  // return mVexs index of dege's vertex
    int FirstAdjVertex(int v);  // return mVexs index of v's first adjacent vertex
    int NextAdjVertex(int v, int w);  // w is an adjacent vertex of v
                                      // return v's another adjacent vertex next w 
    void DFS(int i, int *visited);  //  recursive implementation

    char mVexs[MAX];  // set of vertice
    int mVexNum;  // vertex count
    int mEdgNum;  // number of edges
    int mMatrix[MAX][MAX];  // adjacent matrix
};

/**
 * create matrix by input data
 */
MatrixUDG::MatrixUDG()
{
    char c1, c2;
    int i, j, p1, p2;

    cout << "input vertice count: ";
    cin >> mVexNum;
    cout << "input edges count: " ;
    cin >> mEdgNum;
    if (mVexNum < 1 || mEdgNum < 1 || (mEdgNum > (mVexNum * (mVexNum - 1))))
    {
        cout << "input error: invalid parameters!" << endl;
        return ;
    }

    // initialize vertices
    for (i = 0; i < mVexNum; ++i)
    {
        cout << "vertex(" << i << "): ";
        mVexs[i] = ReadChar();
    }

    // initialize adjacent matrix
    for (i = 0; i < mVexNum; ++i)
        for (j = 0; j < mVexNum; ++j)
            mMatrix[i][j] = 0;

    // initialize edges
    for (i = 0; i < mEdgNum; ++i)
    {
        // input pair of vertices that are adjacent in a graph
        cout << "edge(" << i << "): ";
        c1 = ReadChar();
        c2 = ReadChar();

        p1 = GetPosition(c1);
        p2 = GetPosition(c2);
        if (p1 == -1 || p2 == -1)
        {
            cout << "input error: invalid edge!" << endl;
            return ;
        }

        mMatrix[p1][p2] = 1;
        mMatrix[p2][p1] = 1;
    }
}

/**
 * create matrix by existing data
 *
 * vexs: array of vertices
 * vlen: length of vexs
 * edges: array of edges
 * elen: length of edges
 */
MatrixUDG::MatrixUDG(char vexs[], int vlen, char edges[][2], int elen)
{
    int i, j, p1, p2;

    // initialize count of vertices and edges
    mVexNum = vlen;
    mEdgNum = elen;

    // initialize mVexs
    for (i = 0; i < mVexNum; ++i)
        mVexs[i] = vexs[i];

    // initialize adjacent matrix
    for (i = 0; i < mVexNum; ++i)
        for (j = 0; j < mVexNum; ++j)
            mMatrix[i][j] = 0;

    // imitialize edges
    for (i = 0; i < mEdgNum; ++i)
    {
        p1 = GetPosition(edges[i][0]);
        p2 = GetPosition(edges[i][1]);

        mMatrix[p1][p2] = 1;
        mMatrix[p2][p1] = 1;
    }
}

/**
 * destructor
 */
MatrixUDG::~MatrixUDG()
{}

/**
 * return mVexs index of @ch
 * same as row or column of mMatrix
 *
 * @ch
 */
int MatrixUDG::GetPosition(char ch)
{
    int i;
    for (i = 0; i < mVexNum; ++i)
        if (mVexs[i] == ch)
            return i;
    return -1;
}

/**
 * read a char
 */
char MatrixUDG::ReadChar()
{
    char ch;

    do{
        cin >> ch;
    }while(!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')));

    return ch;
}

/**
 * return mVexs index of v's first adjacent vertex
 */
int MatrixUDG::FirstAdjVertex(int v)
{
    int i;

    if (v < 0 || v > (mVexNum - 1))
        return -1;

    for (i = 0; i < mVexNum; i++)
        if (mMatrix[v][i] == 1)
            return i;

    return -1;
}

/**
 * 返回顶点v相对于w（也是v的一个邻接顶点）的下一个邻接顶点的索引，失败则返回-1
 */
int MatrixUDG::NextAdjVertex(int v, int w)
{
    int i;

    if (v < 0 || v > (mVexNum - 1) || w < 0 || w > (mVexNum - 1))
        return -1;

    for (i = w + 1; i < mVexNum; ++i)
        if (mMatrix[v][i] == 1)
            return i;

    return -1;
}

/**
 * depth-first search recursive implementation
 */
void MatrixUDG::DFS(int i, int *visited)
{
    int w;

    visited[i] = 1;
    cout << mVexs[i] << " ";
    // iterate all adjacent vertices of i, do DFS
    // if all adjacent vertices of i has been searched, w = -1
    for (w = FirstAdjVertex(i); w >= 0; w = NextAdjVertex(i, w))
        if (!visited[w])
            DFS(w, visited);
}

/**
 * depth-first traverse graph
 */
void MatrixUDG::DFS()
{
    int i;
    int visited[MAX];

    // all vertices unvisited
    for (i = 0; i < mVexNum; ++i)
        visited[i] = 0;

    cout << "DFS: ";
    for (i = 0; i < mVexNum; ++i)
        if (!visited[i])
            DFS(i, visited);
    cout << endl;
}

/**
 * breadth-first search
 */
void MatrixUDG::BFS()
{
    int head = 0;
    int rear = 0;
    int queue[MAX];
    int visited[MAX];
    int i, j, k;

    for (i = 0; i < mVexNum; ++i)
        visited[i] = 0;

    cout << "BFS: ";
    for (i = 0; i < mVexNum; ++i)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            cout << mVexs[i] << " ";
            queue[rear++] = i; // from this vertex start BFS
        }
        while (head != rear)
        {
            j = queue[head++];
            for (k = FirstAdjVertex(j); k >= 0; k = NextAdjVertex(j, k))
                if (!visited[k])
                {
                    visited[k] = 1;
                    cout << mVexs[k] << " ";
                    queue[rear++] = k;
                }
        }
    }
    cout << endl;
}

/**
 * show the adjacent matrix
 */
void MatrixUDG::Print()
{
    int i, j;

    cout << "Adjacent Matrix Graph:" << endl;
    for (i = 0; i < mVexNum; ++i)
    {
        for (j = 0; j < mVexNum; ++j)
            cout << mMatrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'C'}, 
        {'A', 'D'}, 
        {'A', 'F'}, 
        {'B', 'C'}, 
        {'C', 'D'}, 
        {'E', 'G'}, 
        {'F', 'G'}};
    int vlen = sizeof(vexs) / sizeof(vexs[0]);
    int elen = sizeof(edges) / sizeof(edges[0]);
    MatrixUDG *pG;

    pG = new MatrixUDG(vexs, vlen, edges, elen);

    pG->Print();
    pG->DFS();
    pG->BFS();

    return 0;
}