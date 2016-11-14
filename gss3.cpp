#include <iostream>
#include <stdio.h>

using namespace std;

int max( int a, int b )
{
    if( a>=b )
        return a;
    else
        return b;
}

struct node
{
    int left;
    int right;
    int max;
    int sum;
};

node makenode( int b )
{
    node temp;
    temp.left = b;
    temp.right = b;
    temp.max = b;
    temp.sum = b;
    return temp;
}

node combinenode( node node1, node node2 )
{
    node temp;
    temp.left = max( node1.sum + node2.left, node1.left );
    temp.right = max( node2.right, node1.right + node2.sum );
    temp.sum = node1.sum + node2.sum;
    temp.max = max( max( node1.max, node2.max ), node1.right + node2.left );
    return temp;
}


void buildtree( int nodeind, int b, int e, int* arr, node *tree )
{
    if( b == e )
        tree[nodeind] = makenode(arr[b]);
    else
    {
        int m = (b+e)/2;
        buildtree( 2*nodeind, b, m, arr, tree );
        buildtree( 2*nodeind + 1, m+1, e, arr, tree );
        tree[nodeind] = combinenode( tree[2*nodeind], tree[2*nodeind+1] );
    }
}

node query( int nodeind, int b ,int e, int ql, int qr, int *arr, node *tree )
{
    if( b == ql && e == qr )
        return tree[nodeind];
    else
    {
        int m = (b+e)/2;
        if( ql>=b && qr<= m )
            return query( 2*nodeind, b, m, ql, qr, arr, tree );
        else if( ql>m && qr<=e )
            return query( 2*nodeind+1, m+1, e, ql, qr, arr, tree );
        else
        {
            node left = query( 2*nodeind, b, m, ql, m, arr, tree );
            node right = query( 2*nodeind + 1, m+1, e, m+1, qr, arr, tree );
            //tree[nodeind] = combinenode( left, right );
            return combinenode( left, right );
        }
    }
}

void modify( int nodeind, int b, int e, int ind, int*arr, node * tree)
{
   if( ind < b || ind > e )
        return;
    else if( b == e  )
    {
        tree[nodeind] = makenode( arr[ind] );
    }
    else
    {
        if( b != e )
        {
            int m = ( b + e )/2;
            modify( 2*nodeind, b, m, ind, arr, tree );
            modify( 2*nodeind + 1, m+1, e, ind, arr, tree );
            tree[nodeind] = combinenode( tree[2*nodeind], tree[2*nodeind+1] );
        }
    }
}



int main()
{
    int n;
    scanf("%d", &n );

    int *arr = new int[n+1];
    for( int i = 1; i <= n; i ++ )
        scanf("%d", &arr[i] );

    node *tree = new node[131072];

    buildtree( 1, 1, n, arr, tree );

    int numq;
    scanf("%d", &numq );

    while( numq-- )
    {
        int op; int ql; int qr;
        scanf("%d %d %d", &op, &ql, &qr );
        if( op == 1 )
        {
            node ans = query( 1, 1, n, ql, qr, arr, tree );
            printf("%d\n", ans.max );
            /*for( int i = 1; i <= 8; i ++ )
                cout<<tree[i].max<<" ";
            cout<<endl;*/
        }
        else if( op == 0 )
        {
            arr[ql] = qr;
            modify( 1, 1, n, ql, arr, tree);
            /*for( int i = 1; i <= 8; i ++ )
                cout<<tree[i].max<<" ";
            cout<<endl;*/
        }
    }
}



