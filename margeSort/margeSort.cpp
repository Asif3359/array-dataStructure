#include <iostream>

using namespace std;
void marge ( int arr[] , int first , int mid , int last)
{
    int n1 = mid -first+1 ;
    int n2 = last - mid ;
    int arr1 [n1+1] ;
    int arr2 [n2+1] ;


    for (int i = 0 ; i< n1 ; i++)
    {
        arr1[i] = arr[first +i];
    }
    for (int j = 0 ; j< n2 ; j++)
    {
        arr2[j] = arr[mid + j+ 1];
    }

    int i = 0 ;
    int j = 0 ;
    arr1 [n1+1]=1000 ;
    arr2 [n2+1]=1000 ;

    //while (i<n1 && j<n2)
    for(int k = first ; k<last ; k++)
    {
        if(arr1[i] <= arr2[j])
        {
          arr[k] = arr1[i];
          i++;
        }
        else{
          arr[k] = arr2[j];
          j++;
        }
    }

   /* while (i<n1)
    {
        arr[k] = arr1[i];
        i++ ;
        k++ ;
    }
    while (j<n2)
    {
        arr[k] = arr2[j];
        j++ ;
        k++ ;
    } */
}


void margeSort ( int arr [] , int first , int last )
{
    int mid ;
    if(first < last)
    {
        mid = first + (last -first ) / 2 ;
        margeSort(arr , first , mid);
        margeSort(arr , mid+1 , last);

        marge(arr , first , mid , last);
    }

}

int main()
{
    cout << " Enter Your Array Size :";
    int n ;
    cin >> n ;
    int arr[n+1];
    for (int i = 0 ; i< n ; i++)
    {
        cin>> arr[i] ;
    }

    margeSort(arr , 0 , n);

    for (int i = 0 ; i< n ; i++)
    {
        cout<< arr[i]<< " " ;
    }
    return 0;
}