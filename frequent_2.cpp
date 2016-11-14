#include <iostream>
#include <stdio.h>

using namespace std;

/*int max( int a, int b )
{
    if( a >= b )
        return a;
    else
        return b;
}*/

struct node
{
    int left; int leftele;
    int right; int rightele;
    int max; int maxele;
};


node makenode ( int b )
{
    node newnode;
    newnode.left = 1;
    newnode.leftele = b;
    newnode.right = 1;
    newnode.rightele = b;
    newnode.max = 1;
    newnode.maxele = b;
    return newnode;
}

node combinenode( node node1, node node2 )
{
    node newnode;
    if( node1.maxele == node2.maxele )
    {
        newnode.maxele = node1.maxele;
        newnode.max = node1.max + node2.max ;
    }
    else if( node1.rightele == node2.leftele )
    {
        if( node1.max >= node2.max )
        {
            if( node1.max >= (node1.right + node2.left) )
            {
                newnode.max = node1.max;
                newnode.maxele = node1.maxele;
            }
            else
            {
                newnode.max = node1.right + node2.left;
                newnode.maxele = node1.rightele ;
            }
        }
        else
        {
            if( node2.max >= (node1.right + node2.left) )
            {
                newnode.max = node2.max;
                newnode.maxele = node2.maxele;
            }
            else
            {
                newnode.max = node1.right + node2.left;
                newnode.maxele = node1.rightele;
            }
        }
    }
    else
    {
        if( node1.max>=node2.max )
        {
            newnode.max = node1.max;
            newnode.maxele = node1.maxele;
        }
        else
        {
            newnode.max = node2.max;
            newnode.maxele = node2.maxele;
        }
    }

    if( node1.leftele == node2.leftele )
    {
        newnode.leftele = node1.leftele;
        newnode.left = node1.left + node2.left;
    }
    else
    {
        newnode.left = node1.left;
        newnode.leftele = node1.leftele;
    }

    if( node1.rightele == node2.rightele )
    {
        newnode.rightele = node2.rightele;
        newnode.right = node2.right + node1.right;
    }
    else
    {
        newnode.right = node2.right;
        newnode.rightele = node2.rightele;
    }

    return newnode;
}







void buildtree( int nodeind, int b, int e, int *arr, node *tree )
{
    if( b == e )
        tree[nodeind] = makenode( arr[b] );
        //return tree[nodeind];

    else
    {
        int mid = (b+e)/2;
        buildtree( 2*nodeind, b, mid, arr, tree );
        buildtree( 2*nodeind+1, mid + 1, e, arr, tree );
        tree[nodeind] = combinenode( tree[2*nodeind], tree[2*nodeind + 1] );
        //return tree[nodeind];
    }
}

node query( int nodeind, int lq, int rq, int b, int e, int *arr, node* tree )
{
    if( lq == b && rq == e )
        return tree[nodeind];
    else
    {
        int m = (b+e)/2;
        if( lq>=b && rq <= m )
            return query( 2*nodeind, lq, rq, b, m, arr, tree );
        else if( lq > m && rq<=e )
            return query( 2*nodeind + 1, lq, rq, m+1, e, arr, tree );
        else
        {
            node node1 = query( 2*nodeind, lq, m, b, m, arr, tree );
            node node2 = query( 2*nodeind + 1, m+1, rq, m+1, e, arr, tree );
            return combinenode( node1, node2 );
        }
    }
}



int main()
{
    while( 1 )
    {
        int n;
        scanf("%d", &n );

        if(n == 0 )
            break;

        int numq;
        scanf("%d", &numq );

        int *arr = new int[n+1];
        for( int i = 1 ; i <= n; i ++ )
            scanf("%d", &arr[i] );

        node *tree = new node[524288];

        buildtree(1, 1, n, arr, tree );

        while( numq-- )
        {
            int b, e;
            scanf("%d %d", &b, &e );


            node ans = query( 1, b, e, 1, n, arr, tree );

            printf("%d\n", ans.max );
        }

        delete[] arr;
        delete[] tree;
    }
}


