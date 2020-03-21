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
			cout << "mafeesh 7aga" << endl;
		}

    int score=m; //hna2as mnu kol mara 3lshan at2aked eni msh hakhod aktr mn el max slices
    int max=0; //3lshan ashof anhi iteration ahsan
    int sum=0; //3lshan ashof anhi iteration ahsan
    int *newarr = new int[n]; //b7ot feha el index kol mara
    int *lastarr = new int[n]; //b7ot feh el index law el iteration di heya el max fe3ln
    int k=0;
    int counter=0; //khadt kam type mn el pizza
    int newcounter=0; //khadt kam type mn el pizza law el iteration max fe3ln

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
