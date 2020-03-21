#include <iostream>
#include <fstream>

using namespace std;

int main()
{
		int m, n;
		ofstream outfile;
		outfile.open("e_also_big.out");

		ifstream infile;
		infile.open("e_also_big.in");
		infile >> m;
		infile >> n;

		int *arr = new int [n];
		for (int i = 0; i < n; i++)
		{
			infile >> arr[i];
			//cout << arr[i] << endl << endl;
		}


		//cout << "m: " << m << endl << "n :" << n << endl << endl;
		if (infile.fail())
		{
			cout << "there is no such file" << endl;
		}

    int score=m; //this variable to make sure that i will not take more than max slices
    int max=0; 
    int sum=0; 
    int *newarr = new int[n]; //to put indices in it
    int *lastarr = new int[n]; //the indices of best iteraton 
    int k=0;
    int counter=0; //how many types of pizza i took
    int newcounter=0; //how many types of pizza i took in best iteration

    for(int i=n-1;i>=0;i--) //iterations
        {
            score=m;
            sum=0;
            k=0;
            counter=0;

            for(int j=i;j>=0;j--)
            {

                if(score-arr[j]>=0)
                {
                    counter++;
                    score-=arr[j];
                    newarr[k]=j;
                    k++;
                    sum+=arr[j];
                }


            }

            if (sum>max)
            {
                max=sum;
                newcounter=counter;
                for(int w=0 ; w<newcounter ; w++)
                    lastarr[w]=newarr[w];
            }



        }


        outfile<<newcounter<<endl;

        for(int i=newcounter-1;i>=0;i--)
            outfile<<lastarr[i]<<" ";


    return 0;
}
