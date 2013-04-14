#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool passFail(std::vector< std::vector<int> > &yardGrid, int height, int width);
int main(){

	int googleSamples=0;
	int height, width = 0;
	std::vector< std::vector<int> > yardGrid;
	std::vector<int> staging;
	int temp;
	bool testCase;

    ifstream googleInput;
    ofstream googleOutput;

    googleInput.open("C-large-2.in");
    googleOutput.open("small.out");

	cout << "#of googleSamples :";
	cin >> googleSamples;
	cout << endl;

	for (int i = 1; i <= googleSamples; ++i){

		cout << "height and width : ";
		cin >> height >> width;
		cout << endl;

		for (int o = 0; o < height; ++o){
			for (int p = 0; p < width; ++p){
				cin >> temp;
				staging.push_back(temp);
			}

			yardGrid.push_back(staging);
		}


		testCase = passFail(yardGrid, height, width);

		if(testCase){
			cout << "Case #" << i << ": YES" << endl;
		}else{
			cout << "Case #" << i << ": No" << endl;
		}
	}

	for (int i = 0; i < height; ++i){
		for (int c = 0; c < width; ++c)
		{
			cout << yardGrid[i][c];
		}
        cout << endl;
	}


    return 0;
}

bool passFail(std::vector< std::vector<int> > &yardGrid, int const height, int &width){
	bool check=true;
    vector<int> row_max;
    vector<int> col_max;
    int sum=0;
    int maxSum=0;
    int test=0;

    for(int i=0; i<height; ++i){
        for(int j=0;j<width; ++j){
            sum+=yardGrid[i][j];
        }
        if(sum>maxSum){
            maxSum=sum;
            row_max.clear();
            for(int j=0; j<width; ++j){
                row_max.push_back(yardGrid[i][j]);
            }
        }
    }

    for(int i=0; i<width; ++i){
        for(int j=0;j<height; ++j){
            sum+=yardGrid[i][j];
        }
        if(sum>maxSum){
            maxSum=sum;
            row_max.clear();
            for(int j=0; j<height; ++j){
                col_max.push_back(yardGrid[i][j]);
            }
        }
    }


    for(int i=0;i<height;++i){
        for(int j=0;j<width;++j){
            test=yardGrid[i][j];
            if(test!=row_max[i] && test!= col_max[j]){
                return false;
            }
        }
    }



	return check;
}