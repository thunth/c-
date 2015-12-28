#include <iostream>
 
using namespace std;
 
void Merger( int a[], int start, int end )
{
    int mid = ( start + end ) / 2;
    int i = start;
    int j = mid + 1;
    int temp;
    while( i <= j && j <= end)
    {
        if ( a[ i ] > a[ j ] )
        {
            temp = a[ j ];
            for ( int k = j; k > i; k-- )
                a[ k ] = a[ k - 1 ];
            a[ i ] = temp;
            j++;
        }
        i++;
    }
}
 
void Merger_Sort( int a[], int start, int end )
{
    if ( end - start < 1 )
        return;
    int mid = ( start + end ) / 2;
    Merger_Sort( a, start, mid );
    Merger_Sort( a, mid + 1, end );
    Merger( a, start, end );
}
 
void show( int a[], int n )
{
    for ( int i = 0; i < n; i++ )
        cout << a[ i ] << ' ';
}
int main()
{
    int a[] = { 0, 2, 2, 2, 3, 4, 5, 7, 8, 5, 3, 1, 3, 5, 6 };
    int n = sizeof ( a ) / sizeof ( int );
    cout << n << endl;
    Merger_Sort( a, 0, n - 1 );
    show( a, n );
 
    //system("pause");
    return 0;
}